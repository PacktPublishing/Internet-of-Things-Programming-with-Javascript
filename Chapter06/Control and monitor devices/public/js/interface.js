// Set pin 8 as output on lamp control module
$.getq('queue', '/lamp_control/mode/8/o');
$.getq('queue', '/lamp_control2/mode/5/o');

$(document).ready(function() {

  // Function to control lamp Ethernet Shield
  $("#1").click(function() {
    $.getq('queue', '/lamp_control/digital/8/1');
  });

  $("#2").click(function() {
    $.getq('queue', '/lamp_control/digital/8/0');
  });

//Function to control lamp ESP8266
  $("#3").click(function() {
    $.getq('queue', '/lamp_control2/digital/5/0');
  });

  $("#4").click(function() {
    $.getq('queue', '/lamp_control2/digital/5/1');
  });


  // Get data from DHT sensor
  function refresh_dht() {
  	$.getq('queue', '/sensor/temperature', function(data) {
      $('#temperature').html("Temperature: " + data.temperature + " C");	
    });
         $.getq('queue', '/sensor2/temperature2', function(data) {
      $('#temperature2').html("Temperature: " + data.temperature2 + " C");
    });

        $.getq('queue', '/sensor/humidity', function(data) {
      $('#humidity').html("Humidity: " + data.humidity + " %");
    });
         $.getq('queue', '/sensor2/humidity2', function(data) {
      $('#humidity2').html("Humidity: " + data.humidity2 + " %");
    });
  }
  refresh_dht();
  setInterval(refresh_dht, 10000);

});
