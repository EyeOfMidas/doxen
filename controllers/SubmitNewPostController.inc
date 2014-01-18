<?php
class SubmitNewPostController implements IController {

	public function execute() {
		$header = new Header();
		$user = new User();
		$form = new Form();
		$userInputScrubber = new UserInputScrubber();
		$stringUrlLinker = new StringURLLinker();
		$tagDecoder = new TagDecoder();
		$webWrapper = new WebWrapper();
		$database = new Database();
		$notificationScraper = new NotificationScraper();
		
		$user->populate();
		$userId = $user->getId();
		
		if ($userId) {
			$title = $form->postCleanDefaulted("postTitle", "");
			$postContent = $form->postCleanDefaulted("postContent", "");
			$tags = $form->postCleanDefaulted("tags", "");
			$file = $form->file("attachment1");
			
			if ($title == "") {
				// ERROR: title required, return error
				return;
			}
			
			if ($postContent == "") {
				// ERROR: post content required, return error
				return;
			}
			
			if ($tags == "") {
				// ERROR: no tags defined
				return;
			}
			
			$postContent = $stringUrlLinker->replaceUrlsWithLinks($postContent);
			
			$tagsFound = $tagDecoder->getTagIds($tags);
			
			if (count($tagsFound) <= 0) {
				// ERROR: no tags defined, no where to post this
				return;
			}
			$topicId = $tagsFound[0];
			
			$sql = sprintf("INSERT INTO posts (poster_user_id, timestamp, name, url_name, content) 
				VALUES (%s, NOW(), '%s', '%s', '%s')", $userId, $title, $webWrapper->convertToUrl($title), $postContent);
			
			$postId = $database->write($sql);
			
			if ($postId == 0) {
				// ERROR: something went wrong with saving the post, do something here
				return;
			}
			
			if (! empty($file) && ! is_null($file)) {
				$time = new Time();
				$stringToHash = $file['name'] . $time->now() . "doxensalt" . $file['size'];
				$fileHash = sha1($stringToHash);
				
				$moveResult = move_uploaded_file($file['tmp_name'], UPLOAD_PATH . $fileHash);
				if (! $moveResult) {
					$logger = new Logger();
					$logger->error("File upload-move failed! Check permissions on " . UPLOAD_PATH);
				} else {
					$sql = sprintf("INSERT INTO files (file_hash, name, size, type) VALUES ('%s','%s','%s','%s')", $fileHash, $file['name'], $file['size'], $file['type']);
					$fileId = $database->write($sql);
					
					$sql = sprintf("INSERT INTO post_file_associations (post_id, file_id) VALUES ('%s','%s')", $postId, $fileId);
					$database->write($sql);
				}
			}
			
			$sql = "INSERT INTO post_last_updated (post_id, last_updated) VALUES (" . $postId . ", NOW())";
			$database->write($sql);
			
			$sql = "INSERT INTO post_topic_associations (post_id, topic_id) VALUES (" . $postId . "," . $topicId . ")";
			$database->write($sql);
			
			$userTagData = $notificationScraper->getUserTagDataFromString($postContent);
			foreach ($userTagData as $userId => $userTagString) {
				$sql = sprintf("INSERT INTO user_tags (user_id) VALUES ('%s')", $userId);
				$userTagId = $database->write($sql);
				$sql = sprintf("INSERT INTO post_tags (post_id, tag_id) VALUES ('%s', '%s')", $postId, $userTagId);
				$database->write($sql);
			}
			$header->redirect("/?a=post&id=" . $postId . "&t=" . $topicId);
		} else {
			$header->redirect("/");
		}
	}

	private function cleanName($newTopicName) {
		$webWrapper = new WebWrapper();
		return $webWrapper->urlEncode($newTopicName);
	}
}