#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "Deepak"
#define STAPSK "radhaaurkrishna"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
const char index_html[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html>
  

  <head>
    <title>AQUAFONICS</title>
    <link rel="icon" type="image/png" sizes="32x32" href="/favicon-32x32.png" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <script src="https://code.highcharts.com/highcharts.js"></script>
    <style>
      body {
        background-image: url("download (1).jfif"); 
        
        
      }
      
    </style>
    <link
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9"
      crossorigin="anonymous"
    />
  </head>

  <body>
      <div class="container-fluid " style="background-image:url('pngtree-fantasy-bubble-spring-grass-background-image_325665 Cropped (1).jpg');
      ; height:90px">
        <div class="row">
          <div class="col-md-5" >
            <img
            width="64"
            height="64"
            src="https://img.icons8.com/external-icongeek26-flat-icongeek26/64/external-seaweed-sea-life-icongeek26-flat-icongeek26.png"
            alt="external-seaweed-sea-life-icongeek26-flat-icongeek26"
          />
          </div>
          <div class="col-md-7" style="display:flex; align-items:center">
           <h1 class="navbar-brand" style="font-size:200%">Aquafonics Monitoring System</h1>
          </div>
        </div>
  
  
        </div>
    
  

    <div class="container-fluid pt-3">
      <div class="row mb-3">
        <div class="col-md-6">
          <div class="card" style="">
            <div id="chart-ammonia"></div>
            <div class="card-body">
              
            </div>
          </div>
          
        </div>
        <div class="col-md-6">
          <div class="card" style="">
             <div id="chart-nitrite"></div>
            <div class="card-body">
              
            </div>
          </div>
        </div>
      </div>
      <div class="row mb-3">
        <div class="col-md-6">
          <div class="card" style="">
            <div id="chart-nitrate"></div>
            <div class="card-body">
             
            </div>
          </div>
        </div>
        <div class="col-md-6">
          <div class="card" style="">
            <div id="chart-ph"></div>
            <div class="card-body">
             
            </div>
          </div>
        </div>
      </div>
      <div class="row ">
        <div class="col-md-6">
          <div class="card" style="">
            <div id="chart-temperature"></div>
            <div class="card-body">
              
            </div>
        </div>
      </div>
      
    </div>
    </div>
  </body>
  <script>
    var chartT = new Highcharts.Chart({
      chart: { renderTo: "chart-ammonia" },
      title: { text: "concentration of Ammonia" },
      series: [
        {
          showInLegend: false,
          data: [],
        },
      ],
      plotOptions: {
        line: {
          animation: false,
          dataLabels: { enabled: true },
        },
        series: { color: "#059e8a" },
      },
      xAxis: {
        type: "datetime",
        dateTimeLabelFormats: { second: "%H:%M:%S" },
      },
      yAxis: {
        title: { text: "Ammonia concentration(ppm)" },
        //title: { text: 'Temperature (Fahrenheit)' }
      },
      credits: { enabled: false },
    });
    setInterval(function () {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          var x = new Date().getTime(),
            y = parseFloat(this.responseText);
          //console.log(this.responseText);
          if (chartT.series[0].data.length > 40) {
            chartT.series[0].addPoint([x, y], true, true, true);
          } else {
            chartT.series[0].addPoint([x, y], true, false, true);
          }
        }
      };
      xhttp.open("GET", "/ammonia", true);
      xhttp.send();
    }, 30000);

    var chartH = new Highcharts.Chart({
      chart: { renderTo: "chart-nitrite" },
      title: { text: "Concentration of Nitrite" },
      series: [
        {
          showInLegend: false,
          data: [],
        },
      ],
      plotOptions: {
        line: {
          animation: false,
          dataLabels: { enabled: true },
        },
      },
      xAxis: {
        type: "datetime",
        dateTimeLabelFormats: { second: "%H:%M:%S" },
      },
      yAxis: {
        title: { text: "Nitrite concentration(ppb)" },
      },
      credits: { enabled: false },
    });
    setInterval(function () {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          var x = new Date().getTime(),
            y = parseFloat(this.responseText);
          //console.log(this.responseText);
          if (chartH.series[0].data.length > 40) {
            chartH.series[0].addPoint([x, y], true, true, true);
          } else {
            chartH.series[0].addPoint([x, y], true, false, true);
          }
        }
      };
      xhttp.open("GET", "/nitrite", true);
      xhttp.send();
    }, 30000);

    var chartP = new Highcharts.Chart({
      chart: { renderTo: "chart-nitrate" },
      title: { text: "Nitrate concentration monitoring" },
      series: [
        {
          showInLegend: false,
          data: [],
        },
      ],
      plotOptions: {
        line: {
          animation: false,
          dataLabels: { enabled: true },
        },
        series: { color: "#18009c" },
      },
      xAxis: {
        type: "datetime",
        dateTimeLabelFormats: { second: "%H:%M:%S" },
      },
      yAxis: {
        title: { text: "Nitrate concentration(ppm)" },
      },
      credits: { enabled: false },
    });
    setInterval(function () {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          var x = new Date().getTime(),
            y = parseFloat(this.responseText);
          //console.log(this.responseText);
          if (chartP.series[0].data.length > 40) {
            chartP.series[0].addPoint([x, y], true, true, true);
          } else {
            chartP.series[0].addPoint([x, y], true, false, true);
          }
        }
      };
      xhttp.open("GET", "/nitrate", true);
      xhttp.send();
    }, 30000);

    var chartP = new Highcharts.Chart({
      chart: { renderTo: "chart-ph" },
      title: { text: "Ph monitoring of the water " },
      series: [
        {
          showInLegend: false,
          data: [],
        },
      ],
      plotOptions: {
        line: {
          animation: false,
          dataLabels: { enabled: true },
        },
        series: { color: "#18009c" },
      },
      xAxis: {
        type: "datetime",
        dateTimeLabelFormats: { second: "%H:%M:%S" },
      },
      yAxis: {
        title: { text: "Ph value" },
      },
      credits: { enabled: false },
    });
    setInterval(function () {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          var x = new Date().getTime(),
            y = parseFloat(this.responseText);
          //console.log(this.responseText);
          if (chartP.series[0].data.length > 40) {
            chartP.series[0].addPoint([x, y], true, true, true);
          } else {
            chartP.series[0].addPoint([x, y], true, false, true);
          }
        }
      };
      xhttp.open("GET", "/ph", true);
      xhttp.send();
    }, 30000);

    var chartP = new Highcharts.Chart({
      chart: { renderTo: "chart-temperature" },
      title: { text: "Temperature monitoring of water" },
      series: [
        {
          showInLegend: false,
          data: [],
        },
      ],
      plotOptions: {
        line: {
          animation: false,
          dataLabels: { enabled: true },
        },
        series: { color: "#18009c" },
      },
      xAxis: {
        type: "datetime",
        dateTimeLabelFormats: { second: "%H:%M:%S" },
      },
      yAxis: {
        title: { text: "Temperature in degree celcius" },
      },
      credits: { enabled: false },
    });
    setInterval(function () {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          var x = new Date().getTime(),
            y = parseFloat(this.responseText);
          //console.log(this.responseText);
          if (chartP.series[0].data.length > 40) {
            chartP.series[0].addPoint([x, y], true, true, true);
          } else {
            chartP.series[0].addPoint([x, y], true, false, true);
          }
        }
      };
      xhttp.open("GET", "/temperature", true);
      xhttp.send();
    }, 30000);
  </script>
  <script
    src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-HwwvtgBNo3bZJJLYd8oVXjrBZt8cqVSpeBNS5n7C8IVInixGAoxmnlMuBnhbgrkm"
    crossorigin="anonymous"
  ></script>
