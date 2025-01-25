#include <Arduino.h>

// Declaracion de Pines
const int ledPin = 3;

// Variables para controlar LEDs
int delayONSegundos     = 1;
int delayOFFSegundos    = 1;
int velocidadEncendido  = 10;
int velocidadApagado    = 0;

void breathingEffect() {  
  for (int ledForce = 0; ledForce < 255; ledForce++) {
    analogWrite(ledPin, ledForce);
    delay(velocidadEncendido);
  }

  delay(delayONSegundos);

  for (int ledForce = 255; ledForce > 0; ledForce--) {
    analogWrite(ledPin, ledForce);
    delay(velocidadApagado);
  }
  delay(delayOFFSegundos);
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  if (velocidadApagado <= 0)
    velocidadApagado = velocidadEncendido;
  
  delayONSegundos = delayONSegundos * 1000;
  delayOFFSegundos = delayOFFSegundos * 1000;
}
// 1
void loop() {
  breathingEffect();
}


