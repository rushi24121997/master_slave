//CODE FOR SLAVE
//====================================================================================
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>

const char* ssid ="Name";
const char* password ="12345678";
IPAddress ip(10,10,10,55); 
IPAddress gateway(10,10,10,1); 
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);
void handleRoot() {
   server.send(200, "text/html", "Hello esp");
   
}

//=========================================================================================
//                       SETUP 
//=========================================================================================
void setup() {
   server.on("/", handleRoot);
   pinMode(D1,INPUT);

  server.begin();
    Serial.begin(115200);
    delay(500);
    WiFi.config(ip,gateway,subnet);
    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT ...\n", t);
        Serial.flush();
        delay(500);
    }
      WiFi.mode(WIFI_STA);
      WiFi.disconnect(true);
    WiFi.begin(ssid,password);
    if(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
    Serial.println("Connected");
  }
   
}
//========================================================================================
//                 LOOP  
//=======================================================================================
void loop() {
    
  server.handleClient();
 

    // wait for WiFi connection
    if((WiFi.status() == WL_CONNECTED)) {

        HTTPClient http;

     
if(digitalRead(D1) == HIGH)
        {          
           http.begin("http://10.10.10.1/ledon");
          Serial.println("10.10.10.1/ledon");
          int httpCode = http.GET();
           http.end();
        } 
else if(digitalRead(D1) == LOW)
        {          
           http.begin("http://10.10.10.1/ledoff");
          Serial.println("10.10.10.1/ledoff");
          int httpCode = http.GET();
           http.end();
        } 
}     
}
