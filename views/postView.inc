<ul>
<?php
foreach($posts as $post) {?>
<li><a href="/?p=<?=$post['post_id']?>"><?=$post['name']?></a></li>	
<?php } ?>
</ul>
