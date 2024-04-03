/* 

  COMUNICACION SERIAL - CONTADOR BINARIO DE 4 BITS - ARDUINO UNO R3
  Benjamin Hernández Herrera

*/

#include "Arduino.h"

// Definición de pines para conectar LEDs
const int ledPins[] = {2, 3, 4, 5}; // Pines para conectar los LEDs
const int numPins = 4; // Número de LEDs
const int limite  = pow(2, numPins);

void setup() {

  
  // Configuración de los pines de los LEDs
  for (int i = 0; i < numPins; i++) {
    pinMode(ledPins[i], OUTPUT); // Configurar los pines como salida
  }
}

void ascendente(){
static int contador = 0; // Variable para almacenar el valor del contador
  
  // Convertir el contador a binario y mostrarlo en los LEDs
  for (int i = 0; i < numPins; i++) {
    digitalWrite(ledPins[i], (contador >> i) & 1); // Configurar los pines de acuerdo al bit correspondiente del contador
  }
  
  delay(1000); // Esperar un segundo
  
  // Incrementar el contador y volver a 0 si alcanza 16 (0000 a 1111)
  contador++;
  if (contador == limite) {
    contador = 0;
  }
}

void descendente(){
static int contador = limite - 1; // Variable para almacenar el valor del contador
  
  // Convertir el contador a binario y mostrarlo en los LEDs
  for (int i = 0; i < numPins; i++) {
  // Configurar los pines de acuerdo al bit correspondiente del contador
    digitalWrite(ledPins[i], (contador >> i) & 1); 
  }
  
  delay(1000); // Esperar un segundo
  
  // Incrementar el contador y volver a 0 si alcanza 16 (0000 a 1111)
  contador--;
  if (contador == 0) {
    contador = limite;
  }
}

void loop() {
  
  ascendente();
  // descendente();
  
}