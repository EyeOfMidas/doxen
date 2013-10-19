<?php
class UserController implements IController {
	public function execute() {
		$form = new Form();
		$userId = $form->getCleanDefaulted('id', 0);
		$view = new View();
		
		$headRenderer = new HeadRenderer();
		$viewData = array(
			'header' => $headRenderer->render()
		);
		return $view->render('userPage.inc', $viewData);
	}
}