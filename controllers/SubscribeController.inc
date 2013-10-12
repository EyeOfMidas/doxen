<?php

class SubscribeController implements IController {

	public function execute() {
		// only logged in user can see
		$session = new Session();
		$userId = $session->getValue("logged_in");
		$view = new View();
		$topicModel = new TopicModel();
		$viewData = array();
		if ($userId) {
			// get list of all user-subscriptions
			// get list of all topics (paginated)
			$topics = $topicModel->getAllTopicNames();
			
			// add "subscribed" flag to topics user is subscribed to
			// return view for all topics
			$loginViewDecider = new LoginViewDecider();
			$viewData = array(
				"domain" => DOMAIN,
				"loginView" => $loginViewDecider->decide(),
				"topics" => $topics
			);
			return $view->render("subscriptionView.inc", $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}