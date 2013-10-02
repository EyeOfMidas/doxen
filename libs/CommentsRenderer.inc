<?php

class CommentsRenderer {

	const PAGE_SIZE = 100;

	public function getTopLevelComments($postId, $topicId, $page = 0) {
		$sql = sprintf("SELECT * 
			FROM comments c 
			JOIN users u ON c.poster_user_id = u.user_id
			JOIN comment_topic_associations a ON c.comment_id = a.comment_id
			WHERE c.parent_post_id = '%s' 
			AND a.topic_id = '%s'
			ORDER BY timestamp DESC LIMIT %s, %s", $postId, $topicId, $page * CommentsRenderer::PAGE_SIZE, CommentsRenderer::PAGE_SIZE);
		$database = new Database();
		$comments = $database->query($sql);
		
		$view = new View();
		$viewData = array(
			'comments' => $comments
		);
		return $view->render('commentsView.inc', $viewData);
	}
}