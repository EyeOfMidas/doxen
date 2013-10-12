<?php

class SubscribeController implements IController {

	public function execute() {
		// only logged in user can see
		$session = new Session();
		$userId = $session->getValue("logged_in");
		$view = new View();
		$topicModel = new TopicModel();
		$database = new Database();
		$loginViewDecider = new LoginViewDecider();
		
		// get list of all topics (paginated)
		$sql = "SELECT * FROM topics";
		$topics = $database->query($sql);
		
		$viewData = array(
			"domain" => DOMAIN,
			"loginView" => $loginViewDecider->decide(),
			"topics" => $topics
		);
		if ($userId) {
			// get list of all user-subscriptions
			$sql = sprintf("SELECT topic_id FROM user_topic_subscription WHERE user_id = '%s'", $userId);
			$subscribedTopicsRaw = $database->query($sql);
			$subscribedTopics = array();
			foreach ($subscribedTopicsRaw as $topicData) {
				$subscribedTopics[] = $topicData['topic_id'];
			}
			
			// add "subscribed" flag to topics user is subscribed to
			foreach ($topics as $index => $topic) {
				if (in_array($topic['topic_id'], $subscribedTopics)) {
					$topics[$index]['subscribed'] = true;
				} else {
					$topics[$index]['subscribed'] = false;
				}
			}
			// return view for all topics
			$viewData["topics"] = $topics;
		}
		return $view->render("subscriptionView.inc", $viewData);
	}
}