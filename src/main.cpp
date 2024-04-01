#include <Arduino.h>

//Blinking LED and serial communicaction

int pinLed = 8; //pin donde se conecta el led
void setup() {
    
    // Inicializa el LED apagado
    pinMode(pinLed, OUTPUT);
    digitalWrite(pinLed, LOW);

    // Inicializa la consola serial
    Serial.begin(9600);
}

void loop() {
    // Enciende el led por 1 segundo e imprime el estado en la consola serial
    Serial.println("LED is turned on");
    digitalWrite(pinLed, HIGH);
    delay(1000);

    // Apaga el led por 1 segundo e imprime el estado en la consola serial
    Serial.println("LED is turned off");
    digitalWrite(pinLed, LOW);
    delay(1000);
}
