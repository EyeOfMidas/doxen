DOXEN.LoginHandler = function(loginContainer) {
	this.loginResult = function(result) {
		loginContainer.html(result.html);
		console.log(result);
	};

};
