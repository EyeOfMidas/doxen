<?php

class LoginController implements IController {

	public function execute() {
		$form = new Form();
		$username = strtolower($form->post("username"));
		$password = $form->post("password");
		
		$authenticator = new Authenticator();
		$isLoggedIn = $authenticator->authenticate($username, $password);
		
		$view = new View();
		$loginData = array();
		$message = "";
		
		if ($isLoggedIn) {
			$user = new User();
			try {
				$user->populate();
			} catch (SessionExpiredException $e) {
				$message = "Session has expired.";
			}
		} else {
			$message = "Unable to authenticate user: perhaps the name or password is wrong?";
		}
		$location = "/";
		$header = new Header();
		if($message) {
			$location .= "?e=" . base64_encode($message);
		}
		$header->redirect($location);
	}
}
