<?php
class Database {
	private $mysqli;
	public function __construct() {
		$this->mysqli = new mysqli(MYSQLI_SERVER, MYSQLI_USER, MYSQLI_PASS, MYSQLI_DB);
		if($this->mysqli->connect_error) {
			throw new DatabaseConnectionException("Unable to connect");
		}
	}

	public function query($sql) {
		$mysqliResult = $this->mysqli->query($sql);
		if($mysqliResult === true) {
			return true;
		}
		$result = array();
		if($mysqliResult->num_rows == 0) {
			return $result;
		}
		while($row = $mysqliResult->fetch_assoc()) {
			$result[] = $row;
		}
		$mysqliResult->close();
		return $result;
	}

	public function write($sql) {
		$this->mysqli->query($sql);
		return $this->mysqli->insert_id;
	}


}

class DatabaseConnectionException extends Exception {}
class DatabaseResultException extends Exception {}
