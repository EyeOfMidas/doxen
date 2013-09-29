<?php

class Authenticator {

	public function authenticate($username, $password) {
		$databaseAuthenticator = new DatabaseAuthenticator();
		return $databaseAuthenticator->authenticate($username, $password);
	}
}
