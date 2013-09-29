<?php
class LoginViewDecider {
	public function decide() {
		$session = new Session();
		$logger = new Logger();
		$form = new Form();
		$userId = $session->getValue("logged_in");
		
		$view = new View();
		if($userId){
			$user = new User();
			$user->populate();
			$logoutViewData = array("username" => $user->getDisplayName());
			return $view->render("logoutView.inc", $logoutViewData);
		}
		$errorMessage = $form->getCleanEncodedDefaulted("e", "");
		$loginViewData = array("message" => $errorMessage);
		return $view->render("loginView.inc", $loginViewData);
	}
}
