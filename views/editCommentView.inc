<div id="addComment">
	Commenting as: <?=$user->getDisplayName()?>
	<form method="POST" action="?a=submiteditcomment&id=<?=$commentData['comment_id']?>" enctype="multipart/form-data">
		<textarea name="commentBody"><?=$commentData['content']?></textarea>
		<br />
		<?php //include "commentAttachmentsView.inc"?>
		<label for="attachment1">Upload Attachment:</label><input type="file" name="attachment1" id="attachment1" />
		<br />
		<input type="submit" name="submit" value="Save changes" />
	</form>
</div>