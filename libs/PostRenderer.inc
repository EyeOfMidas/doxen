<?php
class PostRenderer {
	const PAGE_SIZE = 20;
	
	private $database;

	public function __construct(Database $database) {
		$this->database = $database;
	}

	public function getPostsInDefaultTopics($page = 0) {
		$view = new View();
		$sql = sprintf("SELECT * FROM posts JOIN users ON user_id = poster_user_id WHERE parent_topic_id IN (SELECT topic_id FROM default_topics) ORDER BY timestamp DESC LIMIT %s, %s"
			,$page * PostRenderer::PAGE_SIZE
			, PostRenderer::PAGE_SIZE
		);
                $posts = $this->database->query($sql);

                $postViewData = array("posts" => $posts);
                return $view->render("postView.inc", $postViewData);

	}

	public function getPostsInTopic($topicId, $page = 0) {
		$view = new View();
		$sql = sprintf("SELECT * FROM posts JOIN users on user_id = poster_user_id WHERE parent_topic_id = '%s' ORDER BY timestamp DESC LIMIT %s, %s"
			, $topicId
			, $page * PostRenderer::PAGE_SIZE
			, PostRenderer::PAGE_SIZE
);
                $posts = $this->database->query($sql);
                $postViewData = array("posts" => $posts);
		return $view->render("postView.inc", $postViewData);
	}
}
