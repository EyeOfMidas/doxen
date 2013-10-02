<?php

class PostController implements IController {

	public function execute() {
		$view = new View();
		
		$form = new Form();
		$postId = $form->getCleanDefaulted("id", 0);
		$topicId = $form->getCleanDefaulted("t", 0);
		
		$postModel = new PostModel();
		$currentPost = $postModel->getPost($postId, $topicId);
		
		
		$loginViewDecider = new LoginViewDecider();
		
		$topicModel = new TopicModel();
		$defaultTopics = $topicModel->getDefaultTopics();
		$currentTopic = $topicModel->getCurrentTopic($topicId);
		
		$postTopics = $postModel->getPostTopics($postId);
		
		$commentsRenderer = new CommentsRenderer();
		
		$postViewData = array(
			"domain" => DOMAIN,
			"loginView" => $loginViewDecider->decide(),
			"postData" => $currentPost,
			"commentView" => $commentsRenderer->getTopLevelComments($postId, $topicId),
			'defaultTopics' => $defaultTopics,
			'postTopics' => $postTopics
		);
		
		return $view->render("postPageView.inc", $postViewData);
	}
}
