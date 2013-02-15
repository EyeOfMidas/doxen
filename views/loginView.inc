<input type="username" id="username" />
<input type="password" id="password" />
<input type="submit" id="login" />		
<script type="text/javascript">
	$("#login").click(function() {
		var loginData = {
			"username" : $("#username").val()
			, "password" : $("#password").val()
		};
		$.post("/?a=login", loginData, DOXEN.instance.loginHandler.loginResult, "json");
	});
</script>

