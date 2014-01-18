<?php
class SubmitNewCommentController implements IController {
	private $user;
	private $form;
	private $userInputScrubber;
	private $stringURLLinker;
	private $database;
	private $header;
	private $notificationScraper;

	public function __construct() {
		$this->user = new User();
		$this->form = new Form();
		$this->userInputScrubber = new UserInputScrubber();
		$this->stringUrlLinker = new StringURLLinker();
		$this->database = new Database();
		$this->header = new Header();
		$this->notificationScraper = new NotificationScraper();
	}

	public function execute() {
		$this->user->populate();
		$userId = $this->user->getId();
		
		if ($userId) {
			$commentBody = $this->form->postCleanDefaulted('commentBody', '');
			$currentPostId = $this->form->getCleanDefaulted('id', 0);
			$currentTopicId = $this->form->getCleanDefaulted('t', 0);
			$parentCommentId = $this->form->postCleanDefaulted('parentComment', 0);
			$file = $this->form->file('attachment1');
			
			$commentBody = $this->userInputScrubber->scrubString($commentBody);
			if ($commentBody == "") {
				// ERROR: empty comment, what do
				return;
			}
			
			$commentBody = $this->stringUrlLinker->replaceUrlsWithLinks($commentBody);
			
			if (empty($currentTopicId)) {
				//ERROR: somehow they're posting in an undefined topic. No.
				return;
			}
			
			$parentCommentId = $this->userInputScrubber->scrubString($parentCommentId);
			
			$sql = sprintf("INSERT INTO comments (content, timestamp) 
				VALUES ('%s', NOW())", $commentBody);
			$commentId = $this->database->write($sql);
			
			if ($commentId == 0) {
				//ERROR: something went wrong with saving the post, do something here
				return;
			}
			
			$fileUploadHandler = new FileUploadHandler();
			$fileUploadHandler->saveFileToComment($file, $commentId, $userId);
			
			$sql = sprintf("INSERT INTO comment_comment_associations (comment_id, parent_comment_id)
				VALUES ('%s', '%s')", $commentId, $parentCommentId);
			$this->database->write($sql);
			
			$sql = sprintf("INSERT INTO comment_user_associations (comment_id, user_id)
				VALUES ('%s', '%s')", $commentId, $userId);
			$this->database->write($sql);
			
			$sql = sprintf("INSERT INTO comment_post_associations (comment_id, post_id)
				VALUES ('%s', '%s')", $commentId, $currentPostId);
			$this->database->write($sql);
			
			$userTagData = $this->notificationScraper->getUserTagDataFromString($commentBody);
			foreach ($userTagData as $userId => $userTagString) {
				$sql = sprintf("INSERT INTO user_tags (user_id) VALUES ('%s')", $userId);
				$userTagId = $this->database->write($sql);
				$sql = sprintf("INSERT INTO post_tags (post_id, tag_id) VALUES ('%s', '%s')", $currentPostId, $userTagId);
				$this->database->write($sql);
			}
			
			$sql = "INSERT INTO post_last_updated (post_id, last_updated) VALUES (" . $currentPostId . ", NOW())";
			$this->database->write($sql);
			
			if($parentCommentId == 0) {
				//send notification to the post author
				$postModel = new PostModel();
				$parentPostData = $postModel->getPost($currentPostId);
				$sql = sprintf("INSERT INTO user_tags (user_id) VALUES ('%s')", $parentPostData['user_id']);
				$notificationId = $this->database->write($sql);
				$sql = sprintf("INSERT INTO post_tags (tag_id, post_id) VALUES ('%s', '%s')", $notificationId, $currentPostId);
				$this->database->write($sql);
			} else {
				//send notification to the parent comment author
				$commentModel = new CommentModel();
				$parentCommentData = $commentModel->getComment($parentCommentId);
				$sql = sprintf("INSERT INTO user_tags (user_id) VALUES ('%s')", $parentCommentData['commenter_user_id']);
				$notificationId = $this->database->write($sql);
				$sql = sprintf("INSERT INTO post_tags (tag_id, post_id) VALUES ('%s', '%s')", $notificationId, $currentPostId);
				$this->database->write($sql);
			}
			
			$this->header->redirect("/?a=post&id=" . $currentPostId . "&t=" . $currentTopicId);
		} else {
			$this->header->redirect("/");
		}
	}
}