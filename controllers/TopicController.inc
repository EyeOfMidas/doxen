<?php
class TopicController implements IController {
	private $view;
	private $topicModel;
	private $form;
	private $postRenderer;
	private $loginViewDecider;
	private $permissionDecider;
	private $headRenderer;

	public function __construct() {
		$this->view = new View();
		$this->topicModel = new TopicModel();
		$this->form = new Form();
		$this->postRenderer = new PostRenderer();
		$this->loginViewDecider = new LoginViewDecider();
		$this->permissionDecider = new PermissionDecider();
		$this->headRenderer = new HeadRenderer();
	}

	public function execute() {
		$topicId = $this->form->getCleanDefaulted("id", 0);
		$page = $this->form->getCleanDefaulted("c", 0);
		
		$currentTopic = $this->topicModel->getCurrentTopic($topicId);
		$defaultTopics = $this->topicModel->getUserTopics();
		
		$topicAccess = $this->permissionDecider->hasTopicAccess($topicId);
		
		$topicViewData = array(
			"header" => $this->headRenderer->render(),
			"title" => $currentTopic['display_name'],
			"topicData" => $currentTopic,
			"postView" => $this->postRenderer->getPostsInTopic($topicId, $page),
			'topicAccess' => $topicAccess
		);
		
		return $this->view->render("topicView.inc", $topicViewData);
	}
}
