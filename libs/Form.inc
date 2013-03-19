<?php
class Form {
	public function get($index) {
		if (isset($_GET[$index])) {
			return $_GET[$index];
		}
	}

	public function post($index) {
		if (isset($_POST[$index])) {
			return $_POST[$index];
		}
	}

	public function getDefaulted($index, $defaultValue) {
		if (isset($_GET[$index]) && !empty($_GET[$index])) {
			return $_GET[$index];
		}
		return $defaultValue;
	}
}
