<?php
class WebWrapper {
	
	public function urlEncode($string) {
		return urlencode($string);		
	}
	
	public function convertToUrl($string) {
		return strtolower(str_replace(' ', '-', trim($string)));
	}
}