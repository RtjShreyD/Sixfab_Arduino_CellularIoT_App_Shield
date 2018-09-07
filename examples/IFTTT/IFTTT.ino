/*
  localHost.ino - This is basic local host example.
  Created by Yasin Kaya (selengalp), August 18, 2018.
*/

#include "Sixfab_CellularIoT.h"

SixfabCellularIoT node;

char event_name[] = "sixfabPost"; // change with IFTTT event name
char api_key[] = "beAwFus9EZr0RoS_vR8HnQ"; // change with x-api-key

char dataTemplate[] ="{\"value\":\"%d\"}";

char dataJSON[100];

// setup
void setup() {
  
  node.init();

  node.getIMEI();
  node.getFirmwareInfo();
  node.getHardwareInfo();

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
  //node.closeConnection();
  //node.connectToServerTCP();


  sprintf(dataJSON, dataTemplate, 20);
  node.sendDataIFTTT(event_name, api_key, dataJSON );
  
}

// loop
void loop() {

}