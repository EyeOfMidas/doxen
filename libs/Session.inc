<?php
class Session {
	public function __construct() {
	}

	public function getId() {
		return session_id();
	}

	public function setId($newSessionId) {
		return session_id($newSessionId);
	}

	public function getName() {
		return session_name();
	}

	public function setName($newSessionName) {
		return session_name($newSessionName);
	}

	public function getValue($key) {
		if(isset($_SESSION[$key])) {
			return $_SESSION[$key];
		}
	}

	public function setValue($key, $value) {
		$_SESSION[$key] = $value;
	}

	public function clear() {
		session_destroy();
		session_start();
		session_regenerate_id(true);
	}
}
class SessionExpiredException extends Exception{}
