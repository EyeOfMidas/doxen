<?php
$session = new Session();
$userId = $session->getValue('logged_in');
?>
<?=$header?>
<div id="contentContainer">
	<div id="content">
		<ul>
		<?php foreach($topics as $topic) { ?>
			<li><?php if($userId) {?><input class="subscribe" data-id="<?=$topic['topic_id']?>" type="checkbox" <?=$topic['subscribed'] ? 'checked="checked"' : ""?> /><?php } ?><a href="?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a> - <?=$topic['description']?></li>
		<?php } ?>
		</ul>
	</div>
</div>
	<?php include "sidebar.inc"; ?>
<script type="text/javascript">
$(document).ready(function(){
	$('.subscribe').click(function(){
		var checkbox = $(this);
		var topicId = checkbox.data('id');
		if(checkbox.is(':checked')) {
			$.ajax('?a=changesubscription&id=' + topicId + '&s=1');
		} else {
			$.ajax('?a=changesubscription&id=' + topicId + '&s=0');
		}
	});
});
</script>
</body>
</html>

