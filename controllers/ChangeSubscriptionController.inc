<?php

class ChangeSubscriptionController implements IController {

	const SUBSCRIBE = 1;

	const UNSUBSCRIBE = 0;

	public function execute() {
		$view = new View();
		$session = new Session();
		$userId = $session->getValue("logged_in");
		$viewData = array();
		if ($userId) {
			$form = new Form();
			$database = new Database();
			$topicId = $form->getCleanDefaulted('id', 0);
			$subscribeAction = $form->getCleanDefaulted('s', ChangeSubscriptionController::UNSUBSCRIBE);
			switch ($subscribeAction) {
				case ChangeSubscriptionController::SUBSCRIBE:
					$sql = sprintf("INSERT IGNORE 
							INTO user_topic_subscription (user_id, topic_id) 
							VALUES ('%s', '%s')", $userId, $topicId);
					$database->query($sql);
					break;
				case ChangeSubscriptionController::UNSUBSCRIBE:
					$sql = sprintf("DELETE IGNORE 
							FROM user_topic_subscription
							WHERE user_id = '%s' AND topic_id = '%s'", $userId, $topicId);
					$database->query($sql);
					break;
			}
		}
	}
}