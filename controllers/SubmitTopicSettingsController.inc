<?php
class SubmitTopicSettingsController implements IController {
	public function execute() {
		$form = new Form();
		$topicId = $form->getCleanDefaulted('id', 0);
		$topicDescription = $form->post('topicDescription');
		$topicSidebar = $form->post('topicSidebar');
		$newModeratorName = $form->post('addTopicModerator');
		var_dump($topicId);
		var_dump($topicDescription);
		var_dump($topicSidebar);
		var_dump($newModeratorName);
		
		//TODO: actually save off these values!
		
		$header = new Header();
		//$header->redirect('?a=topicmanagement&id=' . $topicId);
	}
}