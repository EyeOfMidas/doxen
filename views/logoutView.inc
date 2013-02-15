<?=$username?> : <button id="logout">Log Out</button>
<script type="text/javascript">
	$("#logout").click(function() {
		var logoutData = {};
		 $.post("/?a=logout", logoutData, DOXEN.instance.loginHandler.loginResult, "json");
	});
</script>
