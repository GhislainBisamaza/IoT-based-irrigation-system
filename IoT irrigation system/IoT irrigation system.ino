#include <ESP8266WiFi.h>;
 
#include <WiFiClient.h>;
 
#include <ThingSpeak.h>;
 
const char* ssid = "Ghislain"; //Your Network SSID
 
const char* password = "01234567890"; //Your Network Password of the wireless network
WiFiClient client;
unsigned long myChannelNumber = 1346841; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "V09ZGPPO1GJGIV9E"; //Your Write API Key
void setup() 
{
Serial.begin(9600);
delay(10);
// Connect to WiFi network
WiFi.begin(ssid, password);
ThingSpeak.begin(client); 
}
void loop()
{
 
int Soil_Moisture = analogRead(A0); //Read Analog values and Store in val variable
//val = map(val, 0, 1023, 100, 0);
Serial.print("Soil Moisture =");
Serial.println(Soil_Moisture); //Print on Serial Monitor
 
delay(1000);
 
//ThingSpeak.writeField(myChannelNumber, 1,Soil_Moisture, myWriteAPIKey); //Update in ThingSpeak
 
ThingSpeak.writeField(myChannelNumber, 1,Soil_Moisture, myWriteAPIKey); 
 
delay(1000);
 
}
