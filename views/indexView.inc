<?php include "header.php"; ?>
	<div id="content">
	<div id="posts"><?=$postsView?></div>
	</div>	
	<div id="sidebar">
	<?php if($userId) { ?>
	<div id="createTopicContainer">
		<a href="/?a=createtopic">Create a new topic</a>
	</div>
	<?php } ?>
	</div>
</body>
</html>

