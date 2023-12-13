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

    10 Weihnachtsbäckerei
    11 Morgen kommt der Weihnachtsmann

    12 Advent, Advent
    13 Leise rieselt der Schnee
    14 Lasst uns froh und munter sein
    15 Schneeflöckchen Weißröckchen
    16 Am Weihnachtsbaum die Lichter brennen
    17 O Tannenbaum
    18 Morgen Kinder wirds was geben
    19 O du fröhliche

*/

#include "Noten_min.h"      // nur 3 Oktaven

#define PAUSE             0 // Pausenzeichen

#define Analog0           0 // Analog Eingang für Rauschen Zufallszahl


#define Selbstabschaltung 2 // PD2 für Transistor Abschaltung
#define Buzzer            3 // PD3 als Ansteuerung für passiven Buzzer
#define Soundmodul        4 // PD4 externes Soundmodul ISD1820

#define LED_onboard       13 // LED

#define Lied0                                 0    // Sound Modul
#define MARY_HAD_A_LITTLE_LAMB                1    // Lied
#define ABC_DIE_KATZE_LIEF                    2    // Lied
#define ALLE_MEINE_ENTCHEN                    3    // Lied
#define KUCKUCK_KUCKUCK                       4    // Lied
#define HEIDI                                 5    // Lied
#define KUCKUCK_UND_ESEL                      6    // Lied
#define ALLE_JAHRE_WIEDER                     7    // Lied
#define IHR_KINDERLEIN_KOMMET                 8    // Lied
#define KLING_GLOECKCHEN                      9    // Lied
#define WEIHNACHTSBAECKEREI                   10    // Lied
#define MORGEN_KOMMT_DER_WEIHNACHTSMANN       11    // Lied
#define ADVENT_ADVENT                         12    // Lied
#define LEISE_RIESELT_DER_SCHNEE              13    // Lied
#define LASST_UNS_FROH_UND_MUNTER_SEIN        14    // Lied
#define SCHNEEFLOECKCHEN_WEISSROECKCHEN       15    // Lied
#define AM_WEIHNACHTSBAUM_DIE_LICHTER_BRENNEN 16    // Lied
#define O_TANNENBAUM                          17    // Lied
#define MORGEN_KINDER_WIRDS_WAS_GEBEN         18    // Lied
#define O_DU_FROELICHE                        19    // Lied

#define ANZAHL_LIEDER                         19  // Anzahl für Auswahl über Zufallszahl Generator

int Zufallszahl;

int Blinken;    // LED onboard blinken

#define MAXTOENE 60   // Begrenzung für array

int melody[MAXTOENE];
int noteDurations[MAXTOENE];
//int noteAbstand[MAXTOENE];

int Anzahl_Bytes;   // Array Länge in Bytes
int Anzahl_Noten;   // Array Läneg in Variabeln

int Lied;         // ausgewähltes Lied

// **********  Mary has a little lamb ************

  const int Noten_1[] PROGMEM = {E5, D5, C5, D5, E5, E5, E5, D5, D5, D5, E5, G5, G5, E5, D5, C5, D5, E5, E5, E5, E5, D5, D5, E5, D5, C5};
  const int Dauer_1[] PROGMEM = {4,  4,  4,  4,  4,  4,  2,  4,  4,  2,  4,  4,  2,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  1};


// ************* ABC die Katze lief im Schnee (Seite 263) ************ https://www.lieder-archiv.de/a_b_c_die_katze_lief_im_schnee-notenblatt_100054.html
  const PROGMEM uint16_t Noten_2[] = {F5, A5, C6, PAUSE, BM5, A5, A5, A5, G5, G5, F5, PAUSE, C6, BM5, A5, G5, F5, E5, F5, G5, C6, BM5, A5, G5, F5, E5, F5, G5, C5, F5, A5, C6, PAUSE, BM5, A5, A5, A5, G5, G5, F5};
  const PROGMEM uint16_t Dauer_2[] = { 2,  2,  2,     4,   4,  4,  8,  8,  4,  4,  2,     4,  4,   4,  4,  4,  4,  4,  4,  4,  4,   4,  4,  4,  4,  4,  4,  4,  4,  2,  2,  2,     4,   4,  4,  8,  8,  4,  4,  2};


