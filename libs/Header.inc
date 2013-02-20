<?php
class Header {
    public function setPageNotFound() {
        header('HTTP/1.0 404 Not Found');
    }
    
    public function setNotLoggedIn() {
    	header('HTTP/1.0 401 Unauthorized');
    }
    
    public function redirect($location) {
    	header('Location: ' . $location);
    }
}
