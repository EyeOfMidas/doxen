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
			case "login":
				return new LoginController();
			case "logout":
				return new LogoutController();
			case "topic":
				return new TopicController();
			case "post":
				return new PostController();
			case "index":
			default:
				return new IndexController();
		}
	}
}
