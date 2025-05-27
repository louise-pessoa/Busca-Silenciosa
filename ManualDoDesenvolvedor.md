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

![imagens do circuito](link)

    #include <WiFi.h>
Esse trecho do código ele inicializa a função wi-fi no ESP32.

    const char* targetSSID = "InternetNet";
    const char * password= "abcdefgh";
Nessa parte define o nome da rede de internet e a senha da rede.
    
    int motorPin = 2;
Essa linha define a porta qu o motor de vibração utilizará.    
    
    const int rssiThreshold = -80;
    int indice=0;
    bool redeEncontrada = false;
Essas 3 variáveis que estão sendo inicializadas são utilizadas durante do decorrer do código e quando elas forem utilizadas explicaremos sua função.


descrição do bloco de código

![imagens do funcionamento (passo a passo)](link)

<!--
como a versão final funciona?
acredito que só dá para fazer essa parte quando tiver tudo pronto (pelo menos do código e do circuito).
-->

*Mais detalhes da ideação, testes e execuçãos no nosso site [Busca SIlenciosa](https://sites.google.com/cesar.school/g18-buscasilenciosa/status-report-1).
