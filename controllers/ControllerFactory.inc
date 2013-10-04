<?php

class ControllerFactory {

	public function create() {
		$form = new Form();
		$action = $form->get("a");
		switch ($action) {
			case "submittopicsettings":
				return new SubmitTopicSettingsController();
			case "topicmanagement":
				return new TopicManagementController();
			case "commentreplies":
				return new CommentRepliesController();
			case "submitnewcomment":
				return new SubmitNewCommentController();
			case "submitnewtopic":
				return new SubmitNewTopicController();
			case "submitnewpost":
				return new SubmitNewPostController();
			case "createtopic":
				return new CreateTopicController();
			case "createpost":
				return new CreatePostController();
			case "login":
				return new LoginController();
			case "logout":
				return new LogoutController();
			case "topic":
				return new TopicController();
			case "post":
				return new PostController();
			case "index":
			default:
				return new IndexController();
		}
	}
}
