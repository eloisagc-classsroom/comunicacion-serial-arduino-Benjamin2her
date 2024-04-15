/* 

  COMUNICACION SERIAL - CONTADOR BINARIO DE 4 BITS - ARDUINO UNO R3
  Benjamin Hernández Herrera

*/

#include "Arduino.h"
bool selectMode = true;

// Definición de pines para conectar LEDs
const int ledPins[] = {2, 3, 4, 5}; // Pines para conectar los LEDs
const int numPins = 4; // Número de LEDs
const int limite  = pow(2, numPins);
int opcion;

void mostrarContador(int contador);
void ascendente();
void descendente();

void setup() {

  
  // Configuración de los pines de los LEDs
  for (int i = 0; i < numPins; i++) {
    pinMode(ledPins[i], OUTPUT); // Configurar los pines como salida
  }
  Serial.begin(9600);

  

  
}


void loop() {
  if (selectMode){
    Serial.println("Selecciona una opcion: ");
    Serial.println("1. Ascendente");
    Serial.println("2. Descendente");
    while(Serial.available() == 0){
  
    }
    opcion = Serial.parseInt();
  }
  


  switch (opcion)
  {
  case 1:
    ascendente();
    break;
  
  case 2:
    descendente();
    break;
  default:
    Serial.println("Opción no válida");
    break;
  }
  
}


void mostrarContador(int contador) {
  // Convertir el contador a binario y mostrarlo en los LEDs
  for (int i = numPins - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], (contador >> i) & 1); // Configurar los pines de acuerdo al bit correspondiente del contador
    Serial.print(digitalRead(ledPins[i]));
  }
  Serial.print(" - Decimal: ");
  Serial.println(contador);
}

void ascendente(){
  static int contador = 0; // Variable para almacenar el valor del contador
  
  mostrarContador(contador);
  
  delay(750); // Esperar un segundo
  
  // Incrementar el contador y volver a 0 si alcanza 16 (0000 a 1111)
  contador++;
  selectMode = false;
  if (contador == limite) {
    contador = 0;
    selectMode = true;
  }
}

void descendente(){
  static int contador = limite - 1; // Variable para almacenar el valor del contador
  
  mostrarContador(contador);
  
  delay(750); // Esperar un segundo
  
  // Incrementar el contador y volver a 0 si alcanza 16 (0000 a 1111)
  
  selectMode = false;
  contador--;
  if (contador < 0) {
    contador = limite - 1;
    selectMode = true;
  }
}