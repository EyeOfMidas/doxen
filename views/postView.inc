<ul>
<?php
foreach($posts as $post) {?>
<li><a href="/?a=post&id=<?=$post['post_id']?>"><?=$post['name']?></a></li>	
<?php } ?>
</ul>
