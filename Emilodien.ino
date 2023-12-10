/* Melodien für Emil
Version 2.2   mit Weihnachtsliedern
              Progmem (sonst Konflikt mit max RAM bei mehr al 10 Liedern)

HW siehe Fritzing Schaltplan

  Melodien
    1 Mary has a little lamb        Internet
    2 ABC die Katze lief im Schnee  Das große Buch der Volkslieder
    3 Alle meine Entchen
    4 Kuckuck, Kuckuck
    5 Heidi
    6 Kuckuck und Esel

    https://kinderliederzummitsingen.de/
    7 Alle Jahre wieder
    8 Ihr Kinderlein kommet
    9 Kling Glöckchen

    9 Morgen kommt der Weihnachtsmann
    10 Weihnachtsbäckerei
    11 Nickolaus ist ein guter Mann
    12

*/

#include "Noten_min.h"    // nur 3 Oktaven

#define pause 0         // Pausenzeichen

#define Analog0 0          // Analog Eingang für Rauschen Zufallszahl


#define Selbstabschaltung 2 // PD2 für Transistor Abschaltung
#define Buzzer 3            // PD3 als Ansteuerung für passiven Buzzer
#define Soundmodul 4        // PD4 externes Soundmodul ISD1820

#define LED_onboard 13      // LED

#define Lied0 0    // Sound Modul
#define Lied1 1    // Lied
#define Lied2 2    // Lied
#define Lied3 3    // Lied
#define Lied4 4    // Lied
#define Lied5 5    // Lied
#define Lied6 6    // Lied
#define Lied7 7    // Lied
#define Lied8 8    // Lied
#define Lied9 9    // Lied
#define Lied10 10    // Lied
#define Lied11 11    // Lied
#define Lied12 12    // Lied
#define Lied13 13    // Lied
#define Lied14 14    // Lied
#define Lied15 15    // Lied
#define Lied16 16    // Lied
#define Lied17 17    // Lied
#define Lied18 18    // Lied
#define Lied19 19    // Lied
#define Anzahl_Lieder 19  // Anzahl für Auswahl über Zufallszahl Generator

int Zufallszahl;

int Blinken;    // LED onboard blinken

#define MaxToene 60   // Begrenzung für array

int melody[MaxToene];
int noteDurations[MaxToene];
//int noteAbstand[MaxToene];

int Anzahl_Bytes;   // Array Länge in Bytes
int Anzahl_Noten;   // Array Läneg in Variabeln

int Lied;         // ausgewähltes Lied


// **********  Mary has a little lamb ************

  const int Noten_1[] PROGMEM = {E5, D5, C5, D5, E5, E5, E5, D5, D5, D5, E5, G5, G5, E5, D5, C5, D5, E5, E5, E5, E5, D5, D5, E5, D5, C5};
  const int Dauer_1[] PROGMEM = {4,  4,  4,  4,  4,  4,  2,  4,  4,  2,  4,  4,  2,  4,  4,  4,  4,  4,  4,  2,  4,  4,  2,  4,  4,  1};


// ************* ABC die Katze lief im Schnee (Seite 263) ************

  const PROGMEM uint16_t Noten_2[] = {D5, F5, A5, pause, B5, A5, G5, F5, E5, D5, pause, A5, G5, F5, E5, D5, C5, D5, E5, A5, G5, F5, E5, D5, C5, D5, E5, D5, E5, A5, pause, AS5, A5, G5, F5, E5, D5};
  const PROGMEM uint16_t Dauer_2[] = { 2,  2,  2,     8,  8,  4,  4,  4,  4,  2,     8,  8,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,     8,   8,  4,  4,  4,  4,  4};


// *** Alle meine Entchen ***

  const PROGMEM uint16_t Noten_3[] = {C5, D5, E5, F5, G5, G5, pause, A5, A5, A5, A5, G5, pause, A5, A5, A5, A5, G5, pause, F5, F5, F5, F5, E5, E5, pause, D5, D5, D5, D5, C5};
  const PROGMEM uint16_t Dauer_3[] = { 4,  4,  4,  4,  2,  2,    16,  4,  4,  4,  4,  2,    16,  4,  4,  4,  4,  2,     16, 4,  4,  4,  4,  2,  2,    16,  4,  4,  4,  4,  2};


