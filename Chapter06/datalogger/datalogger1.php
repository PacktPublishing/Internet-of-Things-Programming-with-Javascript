<?php

// VERIFICA QUE LAS VARIABLES ESTEN PRESENTES
if (isset($_GET["temp"]) && isset($_GET["hum"])) {

// SE OBTIENEN LOS DATOS ENVIADOS DESDE LA PLACA ARDUINO
$temperature = intval($_GET["temp"]);
$humidity = intval($_GET["hum"]);

//Abrir conexion a bd
$con=mysql_connect("localhost","root","ruben","arduinobd");

//Hacer la insercion de la temperatura y humedad
mysql_select_db('arduinobd',$con);

	if(mysql_query("INSERT INTO measurements (temperature, humidity) VALUES ('$temperature', '$humidity');")){
	  echo "Datos guardados";
	}
	else {
	  echo "Fallo en el guardado de los datos";
	}

//Cerrar conexion
mysql_close($con);
}
?>
