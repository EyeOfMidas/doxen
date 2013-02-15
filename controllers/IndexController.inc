<?php
class IndexController implements IController {
	public function execute() {
		$view = new View();
		$viewData = array();
		return $view->render("indexView.inc", $viewData);
	}
}
