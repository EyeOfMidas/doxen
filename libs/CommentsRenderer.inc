<?php

class CommentsRenderer {

	const PAGE_SIZE = 100;
	
	private $database;
	
	public function __construct() {
		$this->database = new Database();
		
	}

	public function getComments($postId, $topicId, $parentCommentId, $page = 0) {
		$sql = sprintf("SELECT *
			FROM comments c
			JOIN users u ON c.poster_user_id = u.user_id
			JOIN comment_topic_associations a ON c.comment_id = a.comment_id
			WHERE c.parent_post_id = '%s'
			AND a.topic_id = '%s'
			AND c.parent_comment_id = '%s'
			ORDER BY timestamp DESC LIMIT %s, %s", $postId, $topicId, $parentCommentId, $page * CommentsRenderer::PAGE_SIZE, CommentsRenderer::PAGE_SIZE);
		$comments = $this->database->query($sql);
		
		foreach($comments as $index => $commentData) {
			$sql = sprintf("SELECT count(*) as replies FROM comments WHERE parent_comment_id = '%s'",$commentData['comment_id']);
			$countData = $this->database->query($sql);
			$comments[$index]['replies'] = $countData[0]['replies'];
		}
		
		$view = new View();
		$viewData = array(
			'comments' => $comments
		);
		return $view->render('commentsView.inc', $viewData);
	}
	
	public function getReplies($parentCommentId, $page = 0) {
		$sql = sprintf("SELECT *
			FROM comments c
			JOIN users u ON c.poster_user_id = u.user_id
			WHERE c.parent_comment_id = '%s'
			ORDER BY timestamp DESC LIMIT %s, %s", $parentCommentId, $page * CommentsRenderer::PAGE_SIZE, CommentsRenderer::PAGE_SIZE);
		
		$comments = $this->database->query($sql);
		
		foreach($comments as $index => $commentData) {
			$sql = sprintf("SELECT count(*) as replies FROM comments WHERE parent_comment_id = '%s'",$commentData['comment_id']);
			$countData = $this->database->query($sql);
			$comments[$index]['replies'] = $countData[0]['replies'];
		}
		
		$view = new View();
		$viewData = array(
			'comments' => $comments
		);
		return $view->render('commentsView.inc', $viewData);
	}
	
	public function getTopLevelComments($postId, $topicId, $page = 0) {
		return $this->getComments($postId, $topicId, 0, $page);
	}
}