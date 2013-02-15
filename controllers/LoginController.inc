<?php
class LoginController implements IController {
	public function execute() {
		$view = new View();

		$form = new Form();
		$username = $form->post("username");
		$password = $form->post("password");
		$logoutViewData = array("username" => $username);

		$loginData = array(
			"result" => "success"
			, "username" => $username
			, "password" => $password
			, "html" => $view->render("logoutView.inc", $logoutViewData)
		);
		return json_encode($loginData);
	}
}
