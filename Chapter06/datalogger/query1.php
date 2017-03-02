<!DOCTYPE html>
  <html>
    <body>
<h1>Clik on the buttons to get Data from  MySQL</h1>
<form action="query1.php" method="get">
<input type="submit" value="Get all Data"> 
</form>
</br>

<form action="query2.php" method="get">
<input type="submit"value="Humidity <= 15">
</form> 
</br>

<form action="query3.php" method="get">
<input type="submit" value="Temperature <=25"> 
</form>
</br>

<?php

$con=mysql_connect("localhost","root","ruben","arduinobd");

mysql_select_db('arduinobd',$con);
$result = mysql_query("SELECT * FROM measurements");

echo "<table border='1'>
<tr>
<th>Measurements</th>
<th>Temperature (°C)</th>
<th>Humidity (%)</th>
</tr>";

while($row = mysql_fetch_array($result)) {
  echo "<tr>";
  echo "<td>" . $row['id'] . "</td>";
  echo "<td>" . $row['temperature'] . "</td>";
  echo "<td>" . $row['humidity'] . "</td>";
  echo "</tr>";
}

echo "</table>";
mysql_close($con);
?>

</body>
</html>
