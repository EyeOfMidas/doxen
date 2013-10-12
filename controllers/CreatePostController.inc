<?php

class CreatePostController implements IController {

	public function execute() {
		$session = new Session();
		$view = new View();
		$form = new Form();
		$topicModel = new TopicModel();
		$headRenderer = new HeadRenderer();
		
		$userId = $session->getValue("logged_in");
		$topicId = $form->getDefaulted('t', 0);
		
		$currentTopic = $topicModel->getCurrentTopic($topicId);
		
		$viewData = array(
			"header" => $headRenderer->render(),
			"tag" => ! empty($currentTopic) ? $currentTopic['display_name'] : ""
		);
		
		if ($userId) {
			return $view->render("createPostView.inc", $viewData);
		} else {
			return $view->render("logInPromptView.inc", $viewData);
		}
	}
}