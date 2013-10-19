<?php
class UserPreferencesController implements IController {
	public function execute() {
		$view = new View();
		
		$user = new User();
		$user->populate();
		
		$headRenderer = new HeadRenderer();
		$viewData = array(
			'header' => $headRenderer->render(),
			'displayName' => $user->getDisplayName(),
			'username' => $user->getUserName(),
			'email' => $user->getEmail()
		);
		return $view->render('userPreferencesView.inc', $viewData);
	}
}