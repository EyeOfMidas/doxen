<?php
class SubmitTopicSettingsController implements IController {
	public function execute() {
		//TODO: only admin, owner, moderator can see this page
		$form = new Form();
		$topicId = $form->getCleanDefaulted('id', 0);
		$topicDescription = $form->postCleanDefaulted('topicDescription', "");
		$topicSidebar = $form->postCleanDefaulted('topicSidebar', "");
		$newModeratorName = $form->postCleanDefaulted('addTopicModerator', "");
		
		$sql = sprintf("UPDATE topics SET description = '%s', sidebar = '%s' WHERE topic_id = '%s'", $topicDescription, $topicSidebar, $topicId);
		$database = new Database();
		$database->query($sql);
		
		$session = new Session();
		$userId = $session->getValue('logged_in');
		$sql = sprintf("SELECT * FROM user_topic_acl WHERE user_id = '%s' AND topic_id = '%s' AND (rank_id = 2 OR rank_id = 1)", $userId, $topicId);
		$permissionResults = $database->query($sql);
		if(count($permissionResults) > 0) {
			$cleanModName =trim(strtolower($newModeratorName)); 
			if($cleanModName != "") {
				$sql = sprintf("SELECT * FROM users WHERE username = '%s'", $cleanModName);
				$userData = $database->query($sql);
				if(count($userData) == 1) {
					$newModId = $userData[0]['user_id'];
					$sql = sprintf("INSERT INTO user_topic_acl (user_id, topic_id, rank_id) VALUES ('%s', '%s', '%s')",
						$newModId,
						$topicId,
						3
					);
					
					$database->write($sql);
				}
			}
		}
		$header = new Header();
		$header->redirect('?a=topicmanagement&id=' . $topicId);
	}
}