#include "primary.h"

extern EthernetServer server;

void setup_main() {

  setupCmdArduino(); // Open serial communications and wait for port to open:
  #ifdef SD_CARD_INSERTED
    sd_card_w5100_setup();
  #endif
  //TODO  setupMacAddress();
  serverinit();
}


void loop_main() {
  #ifdef SIMPLE_SERVER
  simplepage();
  #endif
}



void cmdFunctionHelp(int arg_cnt, char **args)
{
    printCurentLanConfig();

    debugSerial<<F("\nUse these commands: 'help' - this text\n"
                          "'mac de:ad:be:ef:fe:00' set and store MAC-address in EEPROM\n"
                          "'ip [ip[,dns[,gw[,subnet]]]]' - set static IP\n"
                          "'save' - save config in NVRAM\n"
                          "'get' [config addr]' - get config from pre-configured URL and store addr\n"
                          "'load' - load config from NVRAM\n"
                          "'pwd' - define MQTT password\n"
                          "'kill' - test watchdog\n"
                          "'clear' - clear EEPROM\n"
                          "'reboot' - reboot controller");
}
void setupCmdArduino() {
  cmdInit(uint32_t(SERIAL_BAUD));
  debugSerial<<(F(">>>"));
  cmdAdd("help", cmdFunctionHelp);
}

void printCurentLanConfig() {
    debugSerial << F("Current LAN config(ip,dns,gw,subnet):");
    printIPAddress(Ethernet.localIP());
//    printIPAddress(Ethernet.dnsServerIP());
    printIPAddress(Ethernet.gatewayIP());
    printIPAddress(Ethernet.subnetMask());
}
