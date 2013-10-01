<?php

class SubmitNewCommentController implements IController {

	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		
		if ($userId) {
			$form = new Form();
			$commentBody = $form->post('commentBody');
			$commentTags = $form->post('commentTags');
			$currentPostId = $form->post('currentPost');
			$parentCommentId = $form->post('parentComment');
			
			$userInputScrubber = new UserInputScrubber();
			
			$commentBody = $userInputScrubber->scrubString($commentBody);
			if ($commentBody == "") {
				// TODO: empty comment, what do
				return;
			}
			
			$stringUrlLinker = new StringURLLinker();
			$commentBody = $stringUrlLinker->replaceUrlsWithLinks($commentBody);
			
			$commentTags = $userInputScrubber->scrubString($commentTags);
			
			$tagDecoder = new TagDecoder();
			$tagsFound = $tagDecoder->getTagIds($commentTags);
			
			if (count($tagsFound) <= 0) {
				// TODO: no tags defined, no where to post this
				return;
			}
			
			$parentCommentId = $userInputScrubber->scrubString($parentCommentId);
			
			$sql = sprintf("INSERT INTO comments (content, timestamp, poster_user_id, parent_post_id) VALUES ('%s', NOW(), '%s', '%s')", $commentBody, $userId, $parentCommentId);
			
			$database = new Database();
			$commentId = $database->write($sql);
			
			if ($commentId == 0) {
				// TODO:something went wrong with saving the post, do something here
				return;
			}
			$associationValues = array();
			$sql = "INSERT INTO comment_topic_associations (comment_id, topic_id) VALUES ";
			foreach ($tagsFound as $topicId) {
				$associationValues[] = "(" . $commentId . "," . $topicId . ")";
			}
			$sql .= implode(',', $associationValues);
			
			$database->write($sql);
			
			$header = new Header();
			$header->redirect("/?a=post&id=".$currentPostId);
		} else {
			// TODO: not logged in
		}
	}
}