<?php
class IndexController implements IController {
	public function execute() {
		$view = new View();
		$loginViewDecider = new LoginViewDecider();
		$loginViewData = array();
		$indexViewData = array(
			"domain" => DOMAIN
			, "loginView" => $loginViewDecider->decide()
		);
		return $view->render("indexView.inc", $indexViewData);
	}
}
