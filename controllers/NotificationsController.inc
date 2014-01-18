<?php
class NotificationsController implements IController {
	public function execute() {
		$view = new View();
		$form = new Form();
		$headRenderer = new HeadRenderer();
		$user = new User();
		$notificationScraper = new NotificationScraper();
		$user->populate();
		
		//$taggedUsers = $notificationScraper->replaceNotificationsWithLinks($testText);
		
		$notificationsView = array(
			"header" => $headRenderer->render(),
			'user' => $user
			//'taggedUsers' => $taggedUsers
		);
		
		return $view->render("notificationsView.inc", $notificationsView);
	}
}