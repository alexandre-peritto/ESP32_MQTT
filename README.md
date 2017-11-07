# ESP32_MQTT
Estudo utilizando o protocolo MQTT no ESP32 para enviar dados de temperatura e humidade através de um Broker Mosquitto rodando em um Container Docker no Windows.

Gerenciador de Containers: Docker for Windows [https://www.docker.com/docker-windows]

Container com Broker MQTT: eclipse-mosquito [https://hub.docker.com/_/eclipse-mosquitto/]

Subscriber MQTT PC: MQTTLENS (App Chrome) [https://chrome.google.com/webstore/detail/mqttlens/hemojaaeigabkbcookmlgmdigohjobjm]

Subscriber Android: MQTT Dash [https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=pt_BR]

-----------------------------------------------------------------------

Poderia ser feito com a IDE do Arduino, mas para facilitar a programação com o intellicence e tirar vantagem das classes do C++ de forma mais simplificada estou utilizando a seguinte configuração:

IDE: Visual Studio Community 2017 [https://www.visualstudio.com/pt-br/downloads/]

Plugin Arduino: Visual Micro [http://www.visualmicro.com/]