// Modules
var express = require('express');
var app = express();
var request = require('request');

// Use public directory
app.use(express.static('public'));

// Pi addresses
var motionSensorPi = "192.168.0.104:3000";
var alarmPi = "192.168.0.103:3000"

// Pins
var buzzerPin = 15;
var ledPin = 14;
var motionSensorPin = 17;

// Routes
app.get('/', function (req, res) {

  res.sendfile(__dirname + '/public/interface.html');

});

app.get('/alarm', function (req, res) {

  res.json({alarm: alarm});

});

app.get('/off', function (req, res) {

  // Set alarm off
  alarm = false;

  // Set LED & buzzer off
  request("http://" + alarmPi + "/digital/" + ledPin + '/0');
  request("http://" + alarmPi + "/digital/" + buzzerPin + '/0');

  // Answer
  res.json({message: "Alarm off"});

});

// Start server
var server = app.listen(3000, function() {
    console.log('Listening on port %d', server.address().port);
});

// Motion sensor measurement loop
setInterval(function() {

  // Get data from motion sensor
  request("http://" + motionSensorPi + "/digital/" + motionSensorPin,
    function (error, response, body) {

      if (!error && body.return_value == 1) {

        // Activate alarm
        alarm = true;

        // Set LED on
        request("http://" + alarmPi + "/digital/" + ledPin + '/1');

        // Set buzzer on
        request("http://" + alarmPi + "/digital/" + buzzerPin + '/1');

      }
  });

}, 2000);
