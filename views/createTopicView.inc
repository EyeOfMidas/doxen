<?=$header?>
<div id="contentContainer">
	<div id="content">
		<form method="POST" action="/?a=submitnewtopic">
			<label for="name">Topic name:</label><input type="text" name="name" id="name" />
			<br />
			<input type="submit" value="Create Topic" />
		</form>
	</div>
</div>
<?php include "sidebar.inc"; ?>
</html>
