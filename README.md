# HC-06
Bluetooth Communications Made Simple!

•	Connect the BT-06 module to your Uno using the following circuit diagram:
 
•	Download the file  BT-06_class.ino from the course website, http://pb860.pbworks.com.
•	Load the file BT-06_class.ino in the Arduino IDE.
•	At the top of the sketch, change “myDevice” to your own, unique Bluetooth device name (spaces are ok!):
	String deviceName="myDevice";
•	 Modify the sketch to report your pH or weight, instead of the reading on pin A1 in the loop() function:

void loop(){
  // Modify this sketch to output pH or weight to your bluetooth device,
  // instead of the reading on pin A1.
  int reading=analogRead(A1); //take analog reading from pin A1
  Serial.println(reading);  //print reading to serial monitor
  SerialBT.println(reading); //print reading to bluetooth device!
  delay(500); //short delay
}
•	At this point, the BT-06 module should be flashing (AT mode). Upload the sketch to your Uno, and open up the Serial Monitor to see the response codes from the BT-06.

Connecting with your laptop:
•	Connect to the BT-06 using your laptop. If you are connecting with your smartphone, pair with the device first, then open up the Serial Bluetooth Terminal app, click the menu button, then “Devices”, and click on your device.
•	If the device asks for a password, enter “1234”.
•	When successfully connected, the LED on the BT-06 should be solid (Bluetooth connected).
•	Once paired, a new COM port will become available, which is the wireless connection to the BT-06.

Connecting with your Android Phone:

•	Download the “Serial Bluetooth Terminal” app by Kai Morich, from the Google Play Store.
•	In settings, pair with your device first, then open up the Serial Bluetooth Terminal app, click the menu button, then “Devices”, and click on your device.
•	If the device asks for a password, enter “1234”.
•	When successfully connected, the LED on the BT-06 should be solid (Bluetooth connected).
•	Click the “Connect” button on the top of the terminal screen of the App.
•	Observe the numbers being transmitted over Bluetooth. If you can see numbers scrolling, you did it!
