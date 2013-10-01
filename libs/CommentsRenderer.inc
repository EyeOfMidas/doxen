<?php

class CommentsRenderer {

	public function getTopLevelComments($postId) {
		$sql = sprintf("SELECT * 
			FROM comments c 
			JOIN users u ON c.poster_user_id = u.user_id
			WHERE c.parent_post_id = '%s'", $postId);
		$database = new Database();
		$comments = $database->query($sql);
		
		$view = new View();
		$viewData = array('comments' => $comments);
		return $view->render('commentsView.inc', $viewData);
	}
}