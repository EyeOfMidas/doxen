<?php
class LoginController implements IController {
	public function execute() {
		$form = new Form();
		$username = $form->post("username");
		$password = $form->post("password");

		$authenticator = new Authenticator();
		$isAuthenticated = $authenticator->authenticate($username, $password);

		$view = new View();
		$loginData = array();
		if ($isAuthenticated) {
			$logoutViewData = array("username" => $username);

			$loginData = array(
				"result" => "success"
				, "html" => $view->render("logoutView.inc", $logoutViewData)
			);
		} else {
			$message = "Unable to authenticate user: perhaps the name or password is wrong?";
			$loginViewData = array(
				"message" => $message
				, "username" => $username
				);
			$loginData = array(
				"result" => "failure"
				, "html" => $view->render("loginView.inc", $loginViewData)
			);
			
		}
		return json_encode($loginData);

	}
}
