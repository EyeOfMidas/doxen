<?php

class TopicManagementController implements IController {

	public function execute() {
		$view = new View();
		$session = new Session();
		$userId = $session->getValue("logged_in");
		
		$loginViewDecider = new LoginViewDecider();
		
		$form = new Form();
		$topicId = $form->getCleanDefaulted('id', 0);
		
		$topicModel = new TopicModel();
		$topicData = $topicModel->getCurrentTopic($topicId);
		
		$viewData = array(
			"loginView" => $loginViewDecider->decide(),
			"topicData" => $topicData
		);
		if ($userId) {
			return $view->render('topicManagementView.inc', $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}