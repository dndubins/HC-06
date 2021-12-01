/* BC-06_class Example Bluetooth Communications Sketch (change device name, report number)
Author: D. Dubins
Date: 01-Dec-21
Note: Make sure device is not connected to Bluetooth to another device (AT mode)

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
String deviceName="myDevice";  // Enter new device name here

void setup(){
  Serial.begin(9600);   // start Serial Monitor
  SerialBT.begin(9600); // start Serial Bluetooth
  Serial.println("Ready to send AT commands.");
  sendAT("AT",1000); // send "AT", then wait 1 sec
  Serial.println("Changing device name to: "+deviceName);
  sendAT("AT+NAME"+deviceName,1000); // change device name
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
