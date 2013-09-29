<?php
class LogoutController implements IController {
	public function execute() {
		$view = new View();
		$session = new Session();
		$session->clear();
		$header = new Header();
		$header->redirect("/");
	}
}
