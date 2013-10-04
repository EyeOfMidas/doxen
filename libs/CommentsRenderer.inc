<?php

class CommentsRenderer {

	const PAGE_SIZE = 100;
	
	private $database;
	
	public function __construct() {
		$this->database = new Database();
		
	}

	public function getComments($postId, $topicId, $parentCommentId, $page = 0) {
		$session = new Session();
		$userId = $session->getValue("logged_in");
		
		$sql = sprintf("SELECT c.comment_id, content, timestamp, poster_user_id, parent_post_id, parent_comment_id, c.url_name as comment_url_name, u.display_name as user_display_name, t.display_name as topic_display_name, t.url_name as topic_url_name
			FROM comments c
			JOIN users u ON c.poster_user_id = u.user_id
			JOIN comment_topic_associations a ON c.comment_id = a.comment_id
			JOIN topics t ON a.topic_id = t.topic_id
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
		if($userId) {
			$viewData['userId'] = $userId;
		}
		return $view->render('commentsView.inc', $viewData);
	}
	
	public function getReplies($parentCommentId, $page = 0) {
		$session = new Session();
		$userId = $session->getValue("logged_in");
		
		$sql = sprintf("SELECT c.comment_id, content, timestamp, poster_user_id, parent_post_id, parent_comment_id, c.url_name as comment_url_name, u.display_name as user_display_name, t.display_name as topic_display_name, t.url_name as topic_url_name, t.topic_id
			FROM comments c
			JOIN users u ON c.poster_user_id = u.user_id
			JOIN comment_topic_associations a ON c.comment_id = a.comment_id
			JOIN topics t ON a.topic_id = t.topic_id
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
		if($userId) {
			$viewData['userId'] = $userId;
		}
		return $view->render('commentsView.inc', $viewData);
	}
	
	public function getTopLevelComments($postId, $topicId, $page = 0) {
		return $this->getComments($postId, $topicId, 0, $page);
	}
}