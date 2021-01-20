//CODE FOR MASTER 
//===================================================================
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

//=============================ESP_AP CREDENTIALS======================================
const char* ssid = "Name";
const char* password = "12345678";
int max_connection = 8;

//=====================================================================================

//===============================STATIC IP DECLARATION=================================
IPAddress staticIP(10,10,10,1); // IP address from Admin pannel 
IPAddress gateway(10,10,10,1);
IPAddress subnet(255,255,255,0);
//=====================================================================================

int httpCode;

HTTPClient http;

ESP8266WebServer server(80); //Server on port 80


//==============================================================
//     This rutine is exicuted when you open its IP in browser
//==============================================================
void handleRoot() {
  server.send(200, "text/plain", "Hello from Rushikesh");
}
void ledon(){
   server.send(200, "text/plain", "LED is ON" );
  digitalWrite(D2,HIGH);
  Serial.println("LED is ON");
  }
void ledoff() {
   server.send(200, "text/plain", "LED is OFF" );
  digitalWrite(D2,LOW);
   Serial.println("LED is OFF");
}
//===============================================================
//                  SETUP
//===============================================================

void setup(){
 
  Serial.begin(115200);
  Serial.println("");
  WiFi.mode(WIFI_AP);           //Only Access point
  WiFi.softAP(ssid, password, 1, false, max_connection); 
  WiFi.softAPConfig(staticIP, gateway, subnet);//Start HOTspot removing password will disable security
  Serial.printf("Stations connected to soft-AP = %d\n", WiFi.softAPgetStationNum());


  IPAddress myIP = WiFi.softAPIP(); //Get IP address
  Serial.print("HotSpt IP:");
  Serial.println(myIP);
   pinMode(D2, OUTPUT);
   
   server.on("/", handleRoot); //Which routine to handle at root location
  
   server.on("/ledon", ledon);
   server.on("/ledoff", ledoff);    
   server.begin();            //Start server
   Serial.println("HTTP server started");
}

//===============================================================
//                     LOOP
//===============================================================
void loop(){
server.handleClient();          //Handle client requests        
} 
