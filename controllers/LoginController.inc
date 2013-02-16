<?php
class LoginController implements IController {
	public function execute() {
		$form = new Form();
		$username = $form->post("username");
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
				$logoutViewData = array("username" => $user->getDisplayName());
	
				$loginData = array(
					"result" => "success"
					, "html" => $view->render("logoutView.inc", $logoutViewData)
				);

				return json_encode($loginData);
			} catch (SessionExpiredException $e) {
				$message = "Session has expired.";
			}
		}
		return $this->loginFailedResponse($view, $username, $message);

	}

	private function loginFailedResponse($view, $username, $message) {
		$loginViewData = array(
			"message" => $message
			, "username" => $username
			);
		$loginData = array(
			"result" => "failure"
			, "html" => $view->render("loginView.inc", $loginViewData)
		);
		return json_encode($loginData);
	}
}
