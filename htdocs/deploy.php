<?php
require_once "../config.inc";
exec("cd ".SOURCE_PATH.";git pull origin master;git archive master --format=tar --output=".DEPLOY_PATH."doxencode.tar");
exec("cd ".DEPLOY_PATH.";tar xvf doxencode.tar");
exec("rm ".DEPLOY_PATH."doxencode.tar");
