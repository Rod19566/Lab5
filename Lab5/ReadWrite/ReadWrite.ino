/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;
void printimage();
int imagen;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  SPI.setModule(0);

  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(PA_3, OUTPUT);

  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  Serial.println();
  Serial.println("Eliga una imagen con 1, 2 o 3: "); 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

  // re-open the file for reading:

  
 
}

void printimage(){
  //
  switch (imagen){
    case 1: 
    myFile = SD.open("froggo.txt");
    if (myFile) {
      Serial.println("froggo.txt: ");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
    } else {
    // if the file didn't open, print an error:
    Serial.println("error opening .txt");
    }
    break;
    case 2: 
    myFile = SD.open("llama.txt");
    if (myFile) {
      Serial.println("llama.txt: ");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
    } else {
    // if the file didn't open, print an error:
    Serial.println("error opening .txt");
    }
    break;
    case 3: 
    myFile = SD.open("jake.txt");
    if (myFile) {
      Serial.println("jake.txt: ");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
    } else {
    // if the file didn't open, print an error:
    Serial.println("error opening .txt");
    }
    break;
    default: 
     Serial.println("No existe");
     break;
  }
  
  Serial.println();
  Serial.println();
}

void loop()
{
  if(Serial.available()) // Check for availablity of data at Serial Port
  {
    imagen = Serial.read(); // Reading Serial Data and saving in data variable
    void printimage();
    Serial.println("Eliga una imagen con 1, 2 o 3: "); 
  }

  
}
