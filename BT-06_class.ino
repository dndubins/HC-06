/* BT-06_class.ino: Example Bluetooth Communications Sketch 
(report device name, report number)
Author: D. Dubins
Date: 01-Dec-21. Last edited: 07-Apr-25.
Note: Make sure device is not connected to Bluetooth to another device
(AT mode, light flashing)

Connections:
------------
BC-06 Bluetooth Module to Arduino Uno:
EN: NC (not connected)
VCC -- +5V 
GND -- GND
TXD -- Pin 2 (RX)
GND -- 2K -- RXD -- 1K -- Pin 3 (TX)
STATE: NC
(Uno Pin 3 is level shifted to 3.3V)
*/

#include <SoftwareSerial.h>
SoftwareSerial SerialBT (2,3); // RX, TX

void setup(){
  Serial.begin(9600);   // start Serial Monitor
  SerialBT.begin(9600); // start Serial Bluetooth
  Serial.println("Ready to send AT commands.");
  sendAT("AT",1000); // send "AT", then wait 1 sec
  Serial.println("Current device name: ");
  sendAT("AT+NAME",1000); // this will print the current name
}

void loop(){
  // Modify this sketch to output pH or weight to your bluetooth device,
  // instead of the reading on pin A1.
  int reading=analogRead(A1); //take analog reading from pin A1
  Serial.println(reading);  //print reading to serial monitor
  SerialBT.println(reading); //print reading to bluetooth device!
  delay(500); //short delay
}

void sendAT(String command, int msec){
  Serial.println("SENT: "+command);
  //SerialBT.print(command);          // send AT command to HC-06
  SerialBT.print(command+"\r\n"); // send AT command to BT-06
  delay(msec);                      // wait msec
  String rcv="";                    // to hold received string
  while(SerialBT.available()){      // print response
    char c=SerialBT.read();
    if(c>=' '&&c<='~')rcv+=c; // filter for printable characters
  }
  Serial.println("RECEIVED: "+rcv);  // output received string
}
