<?php include "header.php"; ?>
<div id="pageBody">
	<div id="content">
		<h1><a href="?a=topic&id=<?=$topicData['topic_id']?>"><?=$title?></a></h1>
		<div id="posts"><?=$postView?></div>
	</div>
	<div id="sidebar">
<?php if($userId) { ?>
<div id="createPostContainer">
			<a href="/?a=createpost&t=<?=$topicData['topic_id']?>">Create a new post</a>
		</div>
<?php } ?>
</div>
</div>
</body>
</html>
