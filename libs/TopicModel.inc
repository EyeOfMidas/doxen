<?php
class TopicModel {
	public function getAllTopicNames() {
		$topicNames = array();
		$sql = sprintf("SELECT topic_id,display_name,url_name FROM topics");
		$database = new Database();
		$topicNamesRaw = $database->query($sql);
		
		foreach($topicNamesRaw as $topicData) {
			$topicNames[$topicData['topic_id']] = strtolower($topicData['display_name']);
		}
		
		return $topicNames;
	}
	
	public function getDefaultTopics() {
		$sql = "SELECT * FROM topics WHERE topic_id IN (SELECT topic_id FROM default_topics ORDER BY sort_order ASC)";
		$database = new Database();
		return $database->query($sql);
	}
	
	public function getUserTopics() {
		$session = new Session();
		$userId = $session->getValue('logged_in');
		if($userId) {
			$sql = sprintf("SELECT * 
				FROM topics 
				WHERE topic_id 
				IN (SELECT topic_id FROM user_topic_subscription WHERE user_id = '%s')", $userId);
		$database = new Database();
		return $database->query($sql);
		}
		return $this->getDefaultTopics();
	}
	
	public function getCurrentTopic($topicId) {
		$topicData = array();
		$sql = sprintf("SELECT * FROM topics WHERE topic_id = '%s'", $topicId);
		$database = new Database();
		$topicData = $database->query($sql);
		if(isset($topicData[0])) {
			return $topicData[0];
		}
		return array();
	}
}