# 📃MANUAL DO DESENVOLVEDOR:

 O que foi necessário e como o projeto foi executado.

## **Materiais, conhecimentos e plataformas**

### Materiais🛠️

- ESP32

- Cabo USB para Micro USB

- Powerbank 10.000 mAh

- Motor vibratório 1027 (Vibracall)

- Transistor (interruptor)

### Conhecimentos🧠

- Circuitos de microcontroladores (como Arduino)

- C++

- Conexão WiFi do ESP32 (por exemplo os modos Station e Access Point)

### Plataformas🚉

- _Arduino IDE_: testes com o circuito

    - Board "ESP32 Dev Module"

## **Execução**

### Explicando o código principal `main.c++`

    #include <WiFi.h>
Inclui a biblioteca para conexão WiFi (necessária para placas como ESP32)

    const char* targetSSID = "InternetNet";
    const char* password = "abcdefgh";
Define o nome (SSID) e senha da rede WiFi que será monitorada

    int motorPin = 2;
Define o pino conectado ao motor (vibrador)
 
    const int rssiThreshold = -80;
Define o limite mínimo de intensidade de sinal (RSSI) para considerar o sinal utilizável

    int indice = 0;
    bool redeEncontrada = false;
Variáveis de controle

    void setup() {
        Serial.begin(115200);
  Inicia a comunicação serial para debug
  
        pinMode(motorPin, OUTPUT);
Define o pino do motor como saída
  
        analogWrite(motorPin, 0);
Garante que o motor inicie desligado
    
        WiFi.mode(WIFI_STA);
Coloca o WiFi em modo "station", ou seja, cliente

        WiFi.begin(targetSSID, password);
Tenta conectar-se à rede especificada

    while(WiFi.status() != WL_CONNECTED){
Aguarda até que a conexão com o WiFi seja estabelecida

        Serial.print('.');
        delay(1000);
    }
Imprime ponto a cada segundo para indicar que está tentando conectar

    redeEncontrada = true;
    }
Quando conectado, marca que a rede foi encontrada

    void loop() {
        int rssi = WiFi.RSSI();
Obtém o valor atual do sinal (RSSI) da rede conectada
 
    if (rssi <= rssiThreshold) {
        analogWrite(motorPin, 255);
Verifica se o sinal está abaixo do limite mínimo → desliga o motor

        Serial.println("SINAL MUITO FRACO → MOTOR DESLIGADO");
        Serial.println(rssi);
    }
Mostra o valor do sinal

    else if (rssi > rssiThreshold && rssi <= -65) {
Sinal entre o limite mínimo e -65 → vibração fraca:

        analogWrite(motorPin, 120);
Define intensidade da vibração (valor PWM)

        Serial.println(rssi);
        Serial.println("CELULAR DISTANTE → VIBRAÇÃO FRACA");
    } else if (rssi > -65 && rssi <= -50) {
Sinal entre -65 e -50 → vibração média:

        analogWrite(motorPin, 70);
        Serial.println(rssi);
        Serial.println("CELULAR PRÓXIMO → VIBRAÇÃO MÉDIA");
    } else if (rssi > -50 && rssi < 0) {
Sinal acima de -50 → vibração forte:

        analogWrite(motorPin, 1);
PWM baixo, mas motor forte (ajuste pode ser necessário de acordo com as medidas e materiais do protótipo).

        Serial.println(rssi);
        Serial.println("CELULAR MUITO PRÓXIMO → VIBRAÇÃO FORTE"); 
    } else {
        analogWrite(motorPin, 255);
        Serial.println("Rede não encontrada. MOTOR DESLIGADO");
    }
Caso a rede não tenha sido encontrada no início, garante que o motor esteja desligado.

    delay(1000);
    }
Aguarda 1 segundo antes de verificar novamente.

### Montagem do circuito

#### Pinos no ESP32, nos sensores e nos atuadores:

- Motor ->

    - Fio amarelo no `3v3` do ESP32

    - Fio verde no `pino esquerdo` do transistor;

- Transistor ->

    - Fio verde do motor vibratório no `pino esquerdo`;

    - Fio cinza do `D2` do ESP32 no `pino central`;

    - Fio azul do `GND` do ESP32 no `pino direito`.

*Mais detalhes da ideação, testes e execução no nosso site [Busca Silenciosa](https://sites.google.com/cesar.school/g18-buscasilenciosa/status-report-1).