// *** Alle meine Entchen *** https://www.kleinemusiker.de/alle-meine-entchen/

  const PROGMEM uint16_t Noten_3[] = {C5, D5, E5, F5, G5, G5, A5, A5, A5, A5, G5, A5, A5, A5, A5, G5, F5, F5, F5, F5, E5, E5, G5, G5, G5, G5, C5};
  const PROGMEM uint16_t Dauer_3[] = { 4,  4,  4,  4,  2,  2,  4,  4,  4,  4,  1,  4,  4,  4,  4,  1,  4,  4,  4,  4,  2,  2,  4,  4,  4,  4,  1};


// *** Nr. 4 Kuckuck, Kuckuck, ruft's aus dem Wald   *** https://www.franzdorfer.com/kuckuck-rufts-aus-dem-wald

  const PROGMEM uint16_t Noten_4[] = {C6, A5, PAUSE, C6, A5, PAUSE, G5, F5, G5, F5, PAUSE, G5, G5, A5, BM5, G5, A5, A5, BM5, C6, A5, C6, A5, C6, A5, G5, F5, G5, F5, F5};
  const PROGMEM uint16_t Dauer_4[] = { 4,  4,     4,  4,  4,     4,  4,  4,  4,  2,     4,  4,  4,  4,   2,  4,  4,  4,   4,  2,  4,  2,  4,  2,  4,  4,  4,  4,  2,  4};


// ******* Nr. 5 Heidi **************

  const PROGMEM uint16_t Noten_5[] = {G5, E5, E6, C6, G5, G5, A5, G5, E5, F5, E5, D5, D5, PAUSE, F5, D5, D6, B5, B5, B5, B5, A5,G5, A5, G5,E5, E5};
  const PROGMEM uint16_t Dauer_5[] = { 2,  2,  2,  2,  4,  8,  4,  4,  8,  4,  8,  8,  4,     4,  2,  2,  2,  2,  4,  8,  4,  8, 4,  4,  8, 8,  4};


// ******* Nr. 6 Der Kuckuck und der Esel ************** https://www.heilpaedagogik-info.de/tierlieder/1774-der-kuckuck-und-der-esel.html

  const PROGMEM uint16_t Noten_6[] = {C6, A5, C6, A5, C6, BM5, BM5, PAUSE, BM5, G5, BM5, G5, BM5, A5, PAUSE, C6, BM5, A5, A5, A5, A5, BM5, BM5, PAUSE, BM5, A5, G5, G5, G5, G5, A5, A5, PAUSE, F5, F5, G5, A5, BM5, C6, C6, D6, C6, BM5, A5, A5, G5, G5, F5};
  const PROGMEM uint16_t Dauer_6[] = { 4,  4,  4,  4,  4,   4,   4,     4,   4,  4,   4,  4,   4,  2,     4,  8,   8,  4,  4,  4,  4,   4,   4,     4,   8,  8,  4,  4,  4,  4,  4,  4,     4,  4,  4,  4,  4,   4,  4,  8,  8,  4,   4,  4,  4,  4,  4,  2};


// ******* Nr. 7 Alle Jahre wieder **************

  const PROGMEM uint16_t Noten_7[] = {A5,B5,A5,G5,F5,E5,D5,E5,F5,G5,F5,E5,F5,A5,AS5,A5,D6,C6,AS5,A5,G5,F5,G5,A5,G5};
  const PROGMEM uint16_t Dauer_7[] = { 3, 6, 4, 4, 2, 2, 4, 8, 8, 4, 4, 1, 4, 4,  4, 4, 2, 4,  4, 4, 8, 8, 4, 4, 1};