// *** Nr. 4 Kuckuck, Kuckuck, ruft's aus dem Wald   ***

  const PROGMEM uint16_t Noten_4[] = {G5, E5, pause, G5, E5, pause, F5, E5, D5, C5, pause, D5, D5, E5, F5, D5, pause, E5, E5, F5, G5, E5, pause, G5, E5, pause, G5, E5, pause, F5, E5, D5, C5, pause};
  const PROGMEM uint16_t Dauer_4[] = { 4,  4,     8,  4,  4,     8,  4,  4,  4,  2,     8,  4,  4,  4,  2,  4,     8,  4,  4,  4,  2,  4,     8,  4,  4,     8,  4,  4,     8,  4,  4,  4,  2,     8};


// ******* Nr. 5 Heidi **************

  const PROGMEM uint16_t Noten_5[] = {G5, E5, E6, C6, G5, G5, A5, A5, G5, E5, F5, E5, D5, D5, pause, F5, F5, D6, B5, B5, B5, B5, B5, A5,G5, A5, G5,E5, E5 };
  const PROGMEM uint16_t Dauer_5[] = { 2,  2,  2,  2,  4,  8,  8,  8,  4,  8,  4,  8,  8,  4,     8,  2,  2,  2,  2,  4,  8,  8,  8,  8, 4,  4,  8, 8, 4};


// ******* Nr. 6 Der Kuckuck und der Esel **************

  const PROGMEM uint16_t Noten_6[] = {C6, A5, C6, A5, C6, AS5, AS5, pause, AS5, G5, AS5, G5, AS5, A5, pause, C6, AS5, A5, A5, A5, A5, AS5, AS5, pause, AS5, A5, G5, G5, G5, G5, A5, A5, pause, F5, F5, G5, A5, AS5, C6, AS5, A5, A5, G5, G5, F5};
  const PROGMEM uint16_t Dauer_6[] = { 2,  4,  4,  4,  4,  4,    2,     8,  2,  4,    4,  4,   4,  2,     8,  8,   8,  4,  4,  4,   4,  4,   2,     8,   8,  8,  4,  4,  4,  4,  4,  2,     8,  4,  4,  4,  4,  4,   2,  2,   4,  4,  4,  4,  2};


// ******* Nr. 7 Alle Jahre wieder **************

  const PROGMEM uint16_t Noten_7[] = {A5,B5,A5,G5,F5,E5,D5,E5,F5,G5,F5,E5,F5,A5,AS5,A5,D6,C6,AS5,A5,G5,F5,G5,A5,G5};
  const PROGMEM uint16_t Dauer_7[] = {3, 6, 4, 4, 2, 2, 4, 8, 8, 4, 4, 1, 4, 4, 4, 4, 2, 4, 4, 4, 8, 8, 4, 4, 1};


// ******* Nr. 8 Ihr Kinderlein kommet **************

  const PROGMEM uint16_t Noten_8[] = {A5,A5,F5,A5,A5,F5,A5,G5,E5,G5,F5,0,A5,A5,F5,A5,A5,F5,A5,G5,E5,G5,F5,0,F5,E5,E5,E5,G5,G5,G5,F5,F5,F5,B5,B5,A5,A5,A5,D6,A5,F5,A5,G5,E5,D5};
  const PROGMEM uint16_t Dauer_8[] = {4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2,4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2};

