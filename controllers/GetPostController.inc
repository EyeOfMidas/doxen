<?php
class GetPostController implements IController {
	public function execute() {
		$form = new Form();
		$postId = $form->post("id");

		//query db for post
		//return json data
	}
}
