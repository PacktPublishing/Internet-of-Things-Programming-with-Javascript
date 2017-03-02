var server = require('http');

function loadServer(requiere,response){
	console.log("Somebody is connected");
	response.writeHead(200,{"Content-Type":"text/html"});
	response.write("<h1>The Server works perfect</h1>");
	response.end();
}

servidor.createServer(arrancaServidor).listen(8080);
