<?php
class FilesController implements IController {

	public function execute() {
		$form = new Form();
		$fileId = $form->getDefaulted('id', 0);
		$forceDownload = $form->getDefaulted('force', 0);
		if ($fileId == 0) {
			return;
		}
		
		$sql = sprintf("SELECT * FROM files WHERE file_id = '%s'", $fileId);
		$database = new Database();
		$fileData = $database->query($sql);
		$fileData = $fileData[0];
		$filePath = UPLOAD_PATH . $fileData['file_hash'];
		if (file_exists($filePath)) {
			header('Pragma: public');
			header('Expires: 0');
			header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
			header('Cache-Control: private', false); // required for certain browsers
			header('Content-Type: ' . $fileData['type']);
			
			if($forceDownload) {
				header('Content-Disposition: attachment; filename="'.$fileData['name'].'";');
			} else {
				header('Content-Disposition: filename="'.$fileData['name'].'";');
			}
			header('Content-Transfer-Encoding: binary');
			header('Content-Length: ' . $fileData['size']);
			readfile($filePath);
		} else {
			echo "file does not exist";
		}
	}
}