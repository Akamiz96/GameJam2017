//Módulo Lector RFID-RC522 RF

#include <SPI.h>
#include <MFRC522.h>
#include <RFID.h>

RFID rfid(10, 5);
int llavero[5] = {246, 37, 89, 143, 5};
void setup()
{
  Serial.begin(9600);
  SPI.begin(); rfid.init();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}


void loop()
{
  bool aceptada = false, Nodiferente = true;
  unsigned long Time = 0, TimePaso = 0;
  unsigned short caso = 1;
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
        if (millis() - Time > 1000) {
          caso = 2;
          Time = millis();
        }
        if (rfid.isCard()) { //Verifica si hay una tarjeta
          if (rfid.readCardSerial()) { //Funcion que lee la tarjeta
            for (int i = 0; i <= 4; i++) {
              if (llavero[i] != rfid.serNum[i])
                Nodiferente = false;
            }
          }
          rfid.halt();
          aceptada = false;
          if (Nodiferente) {
            aceptada = true;
            Serial.println("CORRECTO");
          }
          if (aceptada) {
            paso(&TimePaso, &caso, &Nodiferente);
          }
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
        if (millis() - Time > 1000) {
          caso = 3;
          Time = millis();
        }
        if (rfid.isCard()) { //Verifica si hay una tarjeta
          if (rfid.readCardSerial()) { //Funcion que lee la tarjeta
            for (int i = 0; i <= 4; i++) {
              if (llavero[i] != rfid.serNum[i])
                Nodiferente = false;
            }
          }
          rfid.halt();
          aceptada = false;
          if (Nodiferente) {
            aceptada = true;
            Serial.println("CORRECTO");
          }
          if (aceptada) {
            paso(&TimePaso, &caso, &Nodiferente);
          }
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
        if (millis() - Time > 2000) {
          caso = 4;
          Time = millis();
        }
        if (rfid.isCard()) { //Verifica si hay una tarjeta
          if (rfid.readCardSerial()) { //Funcion que lee la tarjeta
            for (int i = 0; i <= 4; i++) {
              if (llavero[i] != rfid.serNum[i])
                Nodiferente = false;
            }
          }
          rfid.halt();
          aceptada = false;
          if (Nodiferente) {
            aceptada = true;
            Serial.println("CORRECTO");
          }
          if (aceptada) {
            paso(&TimePaso, &caso, &Nodiferente);
          }
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
        if (millis() - Time > 1000) {
          caso = 1;
          Time = millis();
        }
        if (rfid.isCard()) { //Verifica si hay una tarjeta
          if (rfid.readCardSerial()) { //Funcion que lee la tarjeta
            for (int i = 0; i <= 4; i++) {
              if (llavero[i] != rfid.serNum[i])
                aceptada = false;
            }
          }
          rfid.halt();
          aceptada = false;
          if (Nodiferente) {
            aceptada = true;
            Serial.println("CORRECTO");
          }
          if (aceptada) {
            paso(&TimePaso, &caso, &Nodiferente);
          }
        }
        break;
    }
  }
}
void paso(unsigned long * Timepaso, unsigned short * caso, bool * Nodiferente) {
  if (*caso != 3) {
    *caso = 3;
  }
  *Nodiferente = true;
}
void Semaforo1(unsigned short caso) {
  if (caso == 1) {
    //Rojo semaforo 1
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
  }
  if (caso == 2) {
    //AmarilloRojo Semaforo 1
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  if (caso == 3) {
    //Verde Semaforo 2
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  if (caso == 4) {
    //Amarillo Semaforo 1
    digitalWrite(6, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
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
    digitalWrite(A2, HIGH);
    digitalWrite(A0, LOW);
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
    digitalWrite(A2, LOW);
  }
}
void Semaforo3(unsigned short caso) {
  if (caso == 1) {
    //Verde Semaforo 4
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  if (caso == 2) {
    //Amarillo Semaforo 3
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }
  if (caso == 3) {
    //Rojo Semaforo 3
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (caso == 4) {
    //AmarilloRojo Semaforo 3
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  }
}
void Semaforo4(unsigned short caso) {
  if (caso == 1) {
    //Verde Semaforo 3
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  }
  if (caso == 2) {
    //Amarillo Semaforo 4
    digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
  }
  if (caso == 3) {
    //Rojo Semaforo 4
    digitalWrite(A5, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
  }
  if (caso == 4) {
    //AmarilloRojo Semaforo 4
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
    digitalWrite(A3, LOW);
  }
}
