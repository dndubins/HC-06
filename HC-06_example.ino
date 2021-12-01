/* HC-06_example.ino Example Bluetooth Communications Sketch
Author: D. Dubins
Date: 29-Nov-21

Connections:
------------
HC-06 Bluetooth Module to Arduino Uno:
EN: NC (not connected)
VCC -- +5V 
GND -- GND
TXD -- Pin 2 (RX)
GND -- 2K -- RXD -- 1K -- Pin 3 (TX)
STATE: NC
(Uno Pin 3 is level shifted to 3.3V)

Uno Connections:
Pin 4 -- led -- 220R -- GND   
*/

#include <SoftwareSerial.h>
SoftwareSerial SerialBT (2,3); //RX, TX
#define LEDPIN 4 // for external LED
#define READPIN A0 // for analog reading

void setup(){
  SerialBT.begin(9600); // start Serial Bluetooth
  pinMode(LEDPIN,OUTPUT);
}
 
void loop(){
  if(SerialBT.available()){
    char choice=SerialBT.read();
    respondTo(choice);  // respond to user input
  }
  delay(1000);   // delay between readings
  int reading=analogRead(READPIN); // take a reading
  SerialBT.println(reading); // report to Bluetooth
}

void respondTo(char c){
  switch(c){
    case '1':   // turn LED on
      digitalWrite(LEDPIN,HIGH);
      SerialBT.println("Turned LED on.");
      break;
    case '2':   // turn LED off
      digitalWrite(LEDPIN,LOW);
      SerialBT.println("Turned LED off.");
      break;
    case 't':   // flash LED
      SerialBT.print("On time: ");
      SerialBT.print(millis()/1000);
      SerialBT.println(" s");
      break;
    default:
      SerialBT.println("ERR");
  } 
  // now print menu:
  SerialBT.println("1: turn on LED");
  SerialBT.println("2: turn off LED");
  SerialBT.println("t: time on (s)");
}
