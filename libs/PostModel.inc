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
}