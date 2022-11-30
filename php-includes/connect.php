<?php
define('DB_USER', 'aimedidierm');
define('DB_PASS', 'MUdidier@123');
define('DB_HOST', 'localhost');
define('DB_NAME', 'smart_menu_information_and_ordering_system');
$db = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER, DB_PASS);
if (!is_null($db->errorCode())) {
	die("Not Connected");
	exit();
}
?>