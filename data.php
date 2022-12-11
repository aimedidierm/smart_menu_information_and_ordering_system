<?php
if(isset($_POST['order'])){
    //order sample codes here
}

// Button codes here
if(isset($_POST['call'])){
$query = "SELECT * FROM waiter limit 1";
$stmt = $db->prepare($query);
$stmt->execute();
$rows = $stmt->fetch(PDO::FETCH_ASSOC);
if ($stmt->rowCount()>0) {
    $telephone=$rows['phone'];
}
include_once("vendor/autoload.php");
use Yvesniyo\IntouchSms\SmsSimple;
/** @var \Yvesniyo\IntouchSms\SmsSimple */
$messi="Client is calling for you on table 1";
$sms = new SmsSimple();
$sms->recipients([$telephone])
    ->message($messi)
    ->sender("+250785063201")
    ->username("kwizerafisto")
    ->password("kwizera@123")
    ->apiUrl("www.intouchsms.co.rw/api/sendsms/.json")
    ->callBackUrl("");
print_r($sms->send());
}
?>