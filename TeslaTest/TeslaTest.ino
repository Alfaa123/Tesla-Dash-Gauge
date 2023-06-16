#include <due_can.h>



void setup() {
  while(!SerialUSB){};
  SerialUSB.begin(115200);
  Can1.init(CAN_BPS_500K);
  Can1.setRXFilter(0, 0x132, 0xFFF, false);
  Can1.setCallback(0, callbackFunction);
  Can1.setGeneralCallback(callbackFunction);
  SerialUSB.println("test");
}

void loop() {

}

void callbackFunction(CAN_FRAME *frame){
uint16_t batVoltage = frame->data.byte[1];
batVoltage = batVoltage << 8;
batVoltage = batVoltage + frame->data.byte[0];

SerialUSB.print("Battery_Voltage:");
SerialUSB.print(batVoltage * 0.01);
SerialUSB.print(",");

int16_t batCurrent = frame->data.byte[3];
batCurrent = batCurrent << 8;
batCurrent = batCurrent + frame->data.byte[2];

SerialUSB.print("Battery_Current:");
SerialUSB.print(batCurrent * 0.01);
SerialUSB.print(",");

uint16_t timeLeft = frame->data.byte[7];
timeLeft = timeLeft << 8;
timeLeft = timeLeft + frame->data.byte[6];
SerialUSB.print("Charge_time_left:");
SerialUSB.println(timeLeft);
//SerialUSB.println(" Min");
}
