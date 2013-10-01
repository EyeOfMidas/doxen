<?php

class PostController implements IController {

	public function execute() {
		$view = new View();
		
		$form = new Form();
		$postId = $form->getCleanDefaulted("id", 0);
		
		$sql = sprintf("SELECT p.post_id, u.user_id, p.timestamp, p.name as post_name, p.url_name as post_url_name, p.content, u.username, u.display_name as user_display_name
			FROM posts p
			JOIN post_topic_associations a ON p.post_id = a.post_id 
			JOIN users u ON p.poster_user_id = u.user_id 
			WHERE p.post_id = '%s'", $postId);
		$database = new Database();
		$currentPost = $database->query($sql);
		$currentPost = $currentPost[0];
		
		$loginViewDecider = new LoginViewDecider();
		
		$topicModel = new TopicModel();
		$defaultTopics = $topicModel->getDefaultTopics();
		
		$postModel = new PostModel();
		$postTopics = $postModel->getPostTopics($postId);
		
		$commentsRenderer = new CommentsRenderer();
		
		$postViewData = array(
			"domain" => DOMAIN,
			"loginView" => $loginViewDecider->decide(),
			"postData" => $currentPost,
			"commentView" => $commentsRenderer->getTopLevelComments($postId),
			'defaultTopics' => $defaultTopics,
			'postTopics' => $postTopics
		);
		
		return $view->render("postPageView.inc", $postViewData);
	}
}
