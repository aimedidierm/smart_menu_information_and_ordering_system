<?php 
session_start();
require 'php-includes/connect.php';
extract($_POST);
$password=md5($password);
$query = "SELECT id, email, password FROM manager WHERE email= ? AND password = ? limit 1";
$stmt = $db->prepare($query);
$stmt->execute(array($email, $password));
$rows = $stmt->fetch(PDO::FETCH_ASSOC);
if ($stmt->rowCount()>0) {
	$_SESSION['email'] = $email;
	$_SESSION['id'] = session_id();
	$_SESSION['login_type'] = "manager";
	echo "<script>window.location.assign('manager/orders.php')</script>";
}
$query = "SELECT id, email, password FROM admin WHERE email= ? AND password = ? limit 1";
$stmt = $db->prepare($query);
$stmt->execute(array($email, $password));
$rows = $stmt->fetch(PDO::FETCH_ASSOC);
if ($stmt->rowCount()>0) {
	$_SESSION['email'] = $email;
	$_SESSION['id'] = session_id();
	$_SESSION['login_type'] = "boss";
	echo "<script>window.location.assign('boss/managers.php')</script>";
}else{
	echo "<script>alert('Your ID or Password is Wrong');window.location.assign('index.php')</script>";
}
?>