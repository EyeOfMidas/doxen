<?php include "header.inc"; ?>
<div id="pageBody">
	<div id="content">
		<ul>
		<?php foreach($topics as $topic) { ?>
			<li><?=$topic?></li>
		<?php } ?>
		</ul>
	</div>
	<?php include "sidebar.inc"; ?>
</div>
</body>
</html>

