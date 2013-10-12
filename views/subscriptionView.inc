<?php include "header.inc"; ?>
<div id="pageBody">
	<div id="content">
		<ul>
		<?php foreach($topics as $topic) { ?>
			<li><input class="subscribe" data-id="<?=$topic['topic_id']?>" type="checkbox" <?=$topic['subscribed'] ? 'checked="checked"' : ""?>/><a href="?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a> - <?=$topic['description']?></li>
		<?php } ?>
		</ul>
	</div>
	<?php include "sidebar.inc"; ?>
</div>
<script type="text/javascript">
$(document).ready(function(){
	$('.subscribe').click(function(){
		var checkbox = $(this);
		var topicId = checkbox.data('id');
		if(checkbox.is(':checked')) {
			console.log('subscribe to ' + topicId);
		} else {
			console.log('unsubscribe from ' + topicId);
		}
	});
});
</script>
</body>
</html>

