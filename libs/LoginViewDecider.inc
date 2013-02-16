<?php
class LoginViewDecider {
	public function decide() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		$view = new View();
		if($userId){
			$user = new User();
			$user->populate();
			$logoutViewData = array("username" => $user->getDisplayName());
			return $view->render("logoutView.inc", $logoutViewData);
		}
		$loginViewData = array();
		return $view->render("loginView.inc", $loginViewData);
	}
}
