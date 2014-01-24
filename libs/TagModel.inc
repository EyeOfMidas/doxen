<?php
class TagModel {
	const PAGE_SIZE = 50;
	public function geAllTagsForUser($userId, $page = 0) {
	
		$sql = sprintf("SELECT ut.tag_id, ut.user_id, ut.is_seen, ut.tagged_on, ct.comment_id, pt.post_id FROM user_tags ut
			LEFT JOIN comment_tags ct ON ct.tag_id = ut.tag_id
			LEFT JOIN post_tags pt ON pt.tag_id = ut.tag_id
			WHERE ut.user_id = '%s'
			ORDER BY ut.tagged_on DESC
			LIMIT %s, %s", $userId, $page * TagModel::PAGE_SIZE, TagModel::PAGE_SIZE);
		
		$database = new Database();
		$allTagsData = $database->query($sql);
	
		$postModel = new PostModel();
		$commentModel = new CommentModel();
	
		foreach($allTagsData as $index => $tagData) {
			if($tagData['comment_id']) {
				$commentData = $commentModel->getComment($tagData['comment_id']);
				$allTagsData[$index]['commentData'] = $commentData;
			} else if($tagData['post_id']) {
				$postData = $postModel->getPost($tagData['post_id']);
				$allTagsData[$index]['postData'] = $postData;
			}
		}
		return $allTagsData;
	}
	
	public function getUnseenTagsForUser($userId, $page = 0) {
		
		$sql = sprintf("SELECT ut.tag_id, ut.user_id, ut.is_seen, ut.tagged_on, ct.comment_id, pt.post_id FROM user_tags ut
			LEFT JOIN comment_tags ct ON ct.tag_id = ut.tag_id
			LEFT JOIN post_tags pt ON pt.tag_id = ut.tag_id
			WHERE ut.user_id = '%s'
			AND ut.is_seen = 0
			ORDER BY ut.tagged_on DESC
			LIMIT %s, %s", $userId, $page * TagModel::PAGE_SIZE, TagModel::PAGE_SIZE);
		
		$database = new Database();
		$allTagsData = $database->query($sql);
		
		$postModel = new PostModel();
		$commentModel = new CommentModel();
		
		foreach($allTagsData as $index => $tagData) {
			if($tagData['comment_id']) {
				$commentData = $commentModel->getComment($tagData['comment_id']);
				$allTagsData[$index]['commentData'] = $commentData;
			} else if($tagData['post_id']) {
				$postData = $postModel->getPost($tagData['post_id']);
				$allTagsData[$index]['postData'] = $postData;
			}
		}
		return $allTagsData;
	}
	
	public function markTagDataRead(array $tagDataRead) {
		$tagIds = array();
		foreach($tagDataRead as $index => $tagData) {
			if($tagData['is_seen'] == 0) {
				$tagIds[] = $tagData['tag_id'];
			}
		}
		if(count($tagIds) > 0) {
			$sql = sprintf("UPDATE user_tags SET is_seen = 1 WHERE tag_id IN (%s)", join(",", $tagIds));
			$database = new Database();
			$database->write($sql);
		}
	}
}