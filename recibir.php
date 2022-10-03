<?php

$usuario = "root";
$contrasena = "";
$servidor = "localhost";
$basededatos = "lampara";

$conexion = mysqli_connect($servidor, $usuario, "") or die("No se ha podido conectar al servidor de Base de datos");

$db = mysqli_select_db($conexion, $basededatos) or die("No se ha podido seleccionar la base de datos");

$prendido = $_GET ['prendido'];
$reposo = $_GET ['reposo'];
$brillo = $_GET ['brillo'];
$r = $_GET ['r'];
$g = $_GET ['g'];
$b = $_GET ['b'];

$queryModificar = "UPDATE `datos_lampara` SET `prendido` = $prendido, `reposo` = $reposo, `brillo` = $brillo, `r` = $r, `g` = $g, `b` = $b WHERE 1";

$resultModificar = mysqli_query ($conexion, $queryModificar);

if ($resultModificar){
    header('location:index.php');
}
?>