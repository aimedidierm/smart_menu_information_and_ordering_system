<?php
ini_set('display_errors',1);
ini_set('display_startup_errors',1);
error_reporting(E_ALL);
require 'php-includes/connect.php';
include_once("vendor/autoload.php");
use Yvesniyo\IntouchSms\SmsSimple;
/** @var \Yvesniyo\IntouchSms\SmsSimple */
$query = "SELECT * FROM waiter limit 1";
$stmt = $db->prepare($query);
$stmt->execute();
$rows = $stmt->fetch(PDO::FETCH_ASSOC);
if ($stmt->rowCount()>0) {
    $telephone=$rows['phone'];
}
$query = "SELECT * FROM chief limit 1";
$stmt = $db->prepare($query);
$stmt->execute();
$rows = $stmt->fetch(PDO::FETCH_ASSOC);
if ($stmt->rowCount()>0) {
    $telephone2=$rows['phone'];
}
if(isset($_POST['order'])){
    //order sample codes here
    $food=$_POST['order'];
    $price=$_POST['price'];
    $sql ="INSERT INTO orders (table_name,orders,price) VALUES ('Table 1',?,?)";
    $stm = $db->prepare($sql);
    if ($stm->execute(array($food,$price))) {
        $messi="Client on Table 1 wants ".$food;
        $sms = new SmsSimple();
        $sms->recipients([$telephone,$telephone2])
            ->message($messi)
            ->sender("+250785063201")
            ->username("kwizerafisto")
            ->password("kwizera123")
            ->apiUrl("www.intouchsms.co.rw/api/sendsms/.json")
            ->callBackUrl("");
        print_r($sms->send());
    }

}

// Button codes here
if(isset($_POST['call'])){
$messi="Client is calling for you on table 1";
$sms = new SmsSimple();
$sms->recipients([$telephone])
    ->message($messi)
    ->sender("+250785063201")
    ->username("kwizerafisto")
    ->password("kwizera123")
    ->apiUrl("www.intouchsms.co.rw/api/sendsms/.json")
    ->callBackUrl("");
print_r($sms->send());
}
?>