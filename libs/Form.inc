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
}
