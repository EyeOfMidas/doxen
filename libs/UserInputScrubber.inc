<?php
class UserInputScrubber {
	public function scrubString($dirtyString) {
		return htmlspecialchars($dirtyString, ENT_QUOTES, 'UTF-8');
	}
}