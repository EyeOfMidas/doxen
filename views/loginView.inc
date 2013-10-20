<?php 
if(isset($message)) {?>
<span class="alert"><?=$message?></span>
<?php } ?>
<form method="post" action="?a=login">
	<input type="text" id="username" name="username" value="<?=isset($username) ? $username : ""?>" />
	<input type="password" id="password" name="password" value="" />
	<input type="submit" id="login" value="Login" />
</form>
<div style="font-size:10px;">
<a href="#">Forgot password?</a>
<a href="?a=register">New user?</a>
</div>

