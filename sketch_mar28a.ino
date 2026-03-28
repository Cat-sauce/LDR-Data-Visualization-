#include <WiFi.h>
#include <ThingSpeak.h>

// WiFi credentials
const char* ssid = "WIFI NAME";
const char* password = "WIFI password";

// ThingSpeak details
unsigned long channelNumber = CHANNEL ID;
const char * writeAPIKey = "WRITE API KEY";

WiFiClient client;

// LDR pin (ESP32)
#define LDR_PIN 34

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {

  // Read LDR value
  int ldrValue = analogRead(LDR_PIN);

  // Convert to percentage
  float percentage = (ldrValue / 4095.0) * 100.0;

  // Determine light condition
  int lightStatus;
  if (ldrValue < 1500) {
    lightStatus = 0;  // Dark
  } else {
    lightStatus = 1;  // Bright
  }

  // Serial output (for debugging/demo)
  Serial.print("Raw: ");
  Serial.print(ldrValue);
  Serial.print(" | %: ");
  Serial.print(percentage);
  Serial.print(" | Status: ");
  Serial.println(lightStatus);

  // Send data to ThingSpeak
  ThingSpeak.setField(1, ldrValue);     // Light Intensity
  ThingSpeak.setField(2, percentage);   // Percentage
  ThingSpeak.setField(3, lightStatus);  // Status

  ThingSpeak.writeFields(channelNumber, writeAPIKey);

  // ThingSpeak minimum delay
  delay(15000);
}
