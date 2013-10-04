<?php
class SubmitNewTopicController implements IController {

	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		if ($userId) {
			$form = new Form();
			$newTopicName = $form->post("name");
			$displayName = $newTopicName;
			$newTopicName = strtolower($newTopicName);
			$database = new Database();
			$sql = "SELECT topic_id FROM topics WHERE display_name LIKE '".$newTopicName."'";
			$result = $database->query($sql);

			if($result == array()) {
				$sql = sprintf("INSERT INTO topics (display_name, url_name) VALUES ('%s', '%s')"
						, $displayName
						, $this->cleanName($newTopicName)
				);
				$topicId = $database->write($sql);
				
				$sql = sprintf("INSERT INTO user_topic_acl (user_id, topic_id, rank_id) VALUES ('%s', '%s', '%s')",
					$userId,
					$topicId,
					2 
				);
				
				$database->write($sql);
			} else {
				//topic already claimed
			}
			$header = new Header();
			$header->redirect("/?a=topicmanagement&id=".$topicId);
		} else {
			//not logged in
		}

	}

	private function cleanName($newTopicName) {
		$webWrapper = new WebWrapper();
		return $webWrapper->urlEncode($newTopicName);
	}
}