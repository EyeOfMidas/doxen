<?php
class LoginViewDecider {
	public function decide() {
		$session = new Session();
		$logger = new Logger();
		$form = new Form();
		$userId = $session->getValue("logged_in");
		
		$view = new View();
		if($userId){
			$user = new User();
			$user->populate();
			
			$sql = sprintf("SELECT count(*) as count FROM user_tags WHERE is_seen = 0 AND user_id = '%s'", $user->getId());
			$database = new Database();
			$result = $database->query($sql);
			$newNotificationCount = intval($result[0]['count']);
			
			$logoutViewData = array(
				"username" => $user->getDisplayName(),
				"userId" => $userId,
				"newNotifications" => $newNotificationCount
			);
			return $view->render("logoutView.inc", $logoutViewData);
		}
		$errorMessage = $form->getCleanEncodedDefaulted("e", "");
		$loginViewData = array("message" => $errorMessage);
		return $view->render("loginView.inc", $loginViewData);
	}
}
