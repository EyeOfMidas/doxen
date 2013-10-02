<?php include "header.php"; ?>
<div id="pageBody">
	<div id="content">
		<div id="posts"><?=$postsView?></div>
	</div>
	<div id="sidebar">
	<?php if($userId) { ?>
	<a href="/?a=createtopic">Create a new topic</a>
	<br />
	<a href="/?a=createpost">Create a new post</a>
	<?php } ?>
	</div>
</div>
</body>
</html>

