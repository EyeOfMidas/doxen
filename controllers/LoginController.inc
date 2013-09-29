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
		$message = "Unable to authenticate user: perhaps the name or password is wrong?";
		
		if ($isLoggedIn) {
			$user = new User();
			try {
				$user->populate();
			} catch (SessionExpiredException $e) {
				$message = "Session has expired.";
			}
		}
		$header = new Header();
		$header->redirect("/?e=" . base64_encode($message));
	}
}
