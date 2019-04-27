#include <EEPROM.h>


int valueArray[] = {2, 56, 21, 67, 205, 199, 168, 43};
int arrayLength = 7;

void setup() {

  for (int i = 0; i <= arrayLength; i++) {
    if (EEPROM.read(i) != valueArray[i]){
    EEPROM.write(i, valueArray[i]);
    Serial.print("Written data/n");
    }
  }

  Serial.begin(9600);
  while (!Serial){
    ;
  }
  
}

void loop() {

  String readData = "";

  for (int i = 0; i <= arrayLength; i++) {
    readData += String(EEPROM.read(i));
  }

  Serial.print(readData + "\n");

  delay(100);
  
}
