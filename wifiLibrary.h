//-------------Library for ESP8266------------------------
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266Ping.h>

//-------------Setup Static IPAddress---------------------
IPAddress IP (172, 3, 1, 7); // Change here IP
IPAddress SUBNET (255, 255, 240, 0);
IPAddress GATEWAY (172, 3, 15, 254);
IPAddress DNS1 (10, 2, 222, 160);
IPAddress DNS2 (10, 2, 222, 232);

/*IPAddress IP (192, 168, 100, 22); // Change here IP
IPAddress SUBNET (255, 255, 255, 0);
IPAddress GATEWAY (192, 168, 100, 1);
IPAddress DNS1 (192, 168, 100, 1);
IPAddress DNS2 (10, 2, 222, 232);
*/
//--------------SSID and Password Wi-Fi------------------
char ssid[] = "DCI-IOTN";
char pswd[] = "f0xtr0ti0t";
/*char ssid[] = "#OTNASUS";
char pswd[] = "12345678qwerty";*/
