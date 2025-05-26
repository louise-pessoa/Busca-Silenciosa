# 📃MANUAL DO DESENVOLVEDOR:

### O que foi necessário e como o projeto foi executado?

<!--
## **1. Ideação**💡
- 
*Mais detalhes no [nosso site](https://sites.google.com/cesar.school/g18-buscasilenciosa/status-report-1).
-->

## **Materiais, conhecimentos e plataformas**

### Materiais🛠️

- ESP32

- Cabo USB para Micro USB

- Powerbank 10.000 mAh

- Motor vibratório 1027 (Vibracall)

- Protoboard

- Fios "macho-macho" e "macho-fêmea"

### Conhecimentos🧠

- Circuitos de microcontroladores (como Arduino)

- C++

- Conexão WiFi do ESP32 (por exemplo os modos Station e Access Point)

### Plataformas🚉

- _Arduino IDE_: testes com o circuito

    - Board "ESP32 Dev Module"

- _GitHub_ e _VSCode_: atualizações do repositório

## **Execução**

![imagens do circuito](link)

    #include <WiFi.h> 
Esse trecho do código inicializa a função wi-fi, que permite o ESP32 utilizar essa função no código.

    const char* targetSSID = "InternetNet"; // Nome exato do hotspot
    int motorPin = 2; // Pino PWM para acionar o motor
    const int rssiThreshold = -80; // Sinal mais forte que isso = motor liga
Essa parte do código determina o SSID da rede que o ESP32 irá buscar, nesse mesmo trecho determina também a porta que o motor utilizará e uma variável que será utilizada para usar a gradação do motor de vibração.

    void setup() {       
      Serial.begin(115200);
      pinMode(motorPin, OUTPUT);
      analogWrite(motorPin, 0); // Garante que o motor comece desligado
      WiFi.mode(WIFI_STA);
      WiFi.disconnect(true); // Limpa redes anteriores
      delay(1000);
    }
Dentro do void setup:
+ Serial.begin() - Determina a velocidade de 


![imagens do funcionamento (passo a passo)](link)

<!--
como a versão final funciona?
acredito que só dá para fazer essa parte quando tiver tudo pronto (pelo menos do código e do circuito).
-->