// ******* Nr. 9 Kling Glöckchen **************

  const PROGMEM uint16_t Noten_9[] = {C6,A5,B5,C6,D6,C6,D6,C6,0, B5,G5,C6,A5,0,G5,G5,A5,F5,A5,G5,0,B5,B5,C6,G5,B5,A5,0,G5,G5,A5,AS5,C6,G5,0,A5,D6,C6,AS5,D6,C6}; //,0,A5,B5,C6,D6,C6,D6,C6,0,B5,G5,C6,A5};
  const PROGMEM uint16_t Dauer_9[] = {2, 4, 4, 6, 6, 6, 6, 2, 8, 2, 4, 4, 2, 8, 2, 4, 4, 4, 2, 2,8,2, 4, 4, 4, 2, 2, 8, 2, 4, 4, 4, 2, 4, 8, 2, 4, 4,  4, 2, 4}; //, 4,4, 4, 6, 6, 6, 6, 2, 4,2, 4, 4, 2};

// ******* Nr. 10 Weinachtsbäckerei **************

  const PROGMEM uint16_t Noten_10[] = {G4,F5,E5,E5,D5,D5,C5,0,D5,E5,F5,F5,E5,E5,D5,0,D5,E5,F5,F5,G5,0,D5,E5,F5,F5,G5,0,G5,F5,E5,E5,G5,G5,D5,D5,G5,0,G5,F5,E5,E5,D5,D5,C5};
  const PROGMEM uint16_t Dauer_10[] = {3, 6, 4, 4, 4, 4, 2, 8,3, 6, 4, 4, 4, 4, 2, 8,3, 6, 4, 4, 4, 8,3, 6, 4, 4, 4, 8,3, 6, 4, 4, 4, 4, 4, 4, 4, 8,3, 6, 4, 4, 4, 4, 2};

// ******* Nr. 11 Morgen kommt der Weinachtsmann **************

  const PROGMEM uint16_t Noten_11[] = {G5,G5,D6,D6,E6,E6,D6,C6,C6,B5,B5,A5,G5,0,D6,D6,C6,C6,B5,B5,A5,D6,D6,C6,C6,B5,B5,A5,G5,G5,D6,D6,E6,E6,D6,C6,C6,B5,B5,A5,G5};
  const PROGMEM uint16_t Dauer_11[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 4, 6,4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 2};

// ******* Nr. 12 Advent, Advent **************

  const PROGMEM uint16_t Noten_12[] = {G5,D5,E5,D5,0,G5,D5,E5,D5,0,E5,F5,G5,A5,D5,G5,A5,AS5,0,AS5,C6,AS5,A5,G5,E5,A5,F5,G5};
  const PROGMEM uint16_t Dauer_12[] = {6, 3, 6, 3, 8,6, 3, 6, 3, 8,6, 3, 6, 3, 6, 3, 6, 3,  8,6,  3, 6,  3, 6, 6, 6, 4, 2};

// ******* Nr. 13 Leise rieselt der Schnee **************

  const PROGMEM uint16_t Noten_13[] = {B5,B5,A5,B5,A5,G5,0,G5,E5,G5,F5,E5,D5,0,A5,GS5,A5,C6,B5,A5,G5,0,A5,E5,E5,F5,E5,F5,G5};
  const PROGMEM uint16_t Dauer_13[] = {2, 4, 4, 4, 4, 2,10,2, 4, 4, 4, 4, 2,10,4, 4,  4, 4, 4, 4, 2,10,3, 6, 4, 4, 4, 4, 2};

// ******* Nr. 14 Lasst uns froh und munter sein **************

  const PROGMEM uint16_t Noten_14[] = {A5,A5,A5,B5,A5,G5,F5,F5,F5,0,G5,G5,G5,A5,G5,F5,E5,E5,E5,0,D5,E5,F5,G5,A5,B5,A5,B5,A5,0,D6,A5,A5,B5,A5,G5,F5,E5,A5,0,D6,A5,A5,B5,A5,G5,F5,E5,D5};
  const PROGMEM uint16_t Dauer_14[] = {4, 4, 6, 6, 6, 6, 4, 4, 3,10,4, 4, 6, 6, 6, 6, 4, 4, 3,10,4, 4, 4, 4, 6, 8, 6, 6, 2,10,4, 4, 6, 6, 6, 6, 4, 4, 2,10,4, 4, 6, 6, 6, 6, 4, 4, 2};

