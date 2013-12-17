<?=$header?>
<div id="contentContainer">
<div id="content">
<form method="POST" action="/?a=submittopicsettings&id=<?=$topicData['topic_id']?>">
<label for="topicDescription">Topic Description:</label><textarea id="topicDescription" name="topicDescription"><?=$topicData['description']?></textarea>
	<br />
	<label for="topicSidebar">Topic Sidebar:</label><textarea id="topicSidebar" name="topicSidebar"><?=$topicData['sidebar']?></textarea><br />
	<input type="submit" value="Save Changes" />
</form>
Owner: <?=$owner['display_name']?>
<form method="POST" action="/?a=submittopicsettings&id=<?=$topicData['topic_id']?>">
	Moderators: 
	<?php if (count($moderators) == 0) { ?>
	No moderators
	<? } else { ?>
	<ul>
	<?php foreach($moderators as $moderatorData) { ?>
		<li><?=$moderatorData['display_name']?></li>
		<?php } ?> 
	 </ul>
	<?php }?>
	 <br />
	<label for="addTopicModerator">New Moderator:</label><input type="text" id="addTopicModerator" name="addTopicModerator"/><br />
	<input type="submit" value="Add moderator" />
</form>
<form method="POST" action="/?a=addsubtopic&id=<?=$topicData['topic_id']?>">
Topic subscriptions: 
	<?php if (count($subtopics) == 0) { ?>
	No topics
	<? } else { ?>
	<ul>
	<?php foreach($subtopics as $subtopic) { ?>
		<li><?=$subtopic['display_name']?></li>
		<?php } ?>
	 </ul>
	<?php }?>
	 <br />
	<label for="addSubtopic">New Topic:</label><input type="text" id="addSubtopic" name="addSubtopic"/><br />
	<input type="submit" value="Add Topic" />
</form>
</div>
</div>
<?php include "topicSidebarView.inc"; ?>
</html>
