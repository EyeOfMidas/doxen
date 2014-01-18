<?php if (!empty($fileData) && !is_null($fileData)) { ?>
<div id="postAttachments">
<ul>
	<?php foreach($fileData as $file) { ?>
	<li><a href="/?a=files&id=<?=$file['file_id']?>&force=1"><img src="images/icons/<?=$file['icon']?>.png" /></a> <a href="/?a=files&id=<?=$file['file_id']?>" target="_blank"><?=$file['name']?></a></li>
	<?php } ?>
</ul>
</div>
<? } ?>