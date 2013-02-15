<?php
class ControllerFactory {
	public function create() {
		$form = new Form();
		$action = $form->get("a");
		switch($action) {
		case "getpost":
			return new GetPostController();
		case "login":
			return new LoginController();
		case "logout":
			return new LogoutController();
		default:
			return new IndexController();
		}
	}
}
