<?php

class TopicController implements IController {

	private $view;

	private $topicModel;

	private $form;

	private $postRenderer;

	private $loginViewDecider;

	private $permissionDecider;

	public function __construct() {
		$this->view = new View();
		$this->topicModel = new TopicModel();
		$this->form = new Form();
		$this->postRenderer = new PostRenderer();
		$this->loginViewDecider = new LoginViewDecider();
		$this->permissionDecider = new PermissionDecider();
	}

	public function execute() {
		$topicId = $this->form->getCleanDefaulted("id");
		$page = $this->form->getCleanDefaulted("c", 0);
		
		$currentTopic = $this->topicModel->getCurrentTopic($topicId);
		$defaultTopics = $this->topicModel->getDefaultTopics();
		
		$topicAccess = $this->permissionDecider->hasTopicAccess($topicId);
		
		$topicViewData = array(
			"domain" => DOMAIN,
			"title" => $currentTopic['display_name'],
			"loginView" => $this->loginViewDecider->decide(),
			"topicData" => $currentTopic,
			"postView" => $this->postRenderer->getPostsInTopic($topicId, $page),
			'defaultTopics' => $defaultTopics,
			'topicAccess' => $topicAccess
		);
		
		return $this->view->render("topicView.inc", $topicViewData);
	}
}
