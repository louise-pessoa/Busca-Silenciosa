# MANUAL DO DESENVOLVEDOR: 

### Como o projeto foi pensado e executado? 

## **1. Ideação**💡

- 

*Mais detalhes no [nosso site](https://sites.google.com/cesar.school/g18-buscasilenciosa/status-report-1?authuser=0).

## **2. Materiais, conhecimentos e plataformas**

### Materiais🛠️

- ESP32

- Cabo USB-MicroUSB

- Powerbank 10.000 mAh

- Motor vibratório 1027 (Vibracall)

- Protoboard

- Fios "macho-macho" e "macho-fêmea"

### Conhecimentos🧠

- Circuitos de microcontroladores (como Arduino)

- C++

- Conexão WiFi do ESP32 (Station X Acess Point)

### Plataformas🚉

- _ArduinoIDE_: testes de circuito

    - Board "ESP32 Dev Module"

- _GitHub_ e _VSCode_: atualizações do repositório

## **3. Execução**

### Testes🎳

Iniciamos os testes com um circuito básico, usando a gradação das cores de uma <ins>LED RGB</ins> para indicar a quantidade de pessoas conectadas a uma rede WiFi gerada pelo ESP32. O código base para essa primeira etapa foi proporcionado por um grupo do semestre anterior que tinha um projeto um pouco parecido com o nosso.

Depois, testamos o funcionamento do motor vibratório com um código simples baseado em PWM, variando depois de um intervalo de 1 segundo (arquivo `MotorVibratorio.c++`).

<code>

    void setup() {
        pinMode(3, OUTPUT);
    }

    void loop() {
        analogWrite(3, 120);
        delay(1000);
        analogWrite(3,10);
        delay(1000);
    }
</code>

### Desenvolvimento🧩

### Versão final🏆