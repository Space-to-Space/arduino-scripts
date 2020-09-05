#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;
MCP2515 mcp2515(10);

void setup() {
  canMsg1.can_id  = 0x002; //Set id 
  /*
  Biegemessstreifen - 0x001
  Acc x - 0x002
  Acc y - 0x003
  Acc z - 0x004
  */
  canMsg1.can_dlc = 4;
  canMsg1.data[0] = 0xFF; //data contains the sensor value MAPPED
  canMsg1.data[1] = 0xAF;
  canMsg1.data[2] = 0xAF;
  canMsg1.data[3] = 0xAF;
  
  while (!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
}

void loop() {
  //canMsg1.data[0] = counter; --Set the sensor data here
  
  mcp2515.sendMessage(&canMsg1); //Send message

  delay(100);
}
