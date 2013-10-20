<?=$header?>
<div id="contentContainer">
	<div id="content">
		<form method="POST" action="/?a=submitregister">
		<label for="newUsername">Username:</label> <input type="text" id="newUsername" name="newUsername" />
		<br />
		<label for="newEmail">Email:</label> <input type="text" id="newEmail" name="newEmail" />
		<br />
		<label for="newPassword1">Password:</label> <input type="text" id="newPassword1" name="newPassword1" />
		<br />
		<label for="newPassword2">Password (again):</label> <input type="text" id="newPassword2" name="newPassword2" />
		<br />
		<input type="submit" value="Create account" />
		</form>
	</div>
</div>
<?php include "sidebar.inc"; ?>
</body>
</html>
