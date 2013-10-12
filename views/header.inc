<?php
$session = new Session();
$userId = $session->getValue('logged_in');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
<head>
<title>Doxen<?=(isset($title) ? " - " . $title : "")?></title>
<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.0/jquery.min.js"></script>
<script type="text/javascript"></script>
<style type="text/css" title="currentStyle" media="screen">
@import "/css/main.css";
</style>
</head>
<body>
	<div id="header">
		<div id="logo">
			<a href="/">Doxen</a>
		</div>
		<div id="loginContainer"><?=$loginView?></div>
		<?php if(isset($defaultTopics)) { ?>
		<div id="defaultTopics">
			<ul>
			<?php foreach($defaultTopics as $topic) { ?>
				<li><a href="/?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a></li>
			<?php } ?>
			</ul>
		</div>
		<?php } ?>
	</div>