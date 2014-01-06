<?php
class AddSubTopicController implements IController {
	public function execute() {
		//TODO: only admin, owner, moderator can see this page
		$form = new Form();
		$topicId = $form->getCleanDefaulted('id', 0);
		$topicName = $form->postCleanDefaulted('addSubtopic', "");
		$topicModel = new TopicModel();
		$subscribingTopicId = $topicModel->getIdForTopicName($topicName);
		if($subscribingTopicId != 0 && $subscribingTopicId != $topicId) {
			$sql = sprintf("INSERT INTO topic_topic_associations (topic_id, subtopic_id) VALUES (%s, %s)", $topicId, $subscribingTopicId);
			$database = new Database();
			$database->write($sql);
		}
			
		$header = new Header();
		$header->redirect('?a=topicmanagement&id=' . $topicId);
	}
}