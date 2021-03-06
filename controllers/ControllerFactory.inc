<?php

class ControllerFactory {

	public function create() {
		$form = new Form();
		$action = $form->get("a");
		switch ($action) {
			case "files":
				return new FilesController();
			case "notifications":
				return new NotificationsController();
			case "removesubtopic":
				return new RemoveSubTopicController();
			case "addsubtopic":
				return new AddSubTopicController();
			case "submitregister":
				return new SubmitRegisterController();
			case "register":
				return new RegisterController();
			case "submiteditcomment":
				return new SubmitEditCommentController();
			case "submitpreferences":
				return new SubmitUserPreferencesController();
			case "user":
				return new UserController();
			case "preferences":
				return new UserPreferencesController();
			case "submiteditpost":
				return new SubmitEditPostController();
			case "editpost":
				return new EditPostController();
			case "changesubscription":
				return new ChangeSubscriptionController();
			case "subscribe":
				return new SubscribeController();
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
