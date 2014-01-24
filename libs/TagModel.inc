<?php
class TagModel {
	public function getUnseenTagsForUser($userId, $page = 0) {
		
		$sql = sprintf("SELECT ut.tag_id, ut.user_id, ut.is_seen, ut.tagged_on, ct.comment_id, pt.post_id FROM user_tags ut
			LEFT JOIN comment_tags ct ON ct.tag_id = ut.tag_id
			LEFT JOIN post_tags pt ON pt.tag_id = ut.tag_id
			WHERE ut.user_id = '%s'
			AND ut.is_seen = 0
			ORDER BY ut.tagged_on DESC", $userId);
		
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
}