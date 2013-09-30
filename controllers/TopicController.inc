<?php
class TopicController implements IController {
	public function execute() {
		$view = new View();

		$form = new Form();
		$dirtyTopicId = $form->get("id");
		$dirtyPage = $form->getDefaulted("c", 0);

		$sql = sprintf("SELECT * FROM topics WHERE topic_id = '%s'", $dirtyTopicId);
		$database = new Database();
		$currentTopic = $database->query($sql);
		$currentTopic = $currentTopic[0];
		$postRenderer = new PostRenderer($database);

		$sql = sprintf("SELECT * FROM posts WHERE parent_topic_id = '%s' ORDER BY timestamp DESC LIMIT %s, 20"
			, $dirtyTopicId
			, $dirtyPage);
		$posts = $database->query($sql);
		$postViewData = array("posts" => $posts);

		$loginViewDecider = new LoginViewDecider();

		$topicViewData = array(
			"domain" => DOMAIN
			, "title" => $currentTopic['display_name']
			, "loginView" => $loginViewDecider->decide()
			, "topicData" => $currentTopic
			, "postView" => $postRenderer->getPostsInTopic($dirtyTopicId, $dirtyPage)
		);

		return $view->render("topicView.inc", $topicViewData);
	}
}
