//This is a mini- piano with 17 buttons each ith varying pitches.
//Once you have stated simulation, click on any part of the interface,then can use keyboard pins 1- to 9 for buttons 1 to 9 respectively,then use  0, p, o,i,u,y,t and r respectively to represent the remaining buttons.
//Enjoy Your Simulation.



#include "pitches.h"

#define Buzzer 8
const unsigned int buttonPins[]={A5,A4,A3,A2,A1
,A0,2,3,4,5,6,7,9,10,11,12,13};

const int buttonTones[] = {
  NOTE_C4,
  NOTE_CS4,
  NOTE_D4,
  NOTE_DS4,
  NOTE_E4,
  NOTE_F4,
  NOTE_FS4,
  NOTE_G4,
  NOTE_GS4,
  NOTE_A4,
  NOTE_AS4,
  NOTE_B4,
  NOTE_C5,
  NOTE_CS5,
  NOTE_D5,
  NOTE_DS5,
  NOTE_E5
};

const int numTonnes=sizeof(buttonPins)/sizeof(buttonPins[0]);

void setup(){
  for(unsigned int i=0;i<numTonnes; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(Buzzer, OUTPUT);
  }
}
  void loop()
  {
    int pitch =0;
    for(unsigned int i = 0; i<numTonnes; i++){
      if (digitalRead(buttonPins[i])==LOW)

     pitch=buttonTones[i];
    }
    if (pitch){
      tone(Buzzer,pitch);
    }
    else {
      noTone(Buzzer);
    }
  }
