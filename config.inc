<?php

define("DOMAIN", "doxen.test");

define("MYSQLI_SERVER", "localhost");
define("MYSQLI_USER", "doxen");
define("MYSQLI_PASS", "doxenpassword");
define("MYSQLI_DB", "doxen");


define("MEMCACHED_SERVER", "localhost");
define("MEMCACHED_PORT", "11211");

/* --------- Do not edit below this line --------- */
define("ROOT", dirname(__FILE__));
define("LIBROOT", ROOT . "/libs/");
define("VIEWROOT", ROOT . "/views/");
define("CONTROLLERROOT", ROOT . "/controllers/");

function doxen_autoload($class) {
	$classfile = $class . ".inc";
	$libFile = LIBROOT . $classfile;
	$controllerFile = CONTROLLERROOT . $classfile;
	if (file_exists($libFile)) {
		require_once($libFile);
	} else if (file_exists($controllerFile)) {
		require_once($controllerFile);
	}
}
spl_autoload_register("doxen_autoload");

session_start();
