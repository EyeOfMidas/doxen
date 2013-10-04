<?php

class TopicManagementController implements IController {

	public function execute() {
		$view = new View();
		$session = new Session();
		$userId = $session->getValue("logged_in");
		
		$loginViewDecider = new LoginViewDecider();
		
		$viewData = array(
			"loginView" => $loginViewDecider->decide()
		);
		if ($userId) {
			return $view->render('topicManagementView.inc', $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}