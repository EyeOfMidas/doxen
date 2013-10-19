<?php
class PostController implements IController {

	public function execute() {
		$view = new View();
		$form = new Form();
		$postModel = new PostModel();
		$loginViewDecider = new LoginViewDecider();
		$topicModel = new TopicModel();
		$commentsRenderer = new CommentsRenderer();
		$permissionDecider = new PermissionDecider();
		$headRenderer = new HeadRenderer();
		$user = new User();
		
		$user->populate();
		
		$postId = $form->getCleanDefaulted("id", 0);
		$topicId = $form->getCleanDefaulted("t", 0);
		
		$currentPost = $postModel->getPost($postId);
		
		$defaultTopics = $topicModel->getUserTopics();
		$currentTopic = $topicModel->getCurrentTopic($topicId);
		
		
		$postViewData = array(
			"header" => $headRenderer->render(),
			"postData" => $currentPost,
			"commentView" => $commentsRenderer->getTopLevelComments($postId),
			'topicData' => $currentTopic,
			'topicAccess' => $permissionDecider->hasTopicAccess($topicId),
			'user' => $user
		);
		
		return $view->render("postPageView.inc", $postViewData);
	}
}
