<?php
class PostRenderer {
	const PAGE_SIZE = 20;
	private $database;

	public function __construct() {
		$this->database = new Database();
	}

	public function getPostsInUserTopics($page = 0) {
		$user = new User();
		$user->populate();
		$userId = $user->getId();
		if ($userId) {
			$view = new View();
			$sql = sprintf("SELECT p.post_id, u.user_id, p.timestamp, p.name as post_name, p.url_name as post_url_name, p.content, u.username, u.display_name as user_display_name, t.topic_id, t.display_name as topic_display_name
			FROM posts p
			JOIN post_topic_associations a ON p.post_id = a.post_id
			JOIN users u ON p.poster_user_id = u.user_id
			JOIN topics t on t.topic_id = a.topic_id
			WHERE a.topic_id IN (SELECT topic_id FROM user_topic_subscription WHERE user_id = '%s')
			OR a.topic_id IN (SELECT subtopic_id FROM topic_topic_associations WHERE topic_id IN (SELECT topic_id FROM user_topic_subscription WHERE user_id = '%s'))
			ORDER BY timestamp DESC LIMIT %s, %s", $userId, $userId, $page * PostRenderer::PAGE_SIZE, PostRenderer::PAGE_SIZE);
			
			$posts = $this->database->query($sql);
			
			$posts = $this->addCommentCount($posts);
			$posts = $this->addPostDifferent($posts, $userId);
			
			$postViewData = array(
				"posts" => $posts
			);
			return $view->render("postView.inc", $postViewData);
		}
		return $this->getPostsInDefaultTopics($page);
	}

	public function getPostsInDefaultTopics($page = 0) {
		$view = new View();
		$sql = sprintf("SELECT p.post_id, u.user_id, p.timestamp, p.name as post_name, p.url_name as post_url_name, p.content, u.username, u.display_name as user_display_name, t.topic_id, t.display_name as topic_display_name 
			FROM posts p 
			JOIN post_topic_associations a ON p.post_id = a.post_id 
			JOIN users u ON p.poster_user_id = u.user_id 
			JOIN topics t on t.topic_id = a.topic_id
			WHERE a.topic_id IN (SELECT topic_id FROM default_topics) 
			OR a.topic_id IN (SELECT subtopic_id FROM topic_topic_associations WHERE topic_id IN (SELECT topic_id FROM default_topics))
			ORDER BY timestamp DESC LIMIT %s, %s", $page * PostRenderer::PAGE_SIZE, PostRenderer::PAGE_SIZE);
		
		$posts = $this->database->query($sql);
		
		$posts = $this->addCommentCount($posts);
		
		$postViewData = array(
			"posts" => $posts
		);
		return $view->render("postView.inc", $postViewData);
	}

	private function addCommentCount($posts) {
		foreach ($posts as $index => $post) {
			$sql = sprintf("SELECT count(*) AS comment_count FROM comment_post_associations WHERE post_id = '%s'", $post['post_id']);
			$countResult = $this->database->query($sql);
			$count = $countResult[0]['comment_count'];
			$posts[$index]['comment_count'] = $count;
		}
		return $posts;
	}

	private function addPostDifferent($posts, $userId) {
		foreach ($posts as $index => $post) {
			$sql = sprintf("SELECT 1 FROM post_last_updated plu JOIN user_post_viewed upv ON plu.post_id = upv.post_id WHERE plu.post_id = %s AND upv.user_id = %s AND plu.last_updated > upv.last_viewed", $post['post_id'], $userId);
			$timeData = $this->database->query($sql);
			$newContent = false;
			if (count($timeData) > 0) {
				$newContent = true;
			}
			$posts[$index]['new_content'] = $newContent;
		}
		return $posts;
	}

	public function getPostsInTopic($topicId, $page = 0) {
		$view = new View();
		$sql = sprintf("SELECT p.post_id, u.user_id, p.timestamp, p.name as post_name, p.url_name as post_url_name, p.content, t.topic_id, u.username, u.display_name as user_display_name, t.display_name as topic_display_name, t.url_name as topic_url_name
			FROM posts p 
			JOIN post_topic_associations a ON p.post_id = a.post_id 
			JOIN users u ON p.poster_user_id = u.user_id 
			JOIN topics t ON a.topic_id = t.topic_id
			WHERE a.topic_id = '%s' 
			OR a.topic_id IN (SELECT subtopic_id FROM topic_topic_associations WHERE topic_id = '%s')
			ORDER BY timestamp DESC LIMIT %s, %s", $topicId, $topicId, $page * PostRenderer::PAGE_SIZE, PostRenderer::PAGE_SIZE);
		$posts = $this->database->query($sql);
		
		$posts = $this->addCommentCount($posts);
		$user = new User();
		$user->populate();
		$userId = $user->getId();
		if ($userId) {
			$posts = $this->addPostDifferent($posts, $userId);
		}
		
		$postViewData = array(
			"posts" => $posts
		);
		return $view->render("postView.inc", $postViewData);
	}

	public function getPostsByUser($userId, $page = 0) {
		$view = new View();
		$sql = sprintf("SELECT p.post_id, u.user_id, p.timestamp, p.name as post_name, p.url_name as post_url_name, p.content, u.username, u.display_name as user_display_name, t.topic_id, t.display_name as topic_display_name
			FROM posts p
			JOIN post_topic_associations a ON p.post_id = a.post_id
			JOIN users u ON p.poster_user_id = u.user_id
			JOIN topics t on t.topic_id = a.topic_id
			WHERE p.poster_user_id = '%s'
			ORDER BY timestamp DESC LIMIT %s, %s", $userId, $page * PostRenderer::PAGE_SIZE, PostRenderer::PAGE_SIZE);
		
		$posts = $this->database->query($sql);
		
		$posts = $this->addCommentCount($posts);
		$post = $this->addPostDifferent($posts, $userId);
		
		$postViewData = array(
			"posts" => $posts
		);
		return $view->render("postView.inc", $postViewData);
	}
	
	public function getPostedTaggedIn($userId, $page = 0) {
		$view = new View();
		$sql = sprintf("SELECT p.post_id, u.user_id, p.timestamp, p.name as post_name, p.url_name as post_url_name, p.content, u.username, u.display_name as user_display_name, t.topic_id, t.display_name as topic_display_name
			FROM posts p
			JOIN post_topic_associations a ON p.post_id = a.post_id
			JOIN post_tags pt ON pt.post_id = p.post_id
			JOIN user_tags ut ON ut.tag_id = pt.tag_id
			JOIN users u ON ut.user_id = u.user_id
			JOIN topics t on t.topic_id = a.topic_id
			WHERE ut.user_id = '%s'
			ORDER BY ut.tagged_on DESC LIMIT %s, %s", $userId, $page * PostRenderer::PAGE_SIZE, PostRenderer::PAGE_SIZE);
		
		$posts = $this->database->query($sql);
		
		$posts = $this->addCommentCount($posts);
		$post = $this->addPostDifferent($posts, $userId);
		
		$postViewData = array(
			"posts" => $posts
		);
		return $view->render("postView.inc", $postViewData);
	}
}
