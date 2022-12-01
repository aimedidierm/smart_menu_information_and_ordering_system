<?php
ini_set('display_errors',1);
ini_set('display_startup_errors',1);
error_reporting(E_ALL);
require '../php-includes/connect.php';
require 'php-includes/check-login.php';
if(isset($_POST['save'])){
    $names=$_POST['names'];
    $email=$_POST['email'];
    $phone=$_POST['phone'];
    $address=$_POST['address'];
    $password=md5($_POST['password']);
    $sql ="INSERT INTO waiter (email,names,phone,address,password) VALUES (?,?,?,?,?)";
    $stm = $db->prepare($sql);
    if ($stm->execute(array($email,$names,$phone,$address,$password))) {
        print "<script>alert('Waiter added');window.location.assign('waiter.php')</script>";

    } else{
        echo "<script>alert('Error! try again');window.location.assign('waiter.php')</script>";
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
            <div class="col-lg-12 grid-margin stretch-card">
              <div class="card">
                <div class="card-body">
                  <h4 class="card-title">Waiters</h4>
                  <div class="table-responsive pt-3">
                    <table class="table table-bordered">
                      <thead>
                      <tr>
                        <th>N</th>
                        <th>Names</th>
                        <th>Email</th>
                        <th>Phone</th>
                        <th>Address</th>
                        <th>Time</th>
                        <th></th>
                        </tr>
                      </thead>
                      <tbody>
                      <?php
                    $sql = "SELECT * FROM waiter";
                    $stmt = $db->prepare($sql);
                    $stmt->execute();
                    if ($stmt->rowCount() > 0) {
                        $count = 1;
                        while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                        ?>
                      <tr>
                        <td><?php print $count?></td>
                        <td><?php print $row['names']?></td>
                        <td><?php print $row['email']?></td>
                        <td><?php print $row['phone']?></td>
                        <td><?php print $row['address']?></td>
                        <td><?php print $row['time']?></td>
                        <td><form method="post"><button type="submit" class="btn btn-danger" id="<?php echo $row["id"];$sid=$row["id"];?>" name="delete"><span class="glyphicon glyphicon-trash"></span> Delete</button></form></td>
                    </tr>
                      </tbody>
                      <?php
                        $count++;
                        }
                    }
                    if(isset($_POST['delete'])){
                    $sql ="DELETE FROM waiter WHERE id = ?";
                    $stm = $db->prepare($sql);
                    if ($stm->execute(array($sid))) {
                        print "<script>alert('Waiter deleted');window.location.assign('waiter.php')</script>";
            
                    } else {
                        print "<script>alert('Delete fail');window.location.assign('waiter.php')</script>";
                    }
                    }
                    ?>
                    </table>
                  </div>
                </div>
              </div>
            </div>
            <!-- Circle Buttons -->
    <div class="card shadow mb-6">
        <form method="post">
        <div class="card-header py-6">
            <h6 class="m-0 font-weight-bold text-primary">Add Waiter</h6>
        </div>
        <div class="card-body">
        <div class="form-group input-group">
            <span class="input-group-addon" style="width:150px;">Names:</span>
            <input type="text" style="width:350px;" class="form-control" name="names">
        </div>
        <div class="form-group input-group">
            <span class="input-group-addon" style="width:150px;">Email:</span>
            <input type="email" style="width:350px;" class="form-control" name="email">
        </div>
        <div class="form-group input-group">
            <span class="input-group-addon" style="width:150px;">Phone:</span>
            <input type="text" style="width:350px;" class="form-control" name="phone">
        </div>
        <div class="form-group input-group">
            <span class="input-group-addon" style="width:150px;">Address:</span>
            <input type="text" style="width:350px;" class="form-control" name="address">
        </div>
        <div class="form-group input-group">
            <span class="input-group-addon" style="width:150px;">Password:</span>
            <input type="password" style="width:350px;" class="form-control" name="password">
        </div>
        <button type="submit" class="btn btn-facebook btn-block" name="save">Add seller</button>
        </div>
        </form>
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