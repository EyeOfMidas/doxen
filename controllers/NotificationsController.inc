<?php
class NotificationsController implements IController {

	public function execute() {
		$view = new View();
		$form = new Form();
		$headRenderer = new HeadRenderer();
		$user = new User();
		$notificationScraper = new NotificationScraper();
		$postRenderer = new PostRenderer();
		$user->populate();
		
		$userId = $user->getId();
		$viewData = array(
			"header" => $headRenderer->render()
		);
		
		if ($userId) {
			
			//TODO: go through all posts made, pull any that are updated since last viewed
			//TODO: go through all comments made, pull any that are updated since last viewed
			
			$viewData['user'] = $user;
			$tagModel = new TagModel();
			$unreadTags = $tagModel->getUnseenTagsForUser($userId);
			$viewData['unreadTags'] = $unreadTags;
			return $view->render("notificationsView.inc", $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}