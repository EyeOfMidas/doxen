<?php
class UserController implements IController {

	public function execute() {
		$form = new Form();
		$userId = $form->getCleanDefaulted('id', 0);
		$view = new View();
		
		$postRenderer = new PostRenderer();
		$postsView = $postRenderer->getPostsByUser($userId);
		
		// TODO: get both posts and comments, arrange them by date and display them together
		
		$headRenderer = new HeadRenderer();
		$viewData = array(
			'postsView' => $postsView,
			'header' => $headRenderer->render()
		);
		return $view->render('userPage.inc', $viewData);
	}
}