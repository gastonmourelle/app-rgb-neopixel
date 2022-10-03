<?php

$usuario = "root";
$contrasena = "";
$servidor = "localhost";
$basededatos = "lampara";

$conexion = mysqli_connect ($servidor, $usuario, "") or die ("No se ha podido conectar al servidor de Base de datos");

$db = mysqli_select_db ($conexion, $basededatos) or die ("No se ha podido seleccionar la base de datos");

$consulta = "SELECT * FROM datos_lampara";

$resultado = mysqli_query ($conexion, $consulta);

while($fila = mysqli_fetch_array($resultado)){
    echo "pr=".$fila ['prendido'].";";
    echo "re=".$fila ['reposo'].";";
    echo "br=".$fila ['brillo'].";";
    echo "cr=".$fila ['r'].";";
    echo "cg=".$fila ['g'].";";
    echo "cb=".$fila ['b'].";";
}

//echo $resultado;
//echo $resultadoPrendido;

?>