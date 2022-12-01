<?php
$sql = "SELECT *  FROM admin WHERE email = ? limit 1";
$stmt = $db->prepare($sql);
$stmt->execute(array($_SESSION['email']));
$row = $stmt->fetch(PDO::FETCH_ASSOC);
$names=$row['names'];
?>
<nav class="navbar col-lg-12 col-12 p-0 fixed-top d-flex flex-row">
      <div class="navbar-brand-wrapper d-flex justify-content-center">
        <div class="navbar-brand-inner-wrapper d-flex justify-content-between align-items-center w-100">  
          <button class="navbar-toggler navbar-toggler align-self-center" type="button" data-toggle="minimize">
            <span class="mdi mdi-sort-variant"></span>
          </button>
        </div>  
      </div>
      <div class="navbar-menu-wrapper d-flex align-items-center justify-content-end">
        <ul class="navbar-nav navbar-nav-right">
          <li class="nav-item nav-profile dropdown">
            <a class="nav-link dropdown-toggle" href="#" data-bs-toggle="dropdown" id="profileDropdown">
              <img src="../images/faces/face.jpg" alt="profile"/>
              <span class="nav-profile-name"><?php echo $names?></span>
            </a>
            <div class="dropdown-menu dropdown-menu-right navbar-dropdown" aria-labelledby="profileDropdown">
              <a class="dropdown-item" href="account.php">
                <i class="mdi mdi-settings text-primary"></i>
                Settings
              </a>
              <a class="dropdown-item" href="../php-includes/logout.php">
                <i class="mdi mdi-logout text-primary"></i>
                Logout
              </a>
            </div>
          </li>
        </ul>
        <button class="navbar-toggler navbar-toggler-right d-lg-none align-self-center" type="button" data-toggle="offcanvas">
          <span class="mdi mdi-menu"></span>
        </button>
      </div>
    </nav>
    <!-- partial -->
    <div class="container-fluid page-body-wrapper">
      <!-- partial:../partials/_sidebar.html -->
      <nav class="sidebar sidebar-offcanvas" id="sidebar">
        <ul class="nav">
          <li class="nav-item">
            <a class="nav-link" href="orders.php">
              <i class="mdi mdi-grid-large menu-icon"></i>
              <span class="menu-title">Orders</span>
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="managers.php">
            <i class="mdi mdi-account menu-icon"></i>
              <span class="menu-title">Managers</span>
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="account.php">
              <i class="mdi mdi-settings menu-icon"></i>
              <span class="menu-title">Profile</span>
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="../php-includes/logout.php">
              <i class="mdi mdi-logout menu-icon"></i>
              <span class="menu-title">Logout</span>
            </a>
          </li>
        </ul>
      </nav>