/*
  basicUDP.ino - This is basic UDP example.
  Created by Yasin Kaya (selengalp), August 18, 2018.
*/

#include "Sixfab_CellularIoT.h"

// for Arduino CellularIoT Shield
SixfabCellularIoT node;

// for Arduino CellularIoTApp Shield  
// SixfabCellularIoTApp node; 

char your_ip[] = "xx.xx.xx.xx"; // change with your ip
char your_port[] = "xxxx"; // change with your port

// setup
void setup() {
  
  node.init();

  node.getIMEI();
  node.getFirmwareInfo();
  node.getHardwareInfo();

  node.setIPAddress(your_ip);
  node.setPort(your_port);

  node.setGSMBand(GSM_900);
  //node.setCATM1Band(LTE_B5);
  //node.setNBIoTBand(LTE_B20);
  node.getBandConfiguration();  
  node.setMode(GSM_MODE);
  
  node.connectToOperator();
  node.getSignalQuality();
  node.getQueryNetworkInfo();

  node.deactivateContext();
  node.activateContext();
  node.closeConnection();
  node.startUDPService();
  
  node.sendDataUDP("Hello World!\r\n");
}

// loop
void loop() {

}