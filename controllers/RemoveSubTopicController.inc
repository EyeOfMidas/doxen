<?php
class RemoveSubTopicController implements IController {
	public function execute() {
		//TODO: only admin, owner, moderator can see this page
		$form = new Form();
		$topicId = $form->getCleanDefaulted('id', 0);
		$subtopicId = $form->getCleanDefaulted('subtopic', 0);
		$topicModel = new TopicModel();
		$sql = sprintf("DELETE FROM topic_topic_associations WHERE topic_id = '%s' AND subtopic_id = '%s'", $topicId, $subtopicId);
		var_dump($sql);
		$database = new Database();
		$database->write($sql);
			
		$header = new Header();
		$header->redirect('?a=topicmanagement&id=' . $topicId);
	}
}