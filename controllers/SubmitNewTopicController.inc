<?php
class SubmitNewTopicController implements IController {

	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		if ($userId) {
			$form = new Form();
			$newTopicName = $form->post("name");
			$newTopicName = strtolower($newTopicName);
			$database = new Database();
			$sql = "SELECT topic_id FROM topics WHERE display_name LIKE '".$newTopicName."'";
			$result = $database->query($sql);

			if($result == array()) {
				$sql = sprintf("INSERT INTO topics (display_name, url_name) VALUES ('%s', '%s')"
						, $newTopicName
						, $this->cleanName($newTopicName)
				);
				$topicId = $database->write($sql);
				$sql = sprintf("INSERT INTO topic_moderators (topic_id, user_id, rank) VALUES ('%s', '%s', 'owner')"
						, $topicId
						, $userId
				);
				$database->write($sql);
			}
			$header = new Header();
			$header->redirect("/");
		} else {
			//not logged in
		}

	}

	private function cleanName($newTopicName) {
		$webWrapper = new WebWrapper();
		return $webWrapper->urlEncode($newTopicName);
	}
}