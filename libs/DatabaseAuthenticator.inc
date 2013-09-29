<?php

class DatabaseAuthenticator {

	public function authenticate($username, $password) {
		$session = new Session();
		$session->clear();
		$logger = new Logger();
		try {
			$database = new Database();
			$sql = sprintf("SELECT users_auth.user_id FROM users_auth JOIN users on users.user_id = users_auth.user_id  WHERE username = '%s' AND passwordhash = '%s'"
				, $username
				, sha1($password)
			);
			$response = $database->query($sql);
			if ($response != array()) {
				$userId = $response[0]['user_id'];
				$session->setValue("logged_in", $userId);
				return $userId;
			}
		} catch (DatabaseConnectionException $e) {
			$logger->error("Unable to communicate with database");
		}
		return false;
	}
}