// ******* Nr. 8 Ihr Kinderlein kommet ************** en.wikipedia.org/wiki/ihr_kinderlein,_kommet

  const PROGMEM uint16_t Noten_8[] = {A5,A5,FS5,A5,A5,FS5,A5,G5,E5,G5,FS5,PAUSE,A5,A5,FS5,A5,A5,FS5,A5,G5,E5,G5,FS5,PAUSE,FS5,E5,E5,E5,G5,G5,G5,FS5,FS5,FS5,B5,PAUSE,B5,A5,A5,A5,D6,A5,FS5,G5,E5,CS5,D5};
  const PROGMEM uint16_t Dauer_8[] = { 4, 2,  4, 4, 2,  4, 4, 2, 4, 4,  2,    4, 4, 2,  4, 4, 2,  4, 4, 2, 4, 4,  2,    4,  4, 2, 4, 4, 2, 4, 4,  2,  4,  4, 2,    4, 4, 2, 4, 4, 2, 4,  4, 2, 4,  4, 2};

// ******* Nr. 9 Kling Glöckchen **************

  const PROGMEM uint16_t Noten_9[] = {C6,A5,B5,C6,D6,C6,D6,C6,PAUSE,B5,G5,C6,A5,PAUSE,G5,G5,A5,F5,A5,G5,PAUSE,B5,B5,C6,G5,B5,A5,PAUSE,G5,G5,A5,AS5,C6,G5,PAUSE,A5,D6,C6,AS5,D6,C6}; //,PAUSE,A5,B5,C6,D6,C6,D6,C6,PAUSE,B5,G5,C6,A5};
  const PROGMEM uint16_t Dauer_9[] = {2,  4, 4, 6, 6, 6, 6, 2,    8, 2, 4, 4, 2,    8, 2, 4, 4, 4, 2, 2,    8, 2, 4, 4, 4, 2, 2,    8, 2, 4, 4,  4, 2, 4,    8, 2, 4, 4,  4, 2, 4}; //,     4,4, 4, 6, 6, 6, 6, 2,     4,2, 4, 4, 2};

// ******* Nr. 10 Weinachtsbäckerei **************

  const PROGMEM uint16_t Noten_10[] = {G4,F5,E5,E5,D5,D5,C5,PAUSE,D5,E5,F5,F5,E5,E5,D5,PAUSE,D5,E5,F5,F5,G5,PAUSE,D5,E5,F5,F5,G5,PAUSE,G5,F5,E5,E5,G5,G5,D5,D5,G5,PAUSE,G5,F5,E5,E5,D5,D5,C5};
  const PROGMEM uint16_t Dauer_10[] = {3, 6, 4, 4, 4, 4, 2,     8,3, 6, 4, 4, 4, 4, 2,     8,3, 6, 4, 4, 4,     8,3, 6, 4, 4, 4,     8,3, 6, 4, 4, 4, 4, 4, 4, 4,     8,3, 6, 4, 4, 4, 4, 2};

// ******* Nr. 11 Morgen kommt der Weinachtsmann **************

  const PROGMEM uint16_t Noten_11[] = {G5,G5,D6,D6,E6,E6,D6,C6,C6,B5,B5,A5,G5,PAUSE,D6,D6,C6,C6,B5,B5,A5,D6,D6,C6,C6,B5,B5,A5,G5,G5,D6,D6,E6,E6,D6,C6,C6,B5,B5,A5,G5};
  const PROGMEM uint16_t Dauer_11[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 4,     6,4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 2};

// ******* Nr. 12 Advent, Advent **************

  const PROGMEM uint16_t Noten_12[] = {G5,D5,E5,D5,PAUSE,G5,D5,E5,D5,PAUSE,E5,F5,G5,A5,D5,G5,A5,AS5,PAUSE,AS5,C6,AS5,A5,G5,E5,A5,F5,G5};
  const PROGMEM uint16_t Dauer_12[] = {6, 3, 6, 3,     8,6, 3, 6, 3,     8,6, 3, 6, 3, 6, 3, 6, 3,      8,6,  3, 6,  3, 6, 6, 6, 4, 2};

