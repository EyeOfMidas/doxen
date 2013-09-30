<?php
class CreateTopicController implements IController {
	
	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		$view = new View();
		
		$loginViewDecider = new LoginViewDecider();
		$viewData = array(
			"loginView" => $loginViewDecider->decide()
		);
		if($userId){
			$user = new User();
			$user->populate();
			return $view->render("createTopicView.inc", $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}