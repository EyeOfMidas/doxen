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
		if (isset($_GET[$index]) && ! empty($_GET[$index])) {
			return $_GET[$index];
		}
		return $defaultValue;
	}

	public function getEncodedDefaulted($index, $defaultValue) {
		return base64_decode($this->getDefaulted($index, $defaultValue));
	}

	public function getCleanDefaulted($index, $defaultValue) {
		$userInputScrubber = new UserInputScrubber();
		return $userInputScrubber->scrubString($this->getDefaulted($index, $defaultValue));
	}

	public function getCleanEncodedDefaulted($index, $defaultValue) {
		$userInputScrubber = new UserInputScrubber();
		return $userInputScrubber->scrubString($this->getEncodedDefaulted($index, $defaultValue));
	}
}
