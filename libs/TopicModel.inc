<?php
class TopicModel {
	public function getAllTopicNames() {
		$topicNames = array();
		$sql = sprintf("SELECT topic_id,url_name FROM topics");
		$database = new Database();
		$topicNamesRaw = $database->query($sql);
		
		foreach($topicNamesRaw as $topicData) {
			$topicNames[$topicData['topic_id']] = $topicData['url_name'];
		}
		
		return $topicNames;
	}
	
	public function getDefaultTopics() {
		$sql = "SELECT * FROM topics WHERE topic_id IN (SELECT topic_id FROM default_topics ORDER BY sort_order ASC)";
		$database = new Database();
		return $database->query($sql);
	}
	
	public function getCurrentTopic($topicId) {
		$topicData = array();
		$sql = sprintf("SELECT * FROM topics WHERE topic_id = '%s", $topicId);
		$database = new Database();
		$topicData = $database->query($sql);
		return $topicData;
	}
}