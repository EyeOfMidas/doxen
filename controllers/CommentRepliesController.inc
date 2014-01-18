<?php
class CommentRepliesController implements IController {
	public function execute() {
		
		//TODO: for logged in user, mark these comments as viewed with timestamp
		$form = new Form();
		$parentCommentId = $form->getCleanDefaulted('id', 0);
		$commentsRenderer = new CommentsRenderer();
		return $commentsRenderer->getReplies($parentCommentId);
	}
}