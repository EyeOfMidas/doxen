<?php
class LogoutController implements IController {
	public function execute() {
		$view = new View();
		$session = new Session();
		$session->clear();
		$loginViewData = array();
		$logoutView = array(
			"result" => "success"
			, "html" => $view->render("loginView.inc", $loginViewData)
		);
		return json_encode($logoutView);
	}
}
