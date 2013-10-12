<?php
class CreateTopicController implements IController {
	
	public function execute() {
		$session = new Session();
		$view = new View();
		$headRenderer = new HeadRenderer();
		
		$userId = $session->getValue("logged_in");
		
		$viewData = array(
			"header" => $headRenderer->render()
		);
		if($userId){
			return $view->render("createTopicView.inc", $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}