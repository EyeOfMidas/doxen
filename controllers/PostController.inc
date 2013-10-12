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
		
		$postId = $form->getCleanDefaulted("id", 0);
		$topicId = $form->getCleanDefaulted("t", 0);
		
		$currentPost = $postModel->getPost($postId, $topicId);
		$postTopics = $postModel->getPostTopics($postId);
		
		$defaultTopics = $topicModel->getUserTopics();
		$currentTopic = $topicModel->getCurrentTopic($topicId);
		
		$postViewData = array(
			"header" => $headRenderer->render(),
			"postData" => $currentPost,
			"commentView" => $commentsRenderer->getTopLevelComments($postId, $topicId),
			'postTopics' => $postTopics,
			'topicData' => $currentTopic,
			'topicAccess' => $permissionDecider->hasTopicAccess($topicId)
		);
		
		return $view->render("postPageView.inc", $postViewData);
	}
}