// ******* Nr. 15 Schneeflöckchen Weißröckchen **************

  const PROGMEM uint16_t Noten_15[] = {E5,F5,G5,G5,A5,D5,D5,D5,E5,F5,F5,G5,E5,0,E5,F5,G5,G5,C6,B5,A5,G5,F5,E5,F5,D5,C5};
  const PROGMEM uint16_t Dauer_15[] = {6, 6, 4, 4, 4, 4, 4, 6, 6, 4, 4, 4, 2,10,6, 6, 4, 4, 4, 4, 4, 6, 6, 4, 4, 4, 2};

// ******* Nr. 16 Am Weihnachtsbaum die Lichter brennen **************

  const PROGMEM uint16_t Noten_16[] = {C5,C5,E5,G5,E5,G5,C6,A5,G5,E5,0,G5,A5,G5,F5,D5,G5,G5,D5,0,E5,E5,G5,F5,D5,F5,F5,A5,G5,E5,E5,E5,G5,F5,D5,G5,G5,E5};
  const PROGMEM uint16_t Dauer_16[] = {6, 6, 6, 4, 6, 6, 6, 6, 4, 6,10,6, 6, 6, 4, 4, 6, 6, 4,10,6, 6, 6, 4, 6, 6, 6, 6, 4, 6, 6, 6, 6, 4, 4, 6, 6, 3};

// ******* Nr. 17 O Tannenbaum **************

  const PROGMEM uint16_t Noten_17[] = {C5,F5,F5,F5,G5,A5,A5,A5,G5,A5,B5,E5,G5,F5,0,C6,C6,A5,D6,C6,C6,B5,B5,B5,B5,G5,C6,B5,B5,A5,A5,0,C5,F5,F5,F5,G5,A5,A5,A5,A5,G5,A5,B5,E5,G5,F5};
  const PROGMEM uint16_t Dauer_17[] = {6, 3, 8, 3, 6, 3, 8, 3, 6, 6, 4, 4, 4, 4,10,6, 6, 6, 3, 6, 6, 6, 3, 6, 6, 6, 3, 6, 6, 6, 4,10,6, 3, 8, 3, 6, 3, 8, 3, 6, 6, 6, 4, 4, 4, 2};

// ******* Nr. 18 Morgen Kinder wirds was geben **************

  const PROGMEM uint16_t Noten_18[] = {F5,C5,D5,C5,D5,F5,E5,G5,F5,C5,0,A5,A5,B5,C6,A5,B5,A5,G5,0,F5,C5,D5,C5,D5,F5,E5,G5,F5,C5,A5,A5,B5,C6,A5,B5,A5,G5,0,B5,B5,D6,D6,G5,G5,C6,0,F5,F5,B5,B5,A5,G5,F5,E5,F5};
  const PROGMEM uint16_t Dauer_18[] = {4, 4, 4, 4, 6, 6, 6, 6, 4, 4,10, 4, 6, 6, 4, 4, 4, 4, 2, 8,4, 4, 4, 4, 6, 6, 6, 6, 4, 4, 4, 6, 6, 4, 4, 4, 4, 2, 8,4, 4, 4, 4, 4, 4, 3, 8,4, 4, 4, 4, 6, 6, 6, 6, 2};

// ******* Nr. 19 O du fröhliche **************

  const PROGMEM uint16_t Noten_19[] = {G5,A5,G5,F5,E5,F5,0,G5,A5,G5,F5,E5,F5,0,G5,G5,A5,B5,C6,B5,A5,G5,0,D5,E5,D5,E5,F5,G5,F5,0,E5,F5,E5,F5,G5,A5,G5,0,C6,B5,A5,G5,C6,A5,G5,F5,E5,D5,C5};
  const PROGMEM uint16_t Dauer_19[] = {2, 2, 3, 6, 4, 4,12,2, 2, 3, 6, 4, 4,12,2, 2, 2, 4, 4, 2,  2, 1,10,3, 6, 4, 4, 3, 6, 2,10,3, 6, 4, 4, 3, 6, 2,10,4,4,  4, 4, 4, 4, 4, 4, 2, 2, 1};


