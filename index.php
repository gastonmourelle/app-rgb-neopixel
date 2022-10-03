<?php
$usuario = "root";
$contrasena = "";
$servidor = "localhost";
$basededatos = "lampara";

$conexion = mysqli_connect($servidor, $usuario, "") or die("No se ha podido conectar al servidor de Base de datos");

$db = mysqli_select_db($conexion, $basededatos) or die("No se ha podido seleccionar la base de datos");

$consulta = "SELECT * FROM datos_lampara";
$resultado = mysqli_query ($conexion, $consulta);
$fila = mysqli_fetch_array($resultado);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script src="https://cdn.jsdelivr.net/npm/@jaames/iro@5"></script>
        <script src="jquery-3.3.1.min.js" type="text/javascript"></script>
        <link href="switch.css" rel="stylesheet" type="text/css"/>
        <link href="responsive.css" rel="stylesheet" type="text/css"/>
        <link rel="preconnect" href="https://fonts.gstatic.com">
        <link href="https://fonts.googleapis.com/css2?family=Oswald:wght@400;600&display=swap" rel="stylesheet">
        <title>LAMP LED 2000</title>
    </head>
    <body>
        <header>
            <nav>
                <a style="text-align: left;" href="index.php" class="activo">Inicio</a>
                <a style="text-align: center;" href="#">Ayuda</a>
                <a style="text-align: right;" href="#">Contactos</a>
            </nav>
        </header>
        <div class="contenedor">
        <form action="recibir.php" method="get">
                        <div class="ocultar"> </div>   
            <div id="switchs">
            <div id="dSwitch">
             <img src="img/power.svg">    

            <?php 
            if($fila ['prendido']==="1"){
                echo "<input type='checkbox' checked id='prendidoA'>";
            }
            else{
                echo "<input type='checkbox' id='prendidoA'>";
            }
            ?>
            </div>

            <div id="dSwitch2">
                <img src="img/moon.svg">    
            <?php 
            if($fila ['reposo']==="1"){
                echo "<input type='checkbox' checked id='reposoA'>";
            }
            else{
                echo "<input type='checkbox' id='reposoA'>";
            }
            ?>
            </div>
        </div>

            
            <input type="text" name="prendido" id="prendido" style="display: none;">
            <input type="text" name="reposo" id="reposo" style="display: none;">
        <div class="prendido">
            <div id="contBrillo">
                <img src="img/sol.svg">
                <div class="slidecontainer"> 
                    <input type="range" class="slider" name="brillo" id="brillo" min="0" max="255" value="<?php echo $fila ['brillo']?>">
                </div>
            </div>
            
            
            <div id="picker"></div>            
            <div id="values" style="display: none;">
                <label for="r">Canal R</label>
                <input type="text" name="r" id="r" value="<?php echo $fila ['r']?>" >
                <label for="g">Canal G</label>
                <input type="text" name="g" id="g" value="<?php echo $fila ['g']?>" >
                <label for="b">Canal B</label>
                <input type="text" name="b" id="b" value="<?php echo $fila ['b']?>" >
            </div>
            </div>
        
                
            <label class="submit">
                <img src="img/ok.svg">
                <input type="submit" value="ok"  style="display: none;">
            </label>
        </form>
        </div>
        <footer><p style="text-align: left;">Prof. Sebastián Otte, Multimedia 1</p><p style="text-align: center;">Hecho por Gastón Mourelle, Mauricio de Castro y Agustín Figari</p><p style="text-align: right;">Lic. Diseño Multimedia (LDN6A), ORT</p></footer>
        <script src="color.js" type="text/javascript"></script>
        <script src="check.js" type="text/javascript"></script>
    </body>
</html>
