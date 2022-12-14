<?php
ini_set('display_errors',1);
ini_set('display_startup_errors',1);
error_reporting(E_ALL);
require '../php-includes/connect.php';
require 'php-includes/check-login.php';
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
                  <h4 class="card-title">User orders</h4>
                  <div class="table-responsive pt-3">
                  <table class="table table-bordered">
                      <thead>
                        <tr>
                          <th>
                            #
                          </th>
                          <th>
                            Table
                          </th>
                          <th>
                            Food
                          </th>
                          <th>
                            Deadline
                          </th>
                        </tr>
                      </thead>
                      <tbody>
                      <?php
                      $sql = "SELECT * FROM orders";
                      $stmt = $db->prepare($sql);
                      $stmt->execute();
                      if ($stmt->rowCount() > 0) {
                          $count = 1;
                          while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                          ?>
                        <tr>
                          <td><?php print $count?></td>
                          <td><?php print $row['table_name']?></td>
                          <td><?php print $row['orders']?></td>
                          <td><form method="post"><button type="submit" class="btn btn-danger" id="<?php echo $row["id"];$sid=$row["id"];?>" name="delete"><span class="glyphicon glyphicon-trash"></span> Delete</button></form></td>
                        </tr>
                        <?php
                        $count++;
                        }
                    }
                    if(isset($_POST['delete'])){
                    $sql ="DELETE FROM orders WHERE id = ?";
                    $stm = $db->prepare($sql);
                    if ($stm->execute(array($sid))) {
                        print "<script>alert('Order deleted');window.location.assign('orders.php')</script>";
            
                    } else {
                        print "<script>alert('Delete fail');window.location.assign('orders.php')</script>";
                    }
                    }
                    ?>
                      </tbody>
                    </table>
                  </div>
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
