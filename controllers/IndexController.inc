<?php

class IndexController implements IController {

	public function execute() {
		$view = new View();
		
		$topicModel = new TopicModel();
		$defaultTopics = $topicModel->getDefaultTopics();
		
		$form = new Form();
		$dirtyPage = $form->getDefaulted("c", 0);
		$postRenderer = new PostRenderer();
		
		$loginViewDecider = new LoginViewDecider();
		$loginViewData = array();
		$indexViewData = array(
			"domain" => DOMAIN,
			"loginView" => $loginViewDecider->decide(),
			"postsView" => $postRenderer->getPostsInDefaultTopics($dirtyPage),
			"defaultTopics" => $defaultTopics
		);
		return $view->render("indexView.inc", $indexViewData);
	}
}
