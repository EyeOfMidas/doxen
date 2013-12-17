<?php
class TopicManagementController implements IController {

	public function execute() {
		$view = new View();
		$database = new Database();
		$permissionDecider = new PermissionDecider();
		$headRenderer = new HeadRenderer();
		$user = new User();
		$loginViewDecider = new LoginViewDecider();
		$form = new Form();
		$topicModel = new TopicModel();
		
		$user->populate();
		$userId = $user->getId();
		
		$topicId = $form->getCleanDefaulted('id', 0);
		
		$topicData = $topicModel->getCurrentTopic($topicId);
		
		$sql = sprintf("SELECT * 
			FROM user_topic_acl acl
			JOIN users u ON acl.user_id = u.user_id
			WHERE rank_id = 2 AND topic_id = '%s'", $topicId);
		$ownerData = $database->query($sql);
		
		$sql = sprintf("SELECT *
			FROM user_topic_acl acl
			JOIN users u ON acl.user_id = u.user_id
			WHERE rank_id = 3 AND topic_id = '%s'", $topicId);
		$moderatorData = $database->query($sql);
		
		$sql = sprintf("SELECT  t.topic_id, t.display_name, t.description
			FROM topic_topic_associations tt
			JOIN topics t ON t.topic_id = tt.subtopic_id
			WHERE tt.topic_id = '%s'", $topicId);
		$subtopics = $database->query($sql);
		
		$topicAccess = $permissionDecider->hasTopicAccess($topicId);
		
		$viewData = array(
			"header" => $headRenderer->render(),
			"topicData" => $topicData,
			"owner" => $ownerData[0],
			"moderators" => $moderatorData,
			"topicAccess" => $topicAccess,
			"subtopics" => $subtopics
		);
		if ($userId) {
			return $view->render('topicManagementView.inc', $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}