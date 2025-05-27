# 📃MANUAL DO DESENVOLVEDOR:

 O que foi necessário e como o projeto foi executado.

## **Materiais, conhecimentos e plataformas**

### Materiais🛠️

- ESP32

- Cabo USB para Micro USB

- Powerbank 10.000 mAh

- Motor vibratório 1027 (Vibracall)

### Conhecimentos🧠

- Circuitos de microcontroladores (como Arduino)

- C++

- Conexão WiFi do ESP32 (por exemplo os modos Station e Access Point)

### Plataformas🚉

- _Arduino IDE_: testes com o circuito

    - Board `ESP32 Dev Module`

## **Execução**

    #include <WiFi.h>
Inicia a função Wi-Fi no ESP32;

    const char* targetSSID = "InternetNet";
    const char * password= "abcdefgh";

- `const char* targetSSID` - Essa variável coleta o nome da rede;
- `const char* password` - Essa variável coleta a senha da rede;

        int motorPin = 2;
        const int rssiThreshold = -80;
        int indice=0;
        bool redeEncontrada = false;

- int motorPin = 2 - Porta que o motor deve utilizar;

- const int rssiThreshold = -80 - RSSI limite que estamos utilizando;

- int indice=0 - Esse índice vai ser melhor explicado no momento de sua utilização, nesse momento essa variável está sendo inicializada;

- bool redeEncontrada = false - Essa variável booleana está definindo o estado da variável;

      void setup() {
        Serial.begin(115200);
        pinMode(motorPin, OUTPUT);
        analogWrite(motorPin, 0);
        WiFi.mode(WIFI_STA);
        WiFi.begin(targetSSID,password);

Dentro do void setup:

- Serial.begin(115200) - Nessa parte do código é a velocidade em que a ESP32 transmite informações;

- pinMode(motorPin, OUTPUT) - Esse trecho define a portae que o mesmo vai utilizar e  que o motor será para saída de dados;

- analogWrite(motorPin, 0) - Para que o motor de vibração começe desligado;

- Wifi.mode(WIFI_STA) - Define o modo de internet que o ESP32 vai está utilizando, nesse caso, o código define como o station que é para apenas se conectar a outras redes;

- Wifi.begin(targetSSID, password) - Essa função faz com que o ESP32 se conecte a rede definida a partir da rede e da senha;

      while(WiFi.status() != WL_CONNECTED){
          Serial.print('.');
          delay(1000);
           }
          redeEncontrada = true;
      }
Continuando dentro do void loop:

- While(Wifif.status() != WL_CONNECTED) - Confere se está conectado na rede ou não, se não estiver conectado redeEncontrada se torna true, mas se a rede for conectada irá seguir o código;

- Serial.print('-'); - Para mostrar isso no monitor serial;

- redeEncontrada = true - Torna o estado da variável true;

        void loop() {
            ...
        }
Inicializa o void loop, que é o trecho de código que fica se repetindo;

      int rssi=WiFi.RSSI();
Nesse trecho é o local do código, no qual, o ESP32 capta o RSSI da rede;

    if (rssi <= rssiThreshold) {
       analogWrite(motorPin, 0);
       Serial.println("SINAL MUITO FRACO → MOTOR DESLIGADO");
       Serial.println(rssi);
    } else if {

Desse trecho até...

    } else { // rssi > -40 (mais perto de 0)
       analogWrite(motorPin, 1);
       Serial.println(rssi);
       Serial.println("CELULAR MUITO PROXIMO → VIBRAÇÃO FORTE"); 
    }

Esse trecho, existe uma estrutura de condicional que depende do RSSI da rede que a ESP32 está conectada. Quanto maior o RSSI, maior a intensidade da vibração do motor.

    if (!redeEncontrada) {
       analogWrite(motorPin, 0);
       Serial.println("Rede não encontrada. MOTOR DESLIGADO");
    }

Essa parte vai depender da rede, como no começo do código tem a verificação para ver se a rede está conectada, nessa parte se a rede estiver desconectada faz com que o motor vibratório desligue.

![imagens do funcionamento (passo a passo)](link)

*Mais detalhes da ideação, testes e execuçãos no nosso site [Busca SIlenciosa](https://sites.google.com/cesar.school/g18-buscasilenciosa/status-report-1).