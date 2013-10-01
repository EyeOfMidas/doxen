<?php

class CommentsRenderer {

	const PAGE_SIZE = 100;

	public function getTopLevelComments($postId, $page = 0) {
		$sql = sprintf("SELECT * 
			FROM comments c 
			JOIN users u ON c.poster_user_id = u.user_id
			WHERE c.parent_post_id = '%s'ORDER BY timestamp DESC LIMIT %s, %s", $postId, $page * CommentsRenderer::PAGE_SIZE, CommentsRenderer::PAGE_SIZE);
		$database = new Database();
		$comments = $database->query($sql);
		
		$view = new View();
		$viewData = array(
			'comments' => $comments
		);
		return $view->render('commentsView.inc', $viewData);
	}
}