// ******* Nr. 13 Leise rieselt der Schnee **************

  const PROGMEM uint16_t Noten_13[] = {B5,B5,A5,B5,A5,G5,PAUSE,G5,E5,G5,F5,E5,D5,PAUSE,A5,GS5,A5,C6,B5,A5,G5,PAUSE,A5,E5,E5,F5,E5,F5,G5};
  const PROGMEM uint16_t Dauer_13[] = { 2, 4, 4, 4, 4, 2,   10, 2, 4, 4, 4, 4, 2,   10, 4,  4, 4, 4, 4, 4, 2,   10, 3, 6, 4, 4, 4, 4, 2};

// ******* Nr. 14 Lasst uns froh und munter sein **************

  const PROGMEM uint16_t Noten_14[] = {A5,A5,A5,B5,A5,G5,F5,F5,F5,PAUSE,G5,G5,G5,A5,G5,F5,E5,E5,E5,PAUSE,D5,E5,F5,G5,A5,B5,A5,B5,A5,PAUSE,D6,A5,A5,B5,A5,G5,F5,E5,A5,PAUSE,D6,A5,A5,B5,A5,G5,F5,E5,D5};
  const PROGMEM uint16_t Dauer_14[] = { 4, 4, 6, 6, 6, 6, 4, 4, 3,   10, 4, 4, 6, 6, 6, 6, 4, 4, 3,   10, 4, 4, 4, 4, 6, 8, 6, 6, 2,   10, 4, 4, 6, 6, 6, 6, 4, 4, 2,   10, 4, 4, 6, 6, 6, 6, 4, 4, 2};

// ******* Nr. 15 Schneeflöckchen Weißröckchen **************

  const PROGMEM uint16_t Noten_15[] = {E5,F5,G5,G5,A5,D5,D5,D5,E5,F5,F5,G5,E5,PAUSE,E5,F5,G5,G5,C6,B5,A5,G5,F5,E5,F5,D5,C5};
  const PROGMEM uint16_t Dauer_15[] = { 6, 6, 4, 4, 4, 4, 4, 6, 6, 4, 4, 4, 2,   10, 6, 6, 4, 4, 4, 4, 4, 6, 6, 4, 4, 4, 2};

// ******* Nr. 16 Am Weihnachtsbaum die Lichter brennen **************

  const PROGMEM uint16_t Noten_16[] = {C5,C5,E5,G5,E5,G5,C6,A5,G5,E5,PAUSE,G5,A5,G5,F5,D5,G5,G5,D5,PAUSE,E5,E5,G5,F5,D5,F5,F5,A5,G5,E5,E5,E5,G5,F5,D5,G5,G5,E5};
  const PROGMEM uint16_t Dauer_16[] = { 6, 6, 6, 4, 6, 6, 6, 6, 4, 6,   10, 6, 6, 6, 4, 4, 6, 6, 4,   10, 6, 6, 6, 4, 6, 6, 6, 6, 4, 6, 6, 6, 6, 4, 4, 6, 6, 3};

// ******* Nr. 17 O Tannenbaum **************

  const PROGMEM uint16_t Noten_17[] = {C5,F5,F5,F5,G5,A5,A5,A5,G5,A5,B5,E5,G5,F5,PAUSE,C6,C6,A5,D6,C6,C6,B5,B5,B5,B5,G5,C6,B5,B5,A5,A5,PAUSE,C5,F5,F5,F5,G5,A5,A5,A5,A5,G5,A5,B5,E5,G5,F5};
  const PROGMEM uint16_t Dauer_17[] = { 6, 3, 8, 3, 6, 3, 8, 3, 6, 6, 4, 4, 4, 4,   10, 6, 6, 6, 3, 6, 6, 6, 3, 6, 6, 6, 3, 6, 6, 6, 4,   10, 6, 3, 8, 3, 6, 3, 8, 3, 6, 6, 6, 4, 4, 4, 2};

