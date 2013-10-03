<?php
class CommentRepliesController implements IController {
	public function execute() {
		$form = new Form();
		$parentCommentId = $form->getCleanDefaulted('id', 0);
		$commentsRenderer = new CommentsRenderer();
		return $commentsRenderer->getReplies($parentCommentId);
	}
}