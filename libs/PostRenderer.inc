<?php
class PostRenderer {
	const PAGE_SIZE = 20;
	
	private $database;

	public function __construct() {
		$this->database = new Database();
	}

	public function getPostsInDefaultTopics($page = 0) {
		$view = new View();
		$sql = sprintf("SELECT p.*,a.topic_id,u.* 
			FROM posts p 
			JOIN post_topic_associations a ON p.post_id = a.post_id 
			JOIN users u ON p.poster_user_id = u.user_id 
			WHERE a.topic_id IN (SELECT topic_id FROM default_topics) 
			ORDER BY timestamp DESC LIMIT %s, %s"
			,$page * PostRenderer::PAGE_SIZE
			, PostRenderer::PAGE_SIZE
		);
                $posts = $this->database->query($sql);

                $postViewData = array("posts" => $posts);
                return $view->render("postView.inc", $postViewData);

	}

	public function getPostsInTopic($topicId, $page = 0) {
		$view = new View();
		$sql = sprintf("SELECT p.*,a.topic_id,u.* 
			FROM posts p 
			JOIN post_topic_associations a ON p.post_id = a.post_id 
			JOIN users u ON p.poster_user_id = u.user_id 
			WHERE topic_id = '%s' 
			ORDER BY timestamp DESC LIMIT %s, %s"
			, $topicId
			, $page * PostRenderer::PAGE_SIZE
			, PostRenderer::PAGE_SIZE
);
                $posts = $this->database->query($sql);
                $postViewData = array("posts" => $posts);
		return $view->render("postView.inc", $postViewData);
	}
}
