<html>
<head>
	<title>Doxen</title>
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.0/jquery.min.js"></script>
	<script type="text/javascript"></script>
</head>
<body>
	<div id="loginContainer">
		<?=$loginView?>
	</div>
	<script type="text/javascript" src="/js/doxenInit.js"></script>
	<script type="text/javascript">
	$(document).ready(function() {
		DOXEN.init();
	});
	</script>
</body>
</html>

