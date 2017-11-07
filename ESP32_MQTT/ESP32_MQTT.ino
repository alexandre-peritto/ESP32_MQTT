#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN 16
#define DHTTYPE DHT22

const char* ssid = "AbusadorDeMacanetas";
const char* password = "12345678";
const char* mqttServer = "192.168.137.1";
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(115200);
	dht.begin();
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.println("Connecting to WiFi..");
	}
	Serial.println("Connected to the WiFi network");
	client.setServer(mqttServer, mqttPort);
	while (!client.connected()) {
		Serial.println("Connecting to MQTT...");
		if (client.connect("ESP32Client")) {
			Serial.println("connected");
		}
		else {
			Serial.print("failed with state ");
			Serial.print(client.state());
			delay(2000);
		}
	}
}

void loop() {
	StaticJsonBuffer<300> JSONbuffer;
	JsonObject& root = JSONbuffer.createObject();

	auto temperatura = dht.readTemperature();
	auto humidade = dht.readHumidity();
	root["sensor"] = "DHT22";
	root["temperatura"] = temperatura;
	root["humidade"] = humidade;

	char JSONmessageBuffer[100];
	root.printTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
	Serial.println("Sending message to MQTT topic..");
	Serial.println(JSONmessageBuffer);

	if (client.publish("temp-humid/mesa-alexandre", JSONmessageBuffer) == true) {
		Serial.println("Success sending message:");
		Serial.println(JSONmessageBuffer);
	}
	else {
		Serial.println("Error sending message");
	}

	client.loop();
	Serial.println("-------------");

	delay(10000);

}
