/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

int value[4] = {0,0,0,0};
int valueTarget[4] = {0,0,0,0};
// the loop routine runs over and over again forever:
void loop() {
for (int x = 0; x < 4; x++){
if (value[x] == valueTarget[x]){
  valueTarget[x] = random(0,100);
}

if (value[x] < valueTarget[x]) { value[x] = value[x] + 1;}
else {value[x] = value[x] - 1;}
}  

// Serial.write(2);
// for (int x = 0; x < 4; x++){Serial.write(value[x] + 55);}
// Serial.write(4);

Serial.write(1);
Serial.write(value[0] + 55);
Serial.write(4);

delay(10);

// while (true){
//   if (Serial.available() > 0){
//     if (Serial.read() == 6){
//       Serial.flush();
//       break;
//     }
//   }
//}


}
