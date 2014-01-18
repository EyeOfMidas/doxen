<?php
class NotificationsController implements IController {
	public function execute() {
		$view = new View();
		$form = new Form();
		$headRenderer = new HeadRenderer();
		$user = new User();
		$user->populate();
		
		$notificationsView = array(
			"header" => $headRenderer->render(),
			'user' => $user
		);
		
		return $view->render("notificationsView.inc", $notificationsView);
	}
}