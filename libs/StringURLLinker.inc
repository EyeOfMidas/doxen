<?php
class StringURLLinker {
	public function replaceUrlsWithLinks($string) {
		$reg_exUrl = "/(http|https|ftp|ftps)\:\/\/[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,3}(\/\S*)?/";
		if(preg_match($reg_exUrl, $string, $url)) {
			return preg_replace($reg_exUrl, '<a href="' . $url[0] . '">'.$url[0].'</a>', $string);
		} else {
			return $string;
		}
	}
	
	public function stringOnlyContainsUrl($string) {
		$reg_exUrl = "/(http|https|ftp|ftps)\:\/\/[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,3}(\/\S*)?/";
		if(preg_match($reg_exUrl, $string, $url)) {
			//string contains a url. Is it the only content?
			return $string == $url[0];
		}
		return false;
	}
}