<?php
class CommentsRenderer {
	const PAGE_SIZE = 100;
	private $database;

	public function __construct() {
		$this->database = new Database();
	}

	public function getComments($postId, $parentCommentId, $page = 0) {
		$user = new User();
		$notificationScraper = new NotificationScraper();
		$user->populate();
		$userId = $user->getId();
		
		$sql = sprintf("SELECT c.comment_id, c.content, c.timestamp, c.url_name, c.is_edited, ca.parent_comment_id, cp.post_id, pt.topic_id, u.user_id, u.username, u.display_name
			FROM comments c
			JOIN comment_comment_associations ca ON c.comment_id = ca.comment_id
			JOIN comment_post_associations cp ON c.comment_id = cp.comment_id
			JOIN comment_user_associations cu ON c.comment_id = cu.comment_id
			JOIN post_topic_associations pt ON cp.post_id = pt.post_id
			JOIN users u ON u.user_id = cu.user_id
			WHERE ca.parent_comment_id = '%s'
			AND cp.post_id = '%s'
			ORDER BY timestamp DESC LIMIT %s, %s", $parentCommentId, $postId, $page * CommentsRenderer::PAGE_SIZE, CommentsRenderer::PAGE_SIZE);
		
		$comments = $this->database->query($sql);
		foreach ($comments as $index => $commentData) {
			$sql = sprintf("SELECT count(*) as replies FROM comment_comment_associations WHERE parent_comment_id = '%s'", $commentData['comment_id']);
			$countData = $this->database->query($sql);
			$comments[$index]['replies'] = $countData[0]['replies'];
			$comments[$index]['content'] = $notificationScraper->replaceNotificationsWithLinks($commentData['content']);
		}
		
		$view = new View();
		$viewData = array(
			'comments' => $comments,
			'user' => $user
		);
		if ($userId) {
			$viewData['userId'] = $userId;
		}
		return $view->render('commentsView.inc', $viewData);
	}

	public function getReplies($parentCommentId, $page = 0) {
		$user = new User();
		$notificationScraper = new NotificationScraper();
		$user->populate();
		$userId = $user->getId();
		
		$sql = sprintf("SELECT c.comment_id, c.content, c.timestamp, c.url_name, c.is_edited, ca.parent_comment_id, cp.post_id, pt.topic_id, u.user_id, u.username, u.display_name
			FROM comments c
			JOIN comment_comment_associations ca ON c.comment_id = ca.comment_id
			JOIN comment_post_associations cp ON c.comment_id = cp.comment_id
			JOIN comment_user_associations cu ON c.comment_id = cu.comment_id
			JOIN post_topic_associations pt ON cp.post_id = pt.post_id
			JOIN users u ON u.user_id = cu.user_id
			WHERE ca.parent_comment_id = '%s'
			ORDER BY timestamp DESC LIMIT %s, %s", $parentCommentId, $page * CommentsRenderer::PAGE_SIZE, CommentsRenderer::PAGE_SIZE);
		
		$comments = $this->database->query($sql);
		
		foreach ($comments as $index => $commentData) {
			$sql = sprintf("SELECT count(*) as replies FROM comment_comment_associations WHERE parent_comment_id = '%s'", $commentData['comment_id']);
			$countData = $this->database->query($sql);
			$comments[$index]['replies'] = $countData[0]['replies'];
			$comments[$index]['content'] = $notificationScraper->replaceNotificationsWithLinks($commentData['content']);
		}
		
		$view = new View();
		$viewData = array(
			'user' => $user,
			'comments' => $comments
		);
		if ($userId) {
			$viewData['userId'] = $userId;
		}
		return $view->render('commentsView.inc', $viewData);
	}

	public function getTopLevelComments($postId, $page = 0) {
		return $this->getComments($postId, 0, $page);
	}
}