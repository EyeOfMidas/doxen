<?php
$humanReadableTime = new HumanReadableTime(); ?>
<ul>
<?php
foreach($posts as $post) {?>
<li><a href="/?a=post&id=<?=$post['post_id']?>"><?=$post['post_name']?></a> submitted <?=$humanReadableTime->formatString($post['timestamp'])?> by <?=$post['user_display_name']?></li>
<?php } ?>
</ul>
<!-- <?php var_dump($posts); ?> -->