</html>


)=====";

ESP8266WebServer server(80);

const int led = 13;

void sendHtml() {
  server.send_P(200, "text/html", index_html);
}


void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) { message += " " + server.argName(i) + ": " + server.arg(i) + "\n"; }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) { Serial.println("MDNS responder started"); }

  server.on("/", sendHtml);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.on("/gif", []() {
    static const uint8_t gif[] PROGMEM = {
      0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x10, 0x00, 0x10, 0x00, 0x80, 0x01,
      0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x2c, 0x00, 0x00, 0x00, 0x00,
      0x10, 0x00, 0x10, 0x00, 0x00, 0x02, 0x19, 0x8c, 0x8f, 0xa9, 0xcb, 0x9d,
      0x00, 0x5f, 0x74, 0xb4, 0x56, 0xb0, 0xb0, 0xd2, 0xf2, 0x35, 0x1e, 0x4c,
      0x0c, 0x24, 0x5a, 0xe6, 0x89, 0xa6, 0x4d, 0x01, 0x00, 0x3b
    };
    char gif_colored[sizeof(gif)];
    memcpy_P(gif_colored, gif, sizeof(gif));
    // Set the background to a random set of colors
    gif_colored[16] = millis() % 256;
    gif_colored[17] = millis() % 256;
    gif_colored[18] = millis() % 256;
    server.send(200, "image/gif", gif_colored, sizeof(gif_colored));
  });

  server.onNotFound(handleNotFound);

  /////////////////////////////////////////////////////////
  // Hook examples

  server.addHook([](const String& method, const String& url, WiFiClient* client, ESP8266WebServer::ContentTypeFunction contentType) {
    (void)method;       // GET, PUT, ...
    (void)url;          // example: /root/myfile.html
    (void)client;       // the webserver tcp client connection
    (void)contentType;  // contentType(".html") => "text/html"
    Serial.printf("A useless web hook has passed\n");
    Serial.printf("(this hook is in 0x%08x area (401x=IRAM 402x=FLASH))\n", esp_get_program_counter());
    return ESP8266WebServer::CLIENT_REQUEST_CAN_CONTINUE;
  });

  server.addHook([](const String&, const String& url, WiFiClient*, ESP8266WebServer::ContentTypeFunction) {
    if (url.startsWith("/fail")) {
      Serial.printf("An always failing web hook has been triggered\n");
      return ESP8266WebServer::CLIENT_MUST_STOP;
    }
    return ESP8266WebServer::CLIENT_REQUEST_CAN_CONTINUE;
  });

  server.addHook([](const String&, const String& url, WiFiClient* client, ESP8266WebServer::ContentTypeFunction) {
    if (url.startsWith("/dump")) {
      Serial.printf("The dumper web hook is on the run\n");

      // Here the request is not interpreted, so we cannot for sure
      // swallow the exact amount matching the full request+content,
      // hence the tcp connection cannot be handled anymore by the
      // webserver.
#ifdef STREAMSEND_API
      // we are lucky
      client->sendAll(Serial, 500);
#else
      auto last = millis();
      while ((millis() - last) < 500) {
        char buf[32];
        size_t len = client->read((uint8_t*)buf, sizeof(buf));
        if (len > 0) {
          Serial.printf("(<%d> chars)", (int)len);
          Serial.write(buf, len);
          last = millis();
        }
      }
#endif
      // Two choices: return MUST STOP and webserver will close it
      //                       (we already have the example with '/fail' hook)
      // or                  IS GIVEN and webserver will forget it
      // trying with IS GIVEN and storing it on a dumb WiFiClient.
      // check the client connection: it should not immediately be closed
      // (make another '/dump' one to close the first)
      Serial.printf("\nTelling server to forget this connection\n");
      static WiFiClient forgetme = *client;  // stop previous one if present and transfer client refcounter
      return ESP8266WebServer::CLIENT_IS_GIVEN;
    }
    return ESP8266WebServer::CLIENT_REQUEST_CAN_CONTINUE;
  });

  // Hook examples
  /////////////////////////////////////////////////////////

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
