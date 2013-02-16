<?php
class DatabaseAuthenticator {
	public function authenticate($username, $password) {
		$database = new Database();
		$sql = sprintf("SELECT user_id FROM users WHERE username = '%s' AND passwordhash = '%s'"
		, $username
		, sha1($password)
		 );
		$response = $database->query($sql);
		error_log(var_dump($response, true));
		return true;
	}
}
