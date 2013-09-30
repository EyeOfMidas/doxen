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
}