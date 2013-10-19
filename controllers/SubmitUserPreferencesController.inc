<?php
class SubmitUserPreferencesController implements IController {
	private $form;
	private $user;
	private $database;
	private $header;

	public function __construct() {
		$this->form = new Form();
		$this->user = new User();
		$this->database = new Database();
		$this->header = new Header();
	}

	public function execute() {
		$this->user->populate();
		$userId = $this->user->getId();
		
		if ($userId) {
			$sql = sprintf("SELECT * FROM users WHERE user_id = '%s'", $userId);
			$userData = $this->database->query($sql);
			$currentUserData = $userData[0];
			
			$newDisplayName = $this->form->postCleanDefaulted('displayName', $currentUserData['display_name']);
			if ($newDisplayName != $currentUserData['display_name']) {
				$sql = sprintf("UPDATE users SET display_name = '%s' WHERE user_id = '%s'", $newDisplayName, $userId);
				$this->database->query($sql);
			}
			$this->header->redirect("?a=preferences");
		}
	}
}