<?php
class IndexController implements IController {
	public function execute() {
		$view = new View();
		$loginViewData = array();
		$indexViewData = array(
			"domain" => DOMAIN
			, "loginView" => $view->render("loginView.inc", $loginViewData)
		);
		return $view->render("indexView.inc", $indexViewData);
	}
}
