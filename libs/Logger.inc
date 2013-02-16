<?php
class Logger {
	public function error($message) {
		error_log("Doxen: " . $message);
	}

	public function system($message) {
		syslog("Doxen: " . $message);
	}
}
