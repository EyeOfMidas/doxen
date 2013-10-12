<?php

class SubscribeController implements IController {

	public function execute() {
		$session = new Session();
		$view = new View();
		$database = new Database();
		$headRenderer = new HeadRenderer();
		
		$userId = $session->getValue("logged_in");
		
		// get list of all topics (paginated)
		$sql = "SELECT * FROM topics";
		$topics = $database->query($sql);
		
		$viewData = array(
			"header" => $headRenderer->render(),
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