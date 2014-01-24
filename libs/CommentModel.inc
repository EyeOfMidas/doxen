<?php
class CommentModel {
	public function getComment($commentId) {
		$commentData = array();
		$sql = sprintf("SELECT c.comment_id, c.content, c.timestamp, c.url_name, c.is_edited, cpa.post_id as parent_post_id, cua.user_id as commenter_user_id, u.display_name as display_name
				FROM comments c
			JOIN comment_user_associations cua ON c.comment_id = cua.comment_id
			JOIN comment_post_associations cpa ON c.comment_id = cpa.comment_id
			JOIN users u ON cua.user_id = u.user_id
			WHERE c.comment_id = '%s'
			LIMIT 1", $commentId);
		$database = new Database();
		$queryResult = $database->query($sql);
		$commentData = $queryResult[0];
		$commentData['content'] = htmlspecialchars_decode($commentData['content']);
		return $commentData;
	}
}