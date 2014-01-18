<?php if (!empty($commentData['fileData']) && !is_null($commentData['fileData'])) { ?>
<div class="postAttachments">
<ul>
	<?php foreach($commentData['fileData'] as $file) { ?>
	<li><a href="/?a=files&id=<?=$file['file_id']?>&force=1"><img src="images/icons/<?=$file['icon']?>.png" /></a> <a href="/?a=files&id=<?=$file['file_id']?>" target="_blank"><?=$file['name']?></a></li>
	<?php } ?>
</ul>
</div>
<? } ?>