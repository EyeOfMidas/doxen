<?php
class PostModel {

	public function getPostTopics($postId) {
		$sql = sprintf("SELECT t.topic_id, t.display_name, t.url_name 
			FROM post_topic_associations a
			JOIN topics t ON a.topic_id = t.topic_id 
			WHERE a.post_id = '%s'", $postId);
		$database = new Database();
		return $database->query($sql);
	}

	public function getPost($postId) {
		$sql = sprintf("SELECT p.post_id, u.user_id, p.timestamp, p.name as post_name, p.url_name as post_url_name, p.content, u.username, u.display_name as user_display_name, a.topic_id, t.display_name as topic_display_name
			FROM posts p
			JOIN post_topic_associations a ON p.post_id = a.post_id
			JOIN users u ON p.poster_user_id = u.user_id
			JOIN topics t ON a.topic_id = t.topic_id
			WHERE p.post_id = '%s'", $postId);
		$database = new Database();
		$postData = $database->query($sql);
		return $postData[0];
	}
}