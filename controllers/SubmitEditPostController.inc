<?php
class SubmitEditPostController implements IController {

	public function execute() {
		$user = new User();
		$user->populate();
		if ($user->getId()) {
			$form = new Form();
			$postId = $form->getCleanDefaulted('id', 0);
			$topicId = $form->getCleanDefaulted('t', 0); 
			$postContent = $form->postCleanDefaulted('postContent', '');
			$userInputScrubber = new UserInputScrubber();
			
			$postContent = $userInputScrubber->scrubString($postContent);
			$sql = sprintf("UPDATE posts SET content = '%s' WHERE post_id = '%s' AND poster_user_id = '%s'",
				$postContent,
				$postId,
				$user->getId()
			);
			$database = new Database();
			$database->query($sql);
			
			$sql = "INSERT INTO post_last_updated (post_id, last_updated) VALUES (" . $postId . ", NOW())";
			$database->write($sql);
			
			$header = new Header();
			$header->redirect("?a=post&id=" .$postId. "&t=" . $topicId);
		}
	}
}