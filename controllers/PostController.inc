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
		$notificationScraper = new NotificationScraper();
		
		$user->populate();
		
		$postId = $form->getCleanDefaulted("id", 0);
		$topicId = $form->getCleanDefaulted("t", 0);
		
		$currentPost = $postModel->getPost($postId);
		$taggedContent = $notificationScraper->replaceNotificationsWithLinks($currentPost['content']);
		$currentPost['content'] = htmlspecialchars_decode($taggedContent);
		$user->markPostViewed($postId);
		
		$defaultTopics = $topicModel->getUserTopics();
		$currentTopic = $topicModel->getCurrentTopic($topicId);
		
		$sql = sprintf("SELECT f.* FROM files f
			JOIN post_file_associations pfa ON f.file_id = pfa.file_id
			WHERE pfa.post_id = '%s'", $postId);
		$database = new Database();
		$fileData = $database->query($sql);
		foreach($fileData as $index => $file) {
			$fileComponents = explode('.', $file['name']);
			$fileData[$index]['icon'] = $fileComponents[count($fileComponents)-1];
		}
		
		
		$postViewData = array(
			"header" => $headRenderer->render(),
			"postData" => $currentPost,
			"fileData" => $fileData,
			"commentView" => $commentsRenderer->getTopLevelComments($postId),
			'topicData' => $currentTopic,
			'topicAccess' => $permissionDecider->hasTopicAccess($topicId),
			'user' => $user
		);
		
		return $view->render("postPageView.inc", $postViewData);
	}
}
