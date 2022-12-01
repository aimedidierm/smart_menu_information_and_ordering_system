<?php
ini_set('display_errors',1);
ini_set('display_startup_errors',1);
error_reporting(E_ALL);
require '../php-includes/connect.php';
require 'php-includes/check-login.php';
$query = "SELECT * FROM manager WHERE email= ? limit 1";
$stmt = $db->prepare($query);
$stmt->execute(array($_SESSION['email']));
$rows = $stmt->fetch(PDO::FETCH_ASSOC);
if ($stmt->rowCount()>0) {
    $names=$rows['names'];
    $email=$rows['email'];
    $address=$rows['address'];
    $phone=$rows['phone'];
}
if(isset($_POST['update'])){
$uaddress=$_POST['address'];
$uphone=$_POST['phone'];
$cpassword=md5($_POST['cpassword']);
$apassword=md5($_POST['apassword']);
if ($apassword == $cpassword){
    if($apassword == $cpassword){
        $sql ="UPDATE manager SET address = ?, phone = ? , password = ? WHERE email = ? limit 1";
        $stm = $db->prepare($sql);
        if ($stm->execute(array($uaddress, $uphone, $cpassword, $_SESSION['email']))) {
            print "<script>alert('your data updated');window.location.assign('account.php')</script>";

            }
    } else{
        echo "<script>alert('Passwords are not match');window.location.assign('account.php')</script>";
    }
} else{
    echo "<script>alert('Passwords are not match');window.location.assign('account.php')</script>";
}
}
?>
<!DOCTYPE html>
<html lang="en">

<head>
  <!-- Required meta tags -->
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <title>Smart menu information and ordering system</title>
  <!-- plugins:css -->
  <link rel="stylesheet" href="../vendors/mdi/css/materialdesignicons.min.css">
  <link rel="stylesheet" href="../vendors/base/vendor.bundle.base.css">
  <!-- endinject -->
  <!-- inject:css -->
  <link rel="stylesheet" href="../css/style.css">
  <!-- endinject -->
  <link rel="shortcut icon" href="../images/favicon.png" />
</head>

<body>
  <div class="container-scroller">
    <!-- partial:../partials/_navbar.html -->
    <?php require 'php-includes/nav.php';?>
      <!-- partial -->
      <div class="main-panel">
        <div class="content-wrapper">
          <div class="row">
          <div class="col-md-12 grid-margin stretch-card">
              <div class="card">
                <div class="card-body">
                  <h4 class="card-title">Update your data</h4>
                  <form class="forms-sample" method="POST">
                  <div class="form-group input-group">
                <span class="input-group-addon" style="width:150px;">Names:</span>
                <input type="text" style="width:350px;" class="form-control" name="names" value="<?php echo $names;?>" disabled>
                </div>
                <div class="form-group input-group">
                    <span class="input-group-addon" style="width:150px;">Email:</span>
                    <input type="text" style="width:350px;" class="form-control" name="email" value="<?php echo $email;?>" disabled>
                </div>
                <div class="form-group input-group">
                    <span class="input-group-addon" style="width:150px;">Phone:</span>
                    <input type="text" style="width:350px;" class="form-control" name="phone" value="<?php echo $phone; ?>">
                </div>
                <div class="form-group input-group">
                    <span class="input-group-addon" style="width:150px;">Address:</span>
                    <input type="text" style="width:350px;" class="form-control" name="address" value="<?php echo $address; ?>">
                </div>
                <div class="form-group input-group">
                    <span class="input-group-addon" style="width:150px;">Password:</span>
                    <input type="password" style="width:350px;" class="form-control" name="apassword" required>
                </div>
                <div class="form-group input-group">
                    <span class="input-group-addon" style="width:150px;">Confirm password:</span>
                    <input type="password" style="width:350px;" class="form-control" name="cpassword" required>
                </div>
                    <button type="submit" name="update" class="btn btn-primary me-2">Update</button>
                    <button class="btn btn-light">Cancel</button>
                  </form>
                </div>
              </div>
            </div>
          </div>
        </div>
        <!-- content-wrapper ends -->
        <!-- partial:../partials/_footer.html -->
        <?php require 'php-includes/footer.php';?>
        <!-- partial -->
      </div>
      <!-- main-panel ends -->
    </div>
    <!-- page-body-wrapper ends -->
  </div>
  <!-- container-scroller -->
  <!-- plugins:js -->
  <script src="../vendors/base/vendor.bundle.base.js"></script>
  <!-- endinject -->
  <!-- Plugin js for this page-->
  <!-- End plugin js for this page-->
  <!-- inject:js -->
  <script src="../js/off-canvas.js"></script>
  <script src="../js/hoverable-collapse.js"></script>
  <script src="../js/template.js"></script>
  <!-- endinject -->
  <!-- Custom js for this page-->
  <!-- End custom js for this page-->
</body>
</html>
