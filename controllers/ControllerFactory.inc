<?php
class ControllerFactory {
	public function create() {
		$form = new Form();
		$action = $form->get("a");
		switch($action) {
			case "submitnewtopic":
				return new SubmitNewTopicController();
			case "createtopic":
				return new CreateTopicController();
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
