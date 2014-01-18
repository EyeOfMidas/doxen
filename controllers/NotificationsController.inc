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
		
		// TODO: only logged in users can see this page
		$userId = $user->getId();
		if ($userId) {
			
			$notificationsView = array(
				"header" => $headRenderer->render(),
				'user' => $user,
				"postsView" => $postRenderer->getPostedTaggedIn($userId)
			);
			
			return $view->render("notificationsView.inc", $notificationsView);
		}
	}
}