<?php
class UserModel {
	public function getIdFromUsername($username) {
		$sql = sprintf("SELECT user_id FROM users WHERE username = '%s'", $username);
		$database = new Database();
		$userData = $database->query($sql);
		return $userData[0]['user_id'];
	}
}