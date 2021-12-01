# HC-06
Bluetooth Communications Made Simple!

•	Connect the HT-06 module to your Uno using the following circuit diagram:

 ![HC-06 Wiring Diagram](https://github.com/dndubins/HC-06/HC-06.png?raw=true)
 
•	The file BT-06_class.ino is a good place to start for a simple sketch that sends data over Bluetooth to a connected device. The BT-06 device is a lower-cost HC-06 copy.<br>
•	The file <a href=https://github.com/dndubins/HC-06/BT-06_class.ino>BT-06_class.ino</a> is a good place to start for a simple sketch that sends data over Bluetooth to a connected device. You can also use it to change the name of your Bluetooth device. Make sure you run this sketch with your Bluetooth module *disconnected* (in AT mode). Otherwise the module will not accept the AT commands.<br>
•	The file <a href=https://github.com/dndubins/HC-06/HC-06_rename.ino>HC-06_rename.ino</a> can be used to change the name of your Bluetooth device. The module will remember this name, so it only needs to be done once. You can modify this sketch with other AT commands to change the baud rate of the module and other options. Make sure you run this sketch with your Bluetooth module *disconnected* (in AT mode). Otherwise the module will not accept the AT commands.<br>
•	The file <a href=https://github.com/dndubins/HC-06/HC-06_example.ino>HC-06_example.ino</a> is an example sketch for a device with regular reporting of data, but also allows for a Serial menu from your connected device. You can control your project from your computer or smartphone!<p>

##Connecting with your computer:
•	Connect to the BT-06 using your Bluetooth-enabled desktop or laptop.<br>
•	If the device asks for a password, enter “1234”.<br>
•	When successfully connected, the LED on the BT-06 should be solid (Bluetooth connected).<br>
•	Once paired, a new COM port will become available, which is the wireless connection to the BT-06.<br>

##Connecting with your Android Phone:
•	Download the “Serial Bluetooth Terminal” app by Kai Morich, from the Google Play Store.<br>
•	In settings, pair with your device first, then open up the Serial Bluetooth Terminal app, click the menu button, then “Devices”, and click on your device.<br>
•	If the device asks for a password, enter “1234”.<br>
•	When successfully connected, the LED on the BT-06 should be solid (Bluetooth connected).<br>
•	Click the “Connect” button on the top of the terminal screen of the App.<br>
•	Observe the numbers being transmitted over Bluetooth. If you can see numbers scrolling, you did it!<br>
