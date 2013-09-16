<?php
class CreatePostController implements IController {
	
	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		$view = new View();
		if($userId){
			$user = new User();
			$user->populate();
			return $view->render("createPostView.inc", array());
		} else {
			return $view->render("logInPromptView.inc", array());
		}
	}
}