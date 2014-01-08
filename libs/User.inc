<?php
class User {
	private $data;

	public function populate() {
		$session = new Session();
		$userId = $session->getValue("logged_in");
		if($userId) {
			$database = new Database();
			$sql = sprintf("SELECT * FROM users WHERE user_id = '%s'", $userId);
			$result = $database->query($sql);
			$this->data = $result[0];
			
			$sql = sprintf("SELECT * FROM user_topic_acl WHERE user_id = '%s'", $userId);
			$result = $database->query($sql);
			
			$this->acl = array();
			foreach($result as $userAccess) {
				$this->acl[$userAccess['topic_id']] = $userAccess['rank_id'];
			}
		} else {
			//throw new SessionExpiredException();
			//shouldn't throw, but something needs to be done if the user isn't logged in
		}
	}

	public function getUserName() {
		return $this->data['username'];
	}

	public function getDisplayName() {
		return $this->data['display_name'];
	}

	public function getId() {
		return $this->data['user_id'];
	}
	
	public function getEmail() {
		return $this->data['email'];
	}
	
	public function isTopicModerator($topicId) {
		return isset($this->acl[$topicId]) && $this->acl[$topicId] >= 3;
	}
	
	public function isTopicOwner($topicId) {
		return isset($this->acl[$topicId]) && $this->acl[$topicId] >= 2;
	}
	
	public function isLoggedIn() {
		$session = new Session();
		return $session->getValue("logged_in");
	}
	
	public function markPostViewed($postId) {
		if($this->isLoggedIn()) {
		$sql = sprintf("INSERT INTO user_post_viewed (user_id, post_id) VALUES (%s, %s) ON DUPLICATE KEY UPDATE last_viewed = NOW()", 
			$this->getId(), $postId);
		$database = new Database();
		$database->write($sql);
		}
	}
}
