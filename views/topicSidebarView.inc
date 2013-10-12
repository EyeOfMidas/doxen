<div id="sidebar">
	<h2><?=$topicData['display_name']?></h2>
	<h3><?=$topicData['description']?></h3>
	<a href="/?a=createpost&t=<?=$topicData['topic_id']?>">Create a new post</a>
	<div id="topicSidebar"><?=$topicData['sidebar']?></div>
<?php if($topicAccess) { ?>
	<a href="/?a=topicmanagement&id=<?=$topicData['topic_id']?>">Change topic settings</a>
<?php } ?>
<br /> <a href="/?a=subscribe">View all topics</a>
</div>