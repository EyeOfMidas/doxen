<?php include "header.inc"; ?>
<div id="content">
<form method="POST" action="/?a=submittopicsettings">
<label for="topicDescription">Topic Description:</label><textarea id="topicDescription" name="topicDescription"></textarea>
	<br />
	<label for="topicSidebar">Topic Sidebar:</label><textarea id="topicSidebar" name="topicSidebar"></textarea><br />
	[owner]<br />
	[list of moderators]<br />
	<label for="addTopicModerator">New Moderator:</label><input type="text" id="addTopicModerator" name="addTopicModerator"/><br />
	<input type="submit" value="Save Changes" />
</form>
</div>
</html>