// ******* Nr. 18 Morgen Kinder wirds was geben **************

  const PROGMEM uint16_t Noten_18[] = {F5,C5,D5,C5,D5,F5,E5,G5,F5,C5,PAUSE,A5,A5,B5,C6,A5,B5,A5,G5,PAUSE,F5,C5,D5,C5,D5,F5,E5,G5,F5,C5,A5,A5,B5,C6,A5,B5,A5,G5,PAUSE,B5,B5,D6,D6,G5,G5,C6,PAUSE,F5,F5,B5,B5,A5,G5,F5,E5,F5};
  const PROGMEM uint16_t Dauer_18[] = { 4, 4, 4, 4, 6, 6, 6, 6, 4, 4,   10, 4, 6, 6, 4, 4, 4, 4, 2,    8, 4, 4, 4, 4, 6, 6, 6, 6, 4, 4, 4, 6, 6, 4, 4, 4, 4, 2,    8, 4, 4, 4, 4, 4, 4, 3,    8, 4, 4, 4, 4, 6, 6, 6, 6, 2};

// ******* Nr. 19 O du fröhliche **************

  const PROGMEM uint16_t Noten_19[] = {G5,A5,G5,F5,E5,F5,PAUSE,G5,A5,G5,F5,E5,F5,PAUSE,G5,G5,A5,B5,C6,B5,A5,G5,PAUSE,D5,E5,D5,E5,F5,G5,F5,PAUSE,E5,F5,E5,F5,G5,A5,G5,PAUSE,C6,B5,A5,G5,C6,A5,G5,F5,E5,D5,C5};
  const PROGMEM uint16_t Dauer_19[] = { 2, 2, 3, 6, 4, 4,   12, 2, 2, 3, 6, 4, 4,   12, 2, 2, 2, 4, 4, 2, 2, 1,   10, 3, 6, 4, 4, 3, 6, 2,   10, 3, 6, 4, 4, 3, 6, 2,   10, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 1};


