//8-7.ino: Scanning HC-06, BT-06, HC-05 for baud rate, using AT command
//Scans bluetooth device for current baud rate.
//Author: D. Dubins
//Date: 05-Jun-25

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX
int baud[8]={1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
String suffix[4]={"","\n","\r","\r\n"};
String suffixNames[4]={"No Line Ending", "New Line", "Carriage Return", "Both NL & CR" };

void setup(){
  Serial.begin(9600); // start Serial Monitor
  Serial.println(F("Serial monitor ready."));
  for(int i=0;i<8;i++){
    BTSerial.begin(baud[i]);
    delay(100); // small delay
    for(int j=0;j<4;j++){ //iterate through string endings
      BTSerial.print("AT"+suffix[j]);
      delay(3000); // wait for response
      String response = "";
      while (BTSerial.available()) {  // read response from device
        char c = BTSerial.read();
        response += c;
      }
      Serial.print("Baud: "+(String)baud[i]);  // print response
      Serial.print(", Command Ending: "+suffixNames[j]);
      Serial.println(", Response: "+response);
      if(response=="OK"){
        Serial.println("Found baud rate: "+(String)baud[i]+" bps, with "+suffixNames[j]+".");
        return; //leave setup function
      }
    }
  }
  Serial.println(F("Scan complete."));
  Serial.println(F("If no response was found, check wiring, and make sure device is in AT mode."));
}
 
void loop(){
}
