<?php
class SubmitRegisterController implements IController {
	private $form;
	private $database;
	private $authenticator;
	private $header;

	public function __construct() {
		$this->form = new Form();
		$this->database = new Database();
		$this->authenticator = new Authenticator();
		$this->header = new Header();
	}

	public function execute() {
		$newDisplayName = $this->form->postCleanDefaulted('newUsername', "");
		$newUsername = strtolower($newDisplayName);
		$newEmail = strtolower($this->form->postCleanDefaulted('newEmail', ""));
		$newPassword1 = $this->form->postCleanDefaulted('newPassword1', "");
		$newPassword2 = $this->form->postCleanDefaulted('newPassword2', "");
		
		$sql = sprintf("SELECT * FROM users WHERE username = '%s' OR email = '%s'", $newUsername, $newEmail);
		$uniqueCheck = $this->database->query($sql);
		if (count($uniqueCheck) > 0) {
			// already in use
			return;
		}
		
		if ($newPassword1 != $newPassword2) {
			// passwords don't match
			return;
		}
		
		$sql = sprintf("INSERT INTO users (email, username, display_name)
			VALUES ('%s', '%s', '%s')", $newEmail, $newUsername, $newDisplayName);
		$userId = $this->database->write($sql);
		
		if ($userId == 0) {
			// something went wrong with inserting the user
			return;
		}
		$sql = sprintf("INSERT INTO users_auth (user_id, passwordhash)
			VALUES ('%s', SHA1('%s'))", $userId, $newPassword1);
		$this->database->write($sql);
		
		$sql = "SELECT * FROM default_topics";
		$defaultTopics = $this->database->query($sql);
		
		$sql = "INSERT INTO user_topic_subscription (user_id, topic_id) VALUES ";
		$subscribedTopics = array();
		foreach ($defaultTopics as $topicData) {
			$subscribedTopics[] = sprintf("('%s', '%s')", $userId, $topicData['topic_id']);
		}
		$sql .= implode(',', $subscribedTopics);
		$this->database->query($sql);
		
		$this->authenticator->authenticate($newUsername, $newPassword1);
		
		$this->header->redirect('/');
	}
}