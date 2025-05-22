#include <WiFi.h>

const char* targetSSID = "iPhone de Eros (2)"; // nome do hotspot
const int ledPin = 2; //GPIO 4 (LED onboard)
const int rssiThreshold = -70; //limiar de sinal

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, LOW); // LED começa apagado

  WiFi.mode(WIFI_STA);
  WiFi.disconnect(); // Garante que não está conectado a nenhuma rede
  delay(100);
}

void loop() {
  Serial.println("Escaneando redes Wi-Fi...");
  int numRedes = WiFi.scanNetworks();
  bool redeEncontrada = false;

  for (int i = 0; i < numRedes; ++i) {
    String ssid = WiFi.SSID(i);
    int rssi = WiFi.RSSI(i);

    if (ssid == targetSSID) {
      redeEncontrada = true;
      Serial.print("Rede encontrada: ");
      Serial.println(ssid);
      Serial.print("RSSI: ");
      Serial.print(rssi);
      Serial.println(" dBm");

      if (rssi > rssiThreshold) {
        analogWrite(ledPin, );
        Serial.println("LED ACESO");
      } else {
        analogWrite(ledPin, LOW);
        Serial.println("LED APAGADO");
      }
      break;
    }
  }

  if (!redeEncontrada) {
    analogWrite(ledPin, LOW);
    Serial.println("Rede não encontrada. LED APAGADO");
  }

  delay(5000); // Aguarda 5 segundos
}
