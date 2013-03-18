<?php
$humanReadableTime = new HumanReadableTime(); ?>
<ul>
<?php
foreach($posts as $post) {?>
<li><a href="/?a=post&id=<?=$post['post_id']?>"><?=$post['name']?></a> submitted <?=$humanReadableTime->formatString($post['timestamp'])?> by <?=$post['display_name']?></li>
<?php } ?>
</ul>
<!-- <?php var_dump($posts); ?> -->
