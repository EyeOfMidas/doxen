<?php
require_once("../config.inc");
$controllerFactory = new ControllerFactory();
echo $controllerFactory->create()->execute();