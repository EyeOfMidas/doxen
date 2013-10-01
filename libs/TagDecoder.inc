<?php

class TagDecoder {

	public function getTagIds($tagString) {
		$tagsFound = array();
		$possibleTags = explode(",", $tagString);
		$topicModel = new TopicModel();
		$allTopics = $topicModel->getAllTopicNames();
		foreach ($possibleTags as $oneTag) {
			$cleanTag = strtolower(trim($oneTag));
			if ($key = array_search($cleanTag, $allTopics)) {
				$tagsFound[] = $key;
			}
		}
		return $tagsFound;
	}
}