void setup() {
  // iterate over the notes of the melody:

  pinMode(Selbstabschaltung,OUTPUT);
  digitalWrite(Selbstabschaltung, HIGH);    // Batterie Spannung halten (Transistor sofort ein)

  pinMode(Buzzer,OUTPUT);
  digitalWrite(Buzzer, LOW);              // Buzzer Ansteuerung AUS

  pinMode(Soundmodul,OUTPUT);
  digitalWrite(Soundmodul, LOW);          // Soundmodul AUS


  randomSeed(analogRead(A0));     // Zufall abhängig von Rauschen auf Analog Eingang
  Zufallszahl= random(ANZAHL_LIEDER);   // 0.. Anzahl Lieder -1; random nimmt als Parameter die `Obergrenze des Zufallswerts, exklusiv` (s. https://www.arduino.cc/reference/de/language/functions/random-numbers/random/ )
  Lied  = Zufallszahl+1;                  // 0= Sound Modul aktivieren  vorläufig unterdrücken::  1... Anzahl Lieder

  // für debug Lied fix auswählen
  //Lied=6;

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

    case MARY_HAD_A_LITTLE_LAMB:
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

    case ABC_DIE_KATZE_LIEF:
      Anzahl_Bytes=sizeof(Noten_2);
      memcpy_P(melody, Noten_2, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_2,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_2,Anzahl_Bytes);
      break;

    case ALLE_MEINE_ENTCHEN:
      Anzahl_Bytes=sizeof(Noten_3);    // Achtung sizeof = ANzahl Bytes nicht Anzahl Variabeln
      memcpy_P(melody, Noten_3, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_3,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case KUCKUCK_KUCKUCK:
      Anzahl_Bytes=sizeof(Noten_4);
      memcpy_P(melody, Noten_4, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_4,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_4,Anzahl_Bytes);
    break;

    case HEIDI:
      Anzahl_Bytes=sizeof(Noten_5);
      memcpy_P(melody, Noten_5, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_5,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_5,Anzahl_Bytes);
    break;

    case KUCKUCK_UND_ESEL:
      Anzahl_Bytes=sizeof(Noten_6);
      memcpy_P(melody, Noten_6, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_6,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_6,Anzahl_Bytes);
    break;

    case ALLE_JAHRE_WIEDER:
      Anzahl_Bytes=sizeof(Noten_7);
      memcpy_P(melody, Noten_7, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_7,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case IHR_KINDERLEIN_KOMMET:
      Anzahl_Bytes=sizeof(Noten_8);
      memcpy_P(melody, Noten_8, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_8,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case KLING_GLOECKCHEN:
      Anzahl_Bytes=sizeof(Noten_9);
      memcpy_P(melody, Noten_9, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_9,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case WEIHNACHTSBAECKEREI:
      Anzahl_Bytes=sizeof(Noten_10);
      memcpy_P(melody, Noten_10, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_10,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case MORGEN_KOMMT_DER_WEIHNACHTSMANN:
      Anzahl_Bytes=sizeof(Noten_11);
      memcpy_P(melody, Noten_11, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_11,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case ADVENT_ADVENT:
      Anzahl_Bytes=sizeof(Noten_12);
      memcpy_P(melody, Noten_12, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_12,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case LEISE_RIESELT_DER_SCHNEE:
      Anzahl_Bytes=sizeof(Noten_13);
      memcpy_P(melody, Noten_13, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_13,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case LASST_UNS_FROH_UND_MUNTER_SEIN:
      Anzahl_Bytes=sizeof(Noten_14);
      memcpy_P(melody, Noten_14, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_14,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case SCHNEEFLOECKCHEN_WEISSROECKCHEN:
      Anzahl_Bytes=sizeof(Noten_15);
      memcpy_P(melody, Noten_15, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_15,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case AM_WEIHNACHTSBAUM_DIE_LICHTER_BRENNEN:
      Anzahl_Bytes=sizeof(Noten_16);
      memcpy_P(melody, Noten_16, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_16,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case O_TANNENBAUM:
      Anzahl_Bytes=sizeof(Noten_17);
      memcpy_P(melody, Noten_17, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_17,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case MORGEN_KINDER_WIRDS_WAS_GEBEN:
      Anzahl_Bytes=sizeof(Noten_18);
      memcpy_P(melody, Noten_18, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_18,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

    case O_DU_FROELICHE:
      Anzahl_Bytes=sizeof(Noten_19);
      memcpy_P(melody, Noten_19, Anzahl_Bytes);
      memcpy_P(noteDurations, Dauer_19,Anzahl_Bytes);
      //memcpy(noteAbstand, Abstand_3,Anzahl_Bytes);
    break;

  }

Anzahl_Noten= Anzahl_Bytes/sizeof(uint16_t);    // Achtung sizeof = Anzahl Bytes nicht Anzahl Variabeln

Serial.print("Anzahl Noten= ");
Serial.print(Anzahl_Noten);
Serial.print(" ");
Serial.print("Bytes=");
Serial.println(Anzahl_Bytes);


  if (Lied != Lied0) {
    for (int thisNote = 0; thisNote < Anzahl_Noten; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;

      if (melody[thisNote] != PAUSE) {     // Note spielen
        tone(Buzzer, melody[thisNote], noteDuration);
      }
      // der `pauseBetweenNotes` wird bereits fuer eine Pause sorgen, also waere dieses zu viel
      //else {      // Pause statt Note
      //  delay(noteDuration);
      //}
          Serial.print(thisNote);
          Serial.print("/");
          Serial.print(pauseBetweenNotes);
          Serial.print(" ");

      if (pauseBetweenNotes < 0) {
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
  for (int blinken=0; blinken > 6; blinken++) {
      pinMode(LED_onboard, OUTPUT);
      digitalWrite(LED_onboard, LOW);
      delay(500);
      digitalWrite(LED_onboard, HIGH);
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
