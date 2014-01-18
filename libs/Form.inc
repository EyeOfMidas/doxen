<?php

class Form {

	private $userInputScrubber;
	
	public function __construct() {
		$this->userInputScrubber = new UserInputScrubber();
	}
	
	public function get($index) {
		if (isset($_GET[$index])) {
			return $_GET[$index];
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
		return $this->userInputScrubber->scrubString($this->getDefaulted($index, $defaultValue));
	}

	public function getCleanEncodedDefaulted($index, $defaultValue) {
		return $this->userInputScrubber->scrubString($this->getEncodedDefaulted($index, $defaultValue));
	}

	public function post($index) {
		if (isset($_POST[$index])) {
			return $_POST[$index];
		}
	}

	public function postDefaulted($index, $defaultValue) {
		if (isset($_POST[$index]) && ! empty($_POST[$index])) {
			return $_POST[$index];
		}
		return $defaultValue;
	}
	
	public function postCleanDefaulted($index, $defaultValue) {
		return $this->userInputScrubber->scrubString($this->postDefaulted($index, $defaultValue));
	}
	
	public function file($index) {
		$fileData = array();
		if($_FILES[$index]['error'] <= 0) {
			$fileData = $_FILES[$index];
		}
		return $fileData;
	}
}
