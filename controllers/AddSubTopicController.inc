<?php
class AddSubTopicController implements IController {
	public function execute() {
		//TODO: only admin, owner, moderator can see this page
		$form = new Form();
		$topicId = $form->getCleanDefaulted('id', 0);
		$topicName = $form->getCleanDefaulted('addSubtopic', "");
		
		//convert name into topic id
		//if valid topic id, add to topic_topic_associations table
		
			
		$header = new Header();
		$header->redirect('?a=topicmanagement&id=' . $topicId);
	}
}