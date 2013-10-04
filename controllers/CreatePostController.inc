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
		$topicId = $form->getDefaulted('t', 0);
		$currentTopic = $topicModel->getCurrentTopic($topicId);		
		$defaultTopics = $topicModel->getDefaultTopics();
		$viewData = array(
			"loginView" => $loginViewDecider->decide()
			,"tag" => !empty($currentTopic) ? $currentTopic['display_name'] : ""
			,'defaultTopics' => $defaultTopics
		);
		
		if($userId){
			return $view->render("createPostView.inc", $viewData);
		} else {
			return $view->render("logInPromptView.inc",  $viewData);
		}
	}
}