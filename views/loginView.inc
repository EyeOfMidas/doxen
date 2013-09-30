<?php 
if(isset($message)) {?>
<span class="alert"><?=$message?></span>
<?php } ?>
<form method="post" action="?a=login">
	<input type="username" id="username" name="username" value="<?=isset($username) ? $username : ""?>" />
	<input type="password" id="password" name="password" value="" />
	<input type="submit" id="login" value="Login" />
</form>

