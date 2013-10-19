<?php
class SubmitEditCommentController implements IController {

	public function execute() {
		$form = new Form();
		$commentId = $form->getCleanDefaulted('id', 0);
		$content = $form->postCleanDefaulted('commentBody', "");
		if ($content == "") {
			// attempt to delete?
			return;
		}
		
		if ($commentId == 0) {
			// no comment id specified, but this is an edit. wha?
			return;
		}
		
		$sql = sprintf("SELECT * 
			FROM comments c
			JOIN comment_user_associations cu ON c.comment_id = cu.comment_id
			JOIN comment_post_associations cp ON c.comment_id = cp.comment_id
			JOIN post_topic_associations pt ON cp.post_id = pt.post_id
			WHERE c.comment_id = '%s'", $commentId);
		$database = new Database();
		$commentData = $database->query($sql);
		$commentData = $commentData[0];
		
		$user = new User();
		$user->populate();
		$userId = $user->getId();
		
		if ($userId == $commentData['user_id']) {
			$sql = sprintf("UPDATE comments SET content = '%s', is_edited = 1 WHERE comment_id = '%s'", $content, $commentId);
			$database->query($sql);
		}
		$header = new Header();
		$header->redirect("/?a=post&id=" . $commentData['post_id'] . "&t=" . $commentData['topic_id']);
	}
}