//teste de Louise (fonte: DeepSeek)

#include <WiFi.h>
const char* targetSSID = "A53 de Louise";
int motorPin = 2;
const int rssiThreshold = -80;

void setup() {
    Serial.begin(115200);
    pinMode(motorPin, OUTPUT);
    analogWrite(motorPin, 0);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect(true);
}

void loop() {
    Serial.println("Escaneando redes Wi-Fi...");
    int numRedes = WiFi.scanNetworks();
    bool redeEncontrada = false;
    
    for (int i = 0; i < numRedes; ++i) {
        if (WiFi.SSID(i) == targetSSID) {
            redeEncontrada = true;
            int rssi = WiFi.RSSI(i);
            
            Serial.print("REDE ALVO ENCONTRADA: ");
            Serial.print(targetSSID);
            Serial.print(" | RSSI: ");
            Serial.print(rssi);
            Serial.println(" dBm");

            if (rssi <= rssiThreshold) {
                analogWrite(motorPin, 0);
                Serial.println("SINAL MUITO FRACO → MOTOR DESLIGADO");
            } 
            else if (rssi > rssiThreshold && rssi <= -60) {
                analogWrite(motorPin, 85);
                Serial.println("CELULAR DISTANTE → VIBRAÇÃO FRACA");
            } 
            else if (rssi > -60 && rssi <= -40) {
                analogWrite(motorPin, 170);
                Serial.println("CELULAR PROXIMO → VIBRAÇÃO MÉDIA");
            } 
            else { // rssi > -40 (mais perto de 0)
                analogWrite(motorPin, 255);
                Serial.println("CELULAR MUITO PROXIMO → VIBRAÇÃO FORTE");
            }
            break; // Sai do for depois de encontrar a rede alvo
        }
    }
    
    if (!redeEncontrada) {
        analogWrite(motorPin, 0);
        Serial.println("Rede não encontrada. MOTOR DESLIGADO");
    }
    delay(2000); // Espera 2 segundos entre varreduras
    WiFi.scanDelete(); // Limpa resultados anteriores
}