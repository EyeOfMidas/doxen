<?php

class TopicManagementController implements IController {

	public function execute() {
		$view = new View();
		$session = new Session();
		$userId = $session->getValue("logged_in");
		
		$loginViewDecider = new LoginViewDecider();
		
		$form = new Form();
		$topicId = $form->getCleanDefaulted('id', 0);
		
		$topicModel = new TopicModel();
		$topicData = $topicModel->getCurrentTopic($topicId);
		
		$sql = sprintf("SELECT * 
			FROM user_topic_acl acl
			JOIN users u ON acl.user_id = u.user_id
			WHERE rank_id = 2 AND topic_id = '%s'", $topicId);
		$database = new Database();
		$ownerData = $database->query($sql);
		
		$sql = sprintf("SELECT *
			FROM user_topic_acl acl
			JOIN users u ON acl.user_id = u.user_id
			WHERE rank_id = 3 AND topic_id = '%s'", $topicId);
		$database = new Database();
		$moderatorData = $database->query($sql);
		
		$permissionDecider = new PermissionDecider();
		$topicAccess = $permissionDecider->hasTopicAccess($topicId);
		
		$viewData = array(
			"loginView" => $loginViewDecider->decide(),
			"topicData" => $topicData,
			"owner" => $ownerData[0],
			"moderators" => $moderatorData,
			"topicAccess" => $topicAccess
		);
		if ($userId) {
			return $view->render('topicManagementView.inc', $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}