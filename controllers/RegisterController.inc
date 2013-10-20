<?php
class RegisterController implements IController {

	public function execute() {
		$form = new Form();
		$view = new View();
		$headRenderer = new HeadRenderer();
		
		$viewData = array(
			'header' => $headRenderer->render()
		);
		return $view->render('registerPage.inc', $viewData);
	}
}