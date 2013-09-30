<?php include "header.php"; ?>
<div id="content">
<div id="posts"><?=$postView?></div>
</div>
<div id="sidebar">
<?php if($userId) { ?>
<div id="createPostContainer"><a href="/?a=createpost">Create a new post</a></div>
<?php } ?>
</div>
</body>
</html>
