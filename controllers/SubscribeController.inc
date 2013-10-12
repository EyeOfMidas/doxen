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
			$database = new Database();
			$sql = sprintf("SELECT topic_id FROM user_topic_subscription WHERE user_id = '%s'", $userId);
			$subscribedTopicsRaw = $database->query($sql);
			$subscribedTopics = array();
			foreach($subscribedTopicsRaw as $topicData) {
				$subscribedTopics[] = $topicData['topic_id'];
			}
			// get list of all topics (paginated)
			$sql = "SELECT * FROM topics";
			$topics = $database->query($sql);
			
			// add "subscribed" flag to topics user is subscribed to
			foreach($topics as $index => $topic) {
				if(in_array($topic['topic_id'], $subscribedTopics)) {
					$topics[$index]['subscribed'] = true;
				} else {
					$topics[$index]['subscribed'] = false;
				}
			}
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