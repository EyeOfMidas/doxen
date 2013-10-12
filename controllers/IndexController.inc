<?php

class IndexController implements IController {

	private $view;
	private $form;
	private $headRenderer;
	private $postRenderer;
	
	public function __construct() {
		$this->view = new View();
		$this->form = new Form();
		$this->headRenderer = new HeadRenderer();
		$this->postRenderer = new PostRenderer();
	}
	
	public function execute() {
		$page = $this->form->getCleanDefaulted("c", 0);
		
		$viewData = array(
			"header" => $this->headRenderer->render(),
			"postsView" => $this->postRenderer->getPostsInUserTopics($page)
		);
		return $this->view->render("indexView.inc", $viewData);
	}
}
