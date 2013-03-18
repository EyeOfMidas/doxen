<?php
class PostController implements IController {
	public function execute() {
		$view = new View();

		$form = new Form();
		$dirtyPostId = $form->get("id");

		$sql = sprintf("SELECT * FROM posts JOIN users ON user_id = poster_user_id WHERE post_id = '%s'", $dirtyPostId);
		$database = new Database();
		$currentPost = $database->query($sql);

		$loginViewDecider = new LoginViewDecider();

		$postViewData = array(
			"domain" => DOMAIN
			, "loginView" => $loginViewDecider->decide()
			, "postData" => $currentPost[0]
			, "commentView" => ""
		);

		return $view->render("postPageView.inc", $postViewData);
	}
}
