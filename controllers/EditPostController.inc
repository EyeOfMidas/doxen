<?php
class EditPostController implements IController {

	public function execute() {
		$form = new Form();
		$postId = $form->getCleanDefaulted('id', 0);
		$topicId = $form->getCleanDefaulted('t', 0);
		$user = new User();
		$user->populate();
		$userId = $user->getId();
		$view = new View();
		$viewData = array();
		if ($userId) {
			$sql = sprintf("SELECT * FROM posts WHERE poster_user_id = '%s' AND post_id = '%s'", $userId, $postId);
			$database = new Database();
			$postData = $database->query($sql);
			$postData = $postData[0];
			$postData['content'] = htmlspecialchars_decode($postData['content']);
			if (! empty($postData)) {
				$headRenderer = new HeadRenderer();
				
				$topicModel = new TopicModel();
				$currentTopic = $topicModel->getCurrentTopic($topicId);
				$permissionDecider = new PermissionDecider();
				$viewData = array(
					'header' => $headRenderer->render(),
					'postData' => $postData,
					'topicId' => $topicId,
					'topicData' => $currentTopic,
					'topicAccess' => $permissionDecider->hasTopicAccess($topicId),
					'username' => $user->getDisplayName()
				);
				return $view->render('editPostView.inc', $viewData);
			}
		}
		// you must log in to view this page!
	}
}