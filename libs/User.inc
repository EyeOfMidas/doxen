<?php
class User {
	private $data;

	public function populate() {
		$session = new Session();
		$userId = $session->getValue("logged_in");
		if($userId) {
			$database = new Database();
			$sql = "SELECT * FROM users WHERE user_id = '".$userId."'";
			$result = $database->query($sql);
			$this->data = $result[0];
		} else {
			throw new SessionExpiredException();
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
}
