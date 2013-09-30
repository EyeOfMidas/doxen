<?php
class CreatePostController implements IController {
	
	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		$view = new View();
		$loginViewDecider = new LoginViewDecider();
		$form = new Form();
		$sql = sprintf("SELECT * FROM topics WHERE topic_id = '%s'", $form->getDefaulted('t', 0));
		$database = new Database();
		$currentTopic = $database->query($sql);
		$currentTopic = $currentTopic[0];
		
		$viewData = array(
			"loginView" => $loginViewDecider->decide()
			,"tag" => $currentTopic['display_name']
		);
		
		if($userId){
			$user = new User();
			$user->populate();
			return $view->render("createPostView.inc", $viewData);
		} else {
			return $view->render("logInPromptView.inc",  $viewData);
		}
	}
}