<?php
class Cache {
	private $memcached;

	public function __construct() {
		if(!$this->memcached) {
			$this->memcached = new Memcached();
		}
	}

	public function connect() {
		$servers = $this->memcached->getServerList();
		if(is_array($servers)) {
			foreach($servers as $server) {
				return true;
			}
		}
		$this->memcached->addServer(MEMCACHED_SERVER, MEMCACHED_PORT);
	}

	public function get($key) {
		return $this->memcached->get($key);
	}

	public function set($key, $value, $expiration) {
		$this->memcached->set($key, $value, $expiration);
	}
}
