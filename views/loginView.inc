<?php 
if(isset($message)) {?>
<span class="alert"><?=$message?></span>
<?php } ?>
<input type="username" id="username" value="<?=isset($username) ? $username : ""?>" />
<input type="password" id="password" value="" />
<input type="submit" id="login" value="Login" />		
<script type="text/javascript">
	$("#login").click(function() {
		var loginData = {
			"username" : $("#username").val()
			, "password" : $("#password").val()
		};
		$.post("/?a=login", loginData, DOXEN.instance.loginHandler.loginResult, "json");
	});
</script>

