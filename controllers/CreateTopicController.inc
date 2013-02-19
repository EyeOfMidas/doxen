<?php
class CreateTopicController implements IController {
	
	public function execute() {
		//TODO: only show this if user is logged in
		$view = new View();
		return $view->render("createTopicView.inc", array());
	}
}