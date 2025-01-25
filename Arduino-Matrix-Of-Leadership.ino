#include <Arduino.h>

const int ledPin = 3;

void breathingEffect(int delayONSegundos = 1,int delayOFFSegundos = 1,int velocidadEncendido = 10, int velocidadApagado = 0) {  
  // Si el valor de velocidad es negativo, se aplica la velocidad de apagado
  if (velocidadApagado <= 0) 
    velocidadApagado = velocidadEncendido;
  
  // Transforma milisegundos en segundos
  delayONSegundos = delayONSegundos * 1000;
  delayOFFSegundos = delayOFFSegundos * 1000;
  
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
}

void loop() {
  breathingEffect(1, 10, 10);
}


