<?php
class CreateTopicController implements IController {
	
	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		$view = new View();
		
		$loginViewDecider = new LoginViewDecider();
		
		$topicModel = new TopicModel();;
		$defaultTopics = $topicModel->getDefaultTopics();
		
		$viewData = array(
			"loginView" => $loginViewDecider->decide()
			,'defaultTopics' => $defaultTopics
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