// Basic Bluetooth test sketch 5a for the Arduino Mega. 
// AT mode using button switch
// HC-05 with EN pin and button switch
//
// Uses serial with the host computer and serial1 for communication with the Bluetooth module
//
//  Pins
//  BT VCC to Arduino 5V out. Disconnect before running the sketch
//  BT GND to Arduino GND
//  BT RX (through a voltage divider) to Arduino TX1 (pin 10)
//  BT TX  to Arduino RX1 (no need voltage divider)   (pin 11)
//
// When a command is entered in to the serial monitor on the computer 
// the Arduino will relay it to the Bluetooth module and display the result.
//

/*-----( Import needed libraries )-----*/
#include <SoftwareSerial.h>  

char serialByte = '0';

#define HC_05_RXD_ARDUINO_TXD 10
#define HC_05_TXD_ARDUINO_RXD 11

SoftwareSerial BTSerial(HC_05_TXD_ARDUINO_RXD, HC_05_RXD_ARDUINO_TXD); // RX | TX
 
void setup() 
{ 
    // communication with the host computer
    Serial.begin(9600);  
 
    Serial.println("Do not power the BT module");
    Serial.println(" ");
    Serial.println("On the BT module, press the button switch (keep pressed, and at the same time power the BT module");
    Serial.println("The LED on the BT module should now flash on/off every 2 seconds");
    Serial.println("Can now release the button switch on the BT module");
    Serial.println(" ");
    Serial.println("After entering AT mode, type 1 and hit send");
    Serial.println(" ");
 
    // communication with the BT module on serial1
    BTSerial.begin(38400);
 
    Serial.println(" ");
    Serial.println("AT mode.");
    Serial.println("Remember to to set Both NL & CR in the serial monitor.");
    Serial.println("The HC-05 accepts commands in both upper case and lower case");
    Serial.println(" "); 
}
 
 
void loop() 
{
    // listen for communication from the BT module and then write it to the serial monitor
    if ( BTSerial.available() )   {  Serial.write( BTSerial.read() );  }
 
    // listen for user input and send it to the HC-05
   if ( Serial.available() )   {  BTSerial.write( Serial.read() );  }
}

