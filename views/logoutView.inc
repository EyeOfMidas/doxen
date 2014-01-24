<div style="font-size: 10px;">
	<a href="?a=user&id=<?=$userId?>"><?=$username?></a>
	| <a <?=($newNotifications > 0 ? "class=\"newNotice\" " : "")?>href="?a=notifications">notifications<?=($newNotifications > 0 ? " ($newNotifications)" : "")?></a>
	| <a href="?a=preferences">preferences</a> | <a href="?a=logout">logout</a>
</div>