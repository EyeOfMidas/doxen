<?php
class LogoutController implements IController {
	public function execute() {
		$view = new View();

		$loginViewData = array();
		$logoutView = array(
			"result" => "success"
			, "html" => $view->render("loginView.inc", $loginViewData)
		);
		return json_encode($logoutView);
	}
}
