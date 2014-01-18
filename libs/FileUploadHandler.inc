<?php
class FileUploadHandler {

	public function saveFileToPost($file, $postId, $userId) {
		if (! empty($file) && ! is_null($file)) {
			$time = new Time();
			$database = new Database();
			$logger = new Logger();
			
			$stringToHash = $file['name'] . $time->now() . "doxensalt" . $file['size'];
			$fileHash = sha1($stringToHash);
			
			$moveResult = move_uploaded_file($file['tmp_name'], UPLOAD_PATH . $fileHash);
			if (! $moveResult) {
				$logger->error("File upload-move failed! Check permissions on " . UPLOAD_PATH);
			} else {
				$sql = sprintf("INSERT INTO files (file_hash, name, size, type) VALUES ('%s','%s','%s','%s')", $fileHash, $file['name'], $file['size'], $file['type']);
				$fileId = $database->write($sql);
				
				$sql = sprintf("INSERT INTO post_file_associations (post_id, file_id) VALUES ('%s','%s')", $postId, $fileId);
				$database->write($sql);
				
				$sql = sprintf("INSERT INTO user_file_associations (user_id, file_id) VALUES ('%s','%s')", $userId, $fileId);
				$database->write($sql);
			}
		}
	}
	
	public function saveFileToComment($file, $commentId, $userId) {
		if (! empty($file) && ! is_null($file)) {
			$time = new Time();
			$database = new Database();
			$logger = new Logger();
				
			$stringToHash = $file['name'] . $time->now() . "doxensalt" . $file['size'];
			$fileHash = sha1($stringToHash);
				
			$moveResult = move_uploaded_file($file['tmp_name'], UPLOAD_PATH . $fileHash);
			if (! $moveResult) {
				$logger->error("File upload-move failed! Check permissions on " . UPLOAD_PATH);
			} else {
				$sql = sprintf("INSERT INTO files (file_hash, name, size, type) VALUES ('%s','%s','%s','%s')", $fileHash, $file['name'], $file['size'], $file['type']);
				$fileId = $database->write($sql);
	
				$sql = sprintf("INSERT INTO comment_file_associations (comment_id, file_id) VALUES ('%s','%s')", $commentId, $fileId);
				$database->write($sql);
	
				$sql = sprintf("INSERT INTO user_file_associations (user_id, file_id) VALUES ('%s','%s')", $userId, $fileId);
				$database->write($sql);
			}
		}
	}
}