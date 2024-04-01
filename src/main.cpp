#include <Arduino.h>

//Blinking LED and serial communicaction

int pinLed = 8; //pin donde se conecta el led
int numBlinks;

// Strings del estado del led
String LedOnMessage = "LED is turned ON: ";
String LedOffMessage = "LED is turned OFF: ";

void setup() {
    // Inicializa el LED apagado
    pinMode(pinLed, OUTPUT);
    digitalWrite(pinLed, LOW);

    // Inicializa la consola serial
    Serial.begin(9600);
}

void loop() {


    //Solicita el numero de parpadeos hasta que la consola no se encuentre disponible
    Serial.println("Veces que quieres que se encienda y se apague el led");
    while(Serial.available() == 0){}

    numBlinks = Serial.parseInt();
    Serial.print("El usuario indica que el led va a encenderse y apagarse: ");
    Serial.print(numBlinks);
    Serial.print("veces.");

    // Enciende y apaga el LED el numero de parpadeos
    for (int counter = 1; counter <= numBlinks; counter++){
        // Enciende el led por 1 segundo e imprime el estado en la consola serial
        Serial.println(LedOnMessage +  counter);
        digitalWrite(pinLed, HIGH);
        delay(1000);

        // Apaga el led por 1 segundo e imprime el estado en la consola serial
        Serial.println(LedOnMessage +  counter);
        digitalWrite(pinLed, LOW);
        delay(1000);
    }
    
}
