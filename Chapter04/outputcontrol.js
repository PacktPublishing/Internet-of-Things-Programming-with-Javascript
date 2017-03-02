var gpio = require('rpi-gpio');
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var port = 8099;

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

gpio.setup(11, gpio.DIR_OUT);

function ledon() {
    setTimeout(function() {
        console.log('led1 is on');
        gpio.write(11, 1);
	}, 2000);
}

function ledoff() {
    setTimeout(function() {
        console.log('led1 is off');
        gpio.write(11, 0);
   }, 2000);
}

app.get('/ledon', function (req, res) {
    ledon();

    var data ={status:"connected",led:"on"};
    res.json(data);
});

app.get('/ledoff', function (req, res) {
    ledoff();

    var data ={status:"connected",led:"off"};
    res.json(data);
});

app.listen(port);
console.log('Server was started on ' + port);
