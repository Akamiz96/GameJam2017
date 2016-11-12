#include <OneWire.h> //Se importan las librerías
#include <DallasTemperature.h>

#define Pin 2 //Se declara el pin donde se conectará la DATA

OneWire ourWire(Pin); //Se establece el pin declarado como bus para la comunicación OneWire

DallasTemperature sensors(&ourWire); //Se instancia la librería DallasTemperature

#include <DHT11.h>

int pin = 3;
DHT11 dht11(pin);

void setup() {
  delay(1000);
  Serial.begin(9600);
  sensors.begin(); //Se inician los sensores
  for (int i = 13; i > 4; i--) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {
  unsigned long Time = 0;
  unsigned short caso = 1;
  int err;
  float temp, hum;
  while (1) {
    switch (caso) {
      case 1:
        //Rojo semaforo 1
        Semaforo1(caso);
        //Rojo Semaforo 2
        Semaforo2(caso);
        //Verde Semaforo 3
        Semaforo3(caso);
        //Verde Semaforo 4
        Semaforo4(caso);
        //Lectura de sensores
        sensors.requestTemperatures();
        err = dht11.read(hum, temp);
        if (millis() - Time > 1000) {
          caso = 2;
          Time = millis();
        }
        break;
      case 2:
        //AmarilloRojo Semaforo 1
        Semaforo1(caso);
        //AmarilloRojo Semaforo 2
        Semaforo2(caso);
        //Amarillo Semaforo 3
        Semaforo3(caso);
        //Amarillo Semaforo 4
        Semaforo4(caso);
        //Lectura de sensores
        sensors.requestTemperatures();
        err = dht11.read(hum, temp);
        if (millis() - Time > 1000) {
          caso = 3;
          Time = millis();
        }
        break;
      case 3:
        //Verde Semaforo 1
        Semaforo1(caso);
        //Verde Semaforo 2
        Semaforo2(caso);
        //Rojo Semaforo 3
        Semaforo3(caso);
        //Rojo Semaforo 4
        Semaforo4(caso);
        //Lectura de sensores
        sensors.requestTemperatures();
        err = dht11.read(hum, temp);
        if (millis() - Time > 2000) {
          caso = 4;
          Time = millis();
        }
        break;
      case 4:
        //Amarillo Semaforo 1
        Semaforo1(caso);
        //Amarillo Semaforo 2
        Semaforo2(caso);
        //AmarilloRojo Semaforo 3
        Semaforo3(caso);
        //AmarilloRojo Semaforo 4
        Semaforo4(caso);
        //Lectura de sensores
        sensors.requestTemperatures();
        err = dht11.read(hum, temp);
        if (millis() - Time > 1000) {
          caso = 1;
          Time = millis();
        }
        break;
    }
  }
}
void Semaforo1(unsigned short caso) {
  if (caso == 1) {
    //Rojo semaforo 1
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  if (caso == 2) {
    //AmarilloRojo Semaforo 1
    digitalWrite(6, HIGH);
  }
  if (caso == 3) {
    //Verde Semaforo 2
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  if (caso == 4) {
    //Amarillo Semaforo 1
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
}
void Semaforo2(unsigned short caso) {
  if (caso == 1) {
    //Rojo semaforo 1
    digitalWrite(A2, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
  }
  if (caso == 2) {
    //AmarilloRojo Semaforo 2
    digitalWrite(A1, HIGH);
  }
  if (caso == 3) {
    //Verde Semaforo 2
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
  }
  if (caso == 4) {
    //Amarillo Semaforo 2
    digitalWrite(A1, HIGH);
    digitalWrite(A0, LOW);
  }
}
void Semaforo3(unsigned short caso) {
  if (caso == 1) {
    //Verde Semaforo 3
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
  if (caso == 2) {
    //Amarillo Semaforo 3
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
  if (caso == 3) {
    //Rojo Semaforo 3
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  if (caso == 4) {
    //AmarilloRojo Semaforo 3
    digitalWrite(12, HIGH);
  }
}
void Semaforo4(unsigned short caso) {
  if (caso == 1) {
    //Verde Semaforo 4
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if (caso == 2) {
    //Amarillo Semaforo 4
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  if (caso == 3) {
    //Rojo Semaforo 4
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  }
  if (caso == 4) {
    //AmarilloRojo Semaforo 4
    digitalWrite(9, HIGH);
  }
}
//  sensors.requestTemperatures(); //Prepara el sensor para la lectura
//  Serial.print(sensors.getTempCByIndex(0)); //Se lee e imprime la temperatura en grados Celsius
//  Serial.print(sensors.getTempFByIndex(0)); //Se lee e imprime la temperatura en grados Fahrenheit
//  int err;
//  float temp, hum;
//  if ((err = dht11.read(hum, temp)) == 0)   // Si devuelve 0 es que ha leido bien
//  {
//    Serial.print("Temperatura: ");
//    Serial.print(temp);
//    Serial.print(" Humedad: ");
//    Serial.print(hum);
//    Serial.println();
//  }
//  else
//  {
//    Serial.println();
//    Serial.print("Error Num :");
//    Serial.print(err);
//    Serial.println();
//  }
//  delay(1000); //Se provoca un lapso de 1 segundo antes de la próxima lectura

