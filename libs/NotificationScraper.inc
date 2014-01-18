<?php
class NotificationScraper {

	public function getUserTags($text) {
		$matches = array();
		preg_match_all("/(^|)@(\w*[a-zA-Z_]+\w*)/", $text, $matches);
		$tags = $matches[0];
		foreach ($tags as $index => $tagString) {
			$tags[$index] = strtolower($tagString);
		}
		return $tags;
	}

	public function getNamesFromTags(array $tags) {
		$names = array();
		foreach ($tags as $tagString) {
			$names[] = trim($tagString, '@');
		}
		return $names;
	}

	public function getIdsFromTags(array $tags) {
		$userModel = new UserModel();
		$userIds = array();
		$names = $this->getNamesFromTags($tags);
		foreach ($names as $username) {
			$userIds[] = $userModel->getIdFromUsername($username);
		}
		return $userIds;
	}

	public function getUserdataFromTags(array $tags) {
		$userModel = new UserModel();
		$usersData = array();
		foreach ($tags as $tagString) {
			$usersData[$userModel->getIdFromUsername(trim($tagString, '@'))] = $tagString;
		}
		return $usersData;
	}
	
	public function getUserTagDataFromString($text) {
		$allTags = $this->getUserTags($text);
		$userData = $this->getUserdataFromTags($allTags);
		return $userData;
	}

	public function replaceNotificationsWithLinks($text) {
		$modifiedText = $text;
		$userData = $this->getUserTagDataFromString($modifiedText);
		foreach($userData as $userId => $userTag) {
			$modifiedText = str_ireplace($userTag, "<a href=\"?a=user&id=".$userId."\">".$userTag."</a>", $modifiedText);
		}
		
		return $modifiedText;
	}
}