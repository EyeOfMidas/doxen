<?php
class HumanReadableTime {
	
	private $tokens;
	private $time;

	public function __construct() {
		$this->tokens = array (
        		31536000 => 'year',
	        	2592000 => 'month',
	        	604800 => 'week',
		        86400 => 'day',
        		3600 => 'hour',
		        60 => 'minute',
        		1 => 'second'
		);
		$this->time = new Time();
	}

	public function formatString($timestampString) {
		$timeDifference  = $this->time->now() - strtotime($timestampString);

		if ($timeDifference > 0) {
			return $this->getLargestUnit($timeDifference, "ago");
		} else if ($timeDifference < 0){
			$timeDifference = abs($timeDifference);
			return $this->getLargestUnit($timeDifference, "in the future");
			
		} else {
			return "now";
		}
	}

	private function getLargestUnit($timeDifference, $postfixString) {
		foreach ($this->tokens as $unit => $text) {
			if ($timeDifference >= $unit) {
				$numberOfUnits = floor($timeDifference / $unit);
				return $numberOfUnits.' '.$text.(($numberOfUnits>1)?'s':'') . ' ' . $postfixString;
			}
    		}
	}
}
