<?php
class HeadRenderer {
	public function render() {
		$view = new View();
		$topicModel = new TopicModel();
		$loginViewDecider = new LoginViewDecider();
		
		$viewData = array(
			"domain" => DOMAIN,
			"loginView" => $loginViewDecider->decide(),
			"defaultTopics" =>  $topicModel->getUserTopics()
		);
		
		return $view->render('header.inc', $viewData);
	}
}