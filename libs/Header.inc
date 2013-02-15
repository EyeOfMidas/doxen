<?php
class Header {
    public function set404() {
        header('HTTP/1.0 404 Not Found');
    }
}
