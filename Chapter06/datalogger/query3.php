<?php

$con=mysql_connect("localhost","root","ruben","arduinobd");

mysql_select_db('arduinobd',$con);
$result = mysql_query("SELECT * FROM measurements where temperature <= 25 order by id");

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
