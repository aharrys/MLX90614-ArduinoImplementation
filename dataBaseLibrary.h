//-------------Setup ID for Ambient and Objet Tempreature---------
String ambientID = "1644"; // Ambient ID for Database
String objectTemperatureID = "1645"; // Object Temperature for Database

//--------------Variable Setup------------------------------------
float ambientTemp, objectTemp;

void postDB_ambientTemp () {
    HTTPClient http;
    String valueSend, PostData;
    delay(50);
    valueSend = String(ambientTemp);
    String url = "http://10.2.222.232/IoTApiWeb/api/activityvariable/insert?variableId="+ambientID+"&value="+valueSend+"&token=password";
    PostData = "value=" + valueSend;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(PostData);
    Serial.println(url);
  
    if (httpCode > 0){
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);
        
        if (httpCode == HTTP_CODE_OK) {
            const String& payload = http.getString();
            Serial.println("received payload:\n<<");
            Serial.println(payload);
            Serial.println(">>");
        }
    } else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
}

void postDB_objectTemp() {
    HTTPClient http;
    String valueSend, PostData;
    delay(50);
    valueSend = String(objectTemp);
    String url = "http://10.2.222.232/IoTApiWeb/api/activityvariable/insert?variableId="+objectTemperatureID+"&value="+valueSend+"&token=password";
    PostData = "value=" + valueSend;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(PostData);
    Serial.println(url);
  
    if (httpCode > 0){
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);
        
        if (httpCode == HTTP_CODE_OK) {
            const String& payload = http.getString();
            Serial.println("received payload:\n<<");
            Serial.println(payload);
            Serial.println(">>");
        }
    } else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
}
