<?=$header?>
<div id="contentContainer">
	<div id="content">
		Settings for <?=$username?>
		<form method="POST" action="?a=submitpreferences">
		<!-- <label for="email">Email:</label> <input id="email" name="email" type="text" value="<?=$email?>" />
		<br /> -->
		<label for="displayName">Display Name:</label> <input id="displayName" name="displayName" type="text" value="<?=$displayName?>"/>
		<br />
		<input type="submit" value="Save" />
		</form>
		
		<!-- <form method="POST" action="?a=changepassword">
			<label for="oldPass">Old password:</label> <input id="oldPass" name="oldPass" type="text" />
			<br />
			<label for="newPass1">New password:</label> <input id="newPass1" name="newPass1" type="text" />
			<br />
			<label for="newPass2">New password (again):</label> <input id="newPass2" name="newPass2" type="text" />
			<br />
			<input type="submit" value="Change Password">
		</form> -->
	</div>
</div>
<?php include "sidebar.inc"; ?>
</body>
</html>
