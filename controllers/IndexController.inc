<?php
class IndexController implements IController {
	public function execute() {
		$view = new View();
		$postView = $view->render("postView.inc", array());
		$loginViewDecider = new LoginViewDecider();
		$loginViewData = array();
		$indexViewData = array(
			"domain" => DOMAIN
			, "loginView" => $loginViewDecider->decide()
			, "postsView" => $postView
		);
		return $view->render("indexView.inc", $indexViewData);
	}
}
