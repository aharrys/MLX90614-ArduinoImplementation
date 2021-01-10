//-----------------Library for ESP8266------------------------
#include "wifiLibrary.h"

//-----------------Ubidots Library----------------------------
#include "ubidotFile.h"

//-----------------Library For Access MLX90614----------------
#include "sensorIRLibrary.h"

//------------Setup ID for Ambient and Objet Tempreature------
#include "dataBaseLibrary.h"

//----------------- Setup Arduino-----------------------------
void setup() { 
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  // Setting WI - FI
  WiFi.hostname("ESP");
  WiFi.config(IP, GATEWAY, SUBNET, DNS1);
  WiFi.begin(ssid, pswd);
  Serial.println("");
//  while (WiFi.status() != WL_CONNECTED) {
//      delay(500);
//      Serial.print(".");
//      if (millis() >= 120000) {
//          ESP.restart();
//      }
//  }
  Serial.println("");
  Serial.print("Connected to ..");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("DNS: ");
  Serial.println(DNS1);
  Serial.print("Hostname: ");
  Serial.println(WiFi.hostname());
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

  // MLX Start
  mlx.begin();
}

//-----------------While looping------------------
void loop() {
 Serial.print("Ambient ");
 Serial.print(mlx.readAmbientTempC());
 Serial.print(" *C");
 ambientTemp = mlx.readAmbientTempC();
 Serial.println("");
 Serial.println("postDB_ambientTemp");
 postDB_ambientTemp();
 
 Serial.print("   Target  ");
 Serial.print(mlx.readObjectTempC());
 Serial.print(" *C");
 objectTemp = mlx.readObjectTempC();
 Serial.println("");
 Serial.println("postDB_objectTemp");
 postDB_objectTemp();

 Serial.println("Send data to ubidots");
 client.add(ID_AmbientTemp, ambientTemp);
 client.add(ID_ObjectTemp, objectTemp);
 client.sendAll();
 Serial.println("--------------------- end --------------------");
 Serial.println("Going into deep sleep for 50 seconds");
 ESP.deepSleep(50e6); // 50e6 is 50 microseconds
 //delay(1000);
 

}