void setup() {
  // iterate over the notes of the melody:

  pinMode(Selbstabschaltung,OUTPUT);
  digitalWrite(Selbstabschaltung, HIGH);    // Batterie Spannung halten (Transistor sofort ein)

  pinMode(Buzzer,OUTPUT);
  digitalWrite(Buzzer, LOW);              // Buzzer Ansteuerung AUS

  pinMode(Soundmodul,OUTPUT);
  digitalWrite(Soundmodul, LOW);          // Soundmodul AUS


  randomSeed(analogRead(A0));     // Zufall abhängig von Rauschen auf Analog Eingang
  Zufallszahl= random(Anzahl_Lieder-1);   // 0.. Anzahl Lieder -1
  Lied  = Zufallszahl+1;                  // 0= Sound Modul aktivieren  vorläufig unterdrücken::  1... Anzahl Lieder

  // für debug Lied fix auswählen
  //Lied=11;

  Serial.begin(9600);
  while (!Serial) {;}  // warten bis der serielle Port verbunden
  Serial.print("Lied= ");
  Serial.println(Lied);


  switch (Lied) {    // Melodie Auswahl
    case Lied0:     // Sound Modul ansteuern
      digitalWrite(Soundmodul,HIGH);    // Soundmodul aktivieren
      delay(3000);                      // xx Sekunden laufen lassen
      digitalWrite(Soundmodul,LOW);
    break;

    case Lied1:
      Anzahl_Bytes=sizeof(Noten_1);
      memcpy_P(melody, Noten_1, Anzahl_Bytes);    // memcpy_P(Ziel, Quelle aus Flash, Anzhal Bytes)
      memcpy_P(noteDurations, Dauer_1, Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_1,Anzahl_Bytes);

        /*for (int thisNote = 0; thisNote <= Anzahl_Bytes/2-1; thisNote++) {        // Zugriff stimmt noch nicht !!!!!!!!!!!!!
          Serial.print(pgm_read_word(Noten_1+thisNote));
          Serial.print("=");
          Serial.print(melody[thisNote]);
          Serial.print(",");
          Serial.print(noteDurations[thisNote]);
          Serial.print(" ");
        }*/

    break;

    case Lied2:
      Anzahl_Bytes=sizeof(Noten_2);
      memcpy_P(melody, Noten_2, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_2,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_2,Anzahl_Bytes);
      break;

    case Lied3:
      Anzahl_Bytes=sizeof(Noten_3);    // Achtung sizeof = ANzahl Bytes nicht Anzahl Variabeln
      memcpy_P(melody, Noten_3, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_3,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied4:
      Anzahl_Bytes=sizeof(Noten_4);
      memcpy_P(melody, Noten_4, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_4,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_4,Anzahl_Bytes);
    break;

    case Lied5:
      Anzahl_Bytes=sizeof(Noten_5);
      memcpy_P(melody, Noten_5, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_5,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_5,Anzahl_Bytes);
    break;

    case Lied6:
      Anzahl_Bytes=sizeof(Noten_6);
      memcpy_P(melody, Noten_6, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_6,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_6,Anzahl_Bytes);
    break;

    case Lied7:
      Anzahl_Bytes=sizeof(Noten_7);
      memcpy_P(melody, Noten_7, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_7,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied8:
      Anzahl_Bytes=sizeof(Noten_8);
      memcpy_P(melody, Noten_8, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_8,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied9:
      Anzahl_Bytes=sizeof(Noten_9);
      memcpy_P(melody, Noten_9, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_9,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied10:
      Anzahl_Bytes=sizeof(Noten_10);
      memcpy_P(melody, Noten_10, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_10,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied11:
      Anzahl_Bytes=sizeof(Noten_11);
      memcpy_P(melody, Noten_11, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_11,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied12:
      Anzahl_Bytes=sizeof(Noten_12);
      memcpy_P(melody, Noten_12, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_12,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied13:
      Anzahl_Bytes=sizeof(Noten_13);
      memcpy_P(melody, Noten_13, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_13,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied14:
      Anzahl_Bytes=sizeof(Noten_14);
      memcpy_P(melody, Noten_14, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_14,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied15:
      Anzahl_Bytes=sizeof(Noten_15);
      memcpy_P(melody, Noten_15, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_15,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied16:
      Anzahl_Bytes=sizeof(Noten_16);
      memcpy_P(melody, Noten_16, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_16,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied17:
      Anzahl_Bytes=sizeof(Noten_17);
      memcpy_P(melody, Noten_17, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_17,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied18:
      Anzahl_Bytes=sizeof(Noten_18);
      memcpy_P(melody, Noten_18, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_18,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case Lied19:
      Anzahl_Bytes=sizeof(Noten_19);
      memcpy_P(melody, Noten_19, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_19,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

  }

Anzahl_Noten= Anzahl_Bytes/2;    // Achtung sizeof = Anzahl Bytes nicht Anzahl Variabeln

Serial.print("Anzahl Noten= ");
Serial.print(Anzahl_Noten);
Serial.print(" ");
Serial.print("Bytes=");
Serial.println(Anzahl_Bytes);


  if (!Lied==Lied0) {
    for (int thisNote = 0; thisNote <= Anzahl_Noten-1; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;

      if (!melody[thisNote]==pause) {     // Note spielen
        tone(Buzzer, melody[thisNote], noteDuration);
      }
      else {      // Pause statt Note
        delay(noteDuration);
      }
          Serial.print(thisNote);
          Serial.print("/");
          Serial.print(pauseBetweenNotes);
          Serial.print(" ");

      if (pauseBetweenNotes <0) {
        pauseBetweenNotes= 1000;      // Pause bergenzen, fall Fehler im Array
      }


      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(Buzzer);

    }

    Serial.println("");
    Serial.println("Melodie beendet");
    }

    // Wartezeit 6s, damit nicht endlos dudelt (LED blinkt)
    for (int blinken=1; blinken >6; blinken++) {
      pinMode(LED_onboard,OUTPUT);
      digitalWrite(LED_onboard, LOW);
      delay(500);
      digitalWrite(LED_onboard,HIGH);
      delay(500);
    }

    Serial.println("Wartezeit beendet");

    digitalWrite(Selbstabschaltung, LOW);  // Batterie Spannung abschalten

}


void loop() {
  // no need to repeat the melody.
}

/*
Test für Ansteuerung ohne Tone() (Toen kann nur 1 Kanal bedienen)
für polphone Töne (z.B. 2..3 Buzzer parallel)

#define Ausgang 8             // PD8 über 1 kOhm an Piezo

const long Frequenz=440;   // in Hz
const long Faktor_microsec= 1000000;  // sec zu

const long Tastverhaeltnis= 10;     // Tastverhältnis in %


long Periode=0;          // in µsec
long Pulspause=0;       // in µesc
long Pulsdauer=0;       // in µsec

bool Ton_ein=false;

void setup() {

  pinMode(Ausgang,OUTPUT);
  digitalWrite(Ausgang, HIGH);


  Periode = Faktor_microsec / Frequenz;  // Periodendauer in µsec

  Pulsdauer = (Periode * Tastverhaeltnis) / 100; // in µsec
  Pulspause = Periode - Pulsdauer;

  Serial.begin(9600);

  Serial.print("Periode Pulsdauer Pulspause ");
  Serial.print(Periode);
  Serial.print(" ");
  Serial.print(Pulsdauer);
  Serial.print(" ");
  Serial.println(Pulspause);

}

void loop() {

  if (Ton_ein==true) {

    digitalWrite(Ausgang,HIGH);;
    delayMicroseconds(Pulsdauer);

    Ton_ein=false;

  }

  else{

    digitalWrite(Ausgang,LOW);
    delayMicroseconds(Pulspause);

    Ton_ein=true;

  }

}


*/