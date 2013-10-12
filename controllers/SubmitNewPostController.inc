<?php

class SubmitNewPostController implements IController {

	public function execute() {
		$session = new Session();
		$logger = new Logger();
		$userId = $session->getValue("logged_in");
		
		if ($userId) {
			$form = new Form();
			$title = $form->post("postTitle");
			$postContent = $form->post("postContent");
			$tags = $form->post("tags");
			
			$userInputScrubber = new UserInputScrubber();
			
			$title = $userInputScrubber->scrubString($title);
			if ($title == "") {
				//TODO: title required, return error
				return;
			}
			
			$postContent = $userInputScrubber->scrubString($postContent);
			if ($postContent == "") {
				//TODO: post content required, return error
				return;
			}
			
			$stringUrlLinker = new StringURLLinker();
			if ($stringUrlLinker->stringOnlyContainsUrl($postContent)) {
			}
			$postContent = $stringUrlLinker->replaceUrlsWithLinks($postContent);
			
			$tags = $userInputScrubber->scrubString($tags);
			
			$tagDecoder = new TagDecoder();
			$tagsFound = $tagDecoder->getTagIds($tags);

			if (count($tagsFound) <= 0) {
				//TODO: no tags defined, no where to post this
				return;
			}
			
			$webWrapper = new WebWrapper();
			$sql = sprintf("INSERT INTO posts (poster_user_id, timestamp, name, url_name, content) VALUES (%s, NOW(), '%s', '%s', '%s')",
				$userId,
				$title,
				$webWrapper->convertToUrl($title),
				$postContent
			);

			$database = new Database();
			$postId = $database->write($sql);
			
			if($postId == 0) {
				//TODO:something went wrong with saving the post, do something here
				return;
			}
			$associationValues = array();
			$sql = "INSERT INTO post_topic_associations (post_id, topic_id) VALUES ";
			foreach($tagsFound as $topicId) {
				$associationValues[] = "(".$postId.",".$topicId.")";
			}
			$sql .= implode(',', $associationValues);
			
			$database->write($sql);

			 $header = new Header();
			 
			 if(count($tagsFound) == 1) {
			 	$header->redirect("/?a=post&id=".$postId."&t=".$tagsFound[0]);
			 } else {
			 	$header->redirect("/");
			 }
		} else {
			//TODO: not logged in
		}
	}

	private function cleanName($newTopicName) {
		$webWrapper = new WebWrapper();
		return $webWrapper->urlEncode($newTopicName);
	}
}