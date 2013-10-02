<?php
class CreatePostController implements IController {
	
	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		$view = new View();
		$loginViewDecider = new LoginViewDecider();
		$form = new Form();
		
		$topicModel = new TopicModel();
		$currentTopic = $topicModel->getCurrentTopic($form->getDefaulted('t', 0));		
		$defaultTopics = $topicModel->getDefaultTopics();
		
		$viewData = array(
			"loginView" => $loginViewDecider->decide()
			,"tag" => $currentTopic['display_name']
			,'defaultTopics' => $defaultTopics
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