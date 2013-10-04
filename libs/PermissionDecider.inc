<?php

class PermissionDecider {

	public function hasTopicAccess($topicId) {
		$topicAccess = false;
		$session = new Session();
		$userId = $session->getValue("logged_in");
		
		if ($userId) {
			$sql = sprintf("SELECT *
			FROM user_topic_acl
			WHERE user_id = '%s'
				AND topic_id = '%s'
				AND (rank_id = 1 OR rank_id = 2 OR rank_id = 3)", $userId, $topicId);
			
			$database = new Database();
			$permissionResults = $database->query($sql);
			if (count($permissionResults) > 0) {
				$topicAccess = true;
			}
		}
		return $topicAccess;
	}
}