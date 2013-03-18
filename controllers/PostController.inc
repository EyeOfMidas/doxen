<?php
class PostController implements IController {
	public function execute() {
		$view = new View();

		$sql = "SELECT * FROM topics WHERE topic_id IN (SELECT topic_id FROM default_topics ORDER BY sort_order ASC)";
		$database = new Database();
		$defaultTopics = $database->query($sql);

		$sql = "SELECT * FROM posts WHERE parent_topic_id IN (SELECT topic_id FROM default_topics) ORDER BY timestamp DESC LIMIT 0, 20";
		$posts = $database->query($sql);

		$postViewData = array("posts" => $posts);
		$postView = $view->render("postView.inc", $postViewData);
		$loginViewDecider = new LoginViewDecider();
		$loginViewData = array();
		$indexViewData = array(
			"domain" => DOMAIN
			, "loginView" => $loginViewDecider->decide()
			, "postsView" => $postView
			, "defaultTopics" => $defaultTopics
		);
		return $view->render("postPageView.inc", $indexViewData);
	}
}
