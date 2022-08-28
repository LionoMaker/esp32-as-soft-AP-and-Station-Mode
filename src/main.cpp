//@LionoMaker
/*
Note:
please read this article before using ESP32 diffferent Modes
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/wifi.html?highlight=wifi_mode_apsta#wi-fi-mode
*/

//Paractice this code on Platformio

#include<Arduino.h>
#include <WiFi.h>
 
const char* wifi_network_ssid = "LionoMaker";
const char* wifi_network_password =  "lionomaker13";
 
const char *soft_ap_ssid = "ESP32_AP";
const char *soft_ap_password = "12345678";

//design an event to which mode ESP32 connect 
 
// void OnWiFiEvent(WiFiEvent_t event)
// {
//   switch (event) {
 
//     case SYSTEM_EVENT_STA_CONNECTED:
//       Serial.print("ESP32 Connected to WiFi Network:");
//       Serial.println(wifi_network_ssid); //netwok SSID
//       break;
//     case SYSTEM_EVENT_AP_START:
//       Serial.println("ESP32 soft AP started");
//       Serial.println(soft_ap_ssid ); // Soft AP Mode ssid
//       break;
//     case SYSTEM_EVENT_AP_STACONNECTED:
//       Serial.println("Station connected to ESP32 soft AP");
      
//       break;
//     case SYSTEM_EVENT_AP_STADISCONNECTED:
//       Serial.println("Station disconnected from ESP32 soft AP");
//       break;
//     default: break;
//   }
// }
 
 
void setup() {
 
  Serial.begin(115200);
  //WiFi.onEvent(OnWiFiEvent);
 
  WiFi.mode(WIFI_MODE_APSTA); // runs Soft_AP and STA mode simultaneously
 
  WiFi.softAP(soft_ap_ssid, soft_ap_password);
  WiFi.begin(wifi_network_ssid, wifi_network_password);
  Serial.print("Network SSID:");
  Serial.println(wifi_network_ssid);

  Serial.print("ESP32_AP SSID:");
  Serial.println(soft_ap_ssid);

}
 
void loop() {}