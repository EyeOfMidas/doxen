<?php
class IndexController implements IController {
	public function execute() {
		$view = new View();

		$sql = "SELECT * FROM topics WHERE topic_id IN (SELECT topic_id FROM default_topics ORDER BY sort_order ASC)";
		$database = new Database();
		$defaultTopics = $database->query($sql);

		$form = new Form();
		$dirtyPage = $form->getDefaulted("c", 0);
		$postRenderer = new PostRenderer($database);

		$loginViewDecider = new LoginViewDecider();
		$loginViewData = array();
		$indexViewData = array(
			"domain" => DOMAIN
			, "loginView" => $loginViewDecider->decide()
			, "postsView" => $postRenderer->getPostsInDefaultTopics($dirtyPage)
			, "defaultTopics" => $defaultTopics
		);
		return $view->render("indexView.inc", $indexViewData);
	}
}
