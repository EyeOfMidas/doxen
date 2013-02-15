if(DOXEN == undefined) {
	var DOXEN = {};
}

DOXEN.instance = {};

DOXEN.init = function() {
	$.getScript("/js/LoginHandler.js", function(){
		DOXEN.instance.loginHandler = new DOXEN.LoginHandler($("#loginContainer"));
	});
};

