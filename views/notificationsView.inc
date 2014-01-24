<?=$header?>
<div id="contentContainer">
	<div id="content">
		<div id="notifications">
		<?php foreach($unreadTags as $tag) { ?>
		<?php if(isset($tag['commentData'])) { 
		$commentData =$tag['commentData'];
			include "singleCommentView.inc";
		} else if(isset($tag['postData'])) {
		$postData = $tag['postData'];
		include "singlePostView.inc";
			}
		} ?>
		</div>
	</div>
</div>
</body>
<script type="text/javascript">
$(document).ready(function() {	
});
</script>
</html>

