#include "primary.h"
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = DEFAULT_FIRMWARE_MAC;
IPAddress ip(192, 168, 0, 122);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

void main_setup() {
  
  setupCmdArduino(); // Open serial communications and wait for port to open:
  #ifdef SD_CARD_INSERTED
    sd_card_w5100_setup();
  #endif
  //TODO  setupMacAddress();

  // start the Ethernet connection and the server:
  Ethernet.begin(mac,ip);
  server.begin();
  debugSerial<<("server is at")<<(Ethernet.localIP());
}


void main_loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each digital input pin
          for (int digitalChannel = 0; digitalChannel < 6; digitalChannel++) {
            int sensorReading = digitalRead(digitalChannel);
            client.print("digital input ");
            client.print(digitalChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}


void setupCmdArduino() {
    cmdInit(uint32_t(SERIAL_BAUD));
    debugSerial<<(F(">>>"));
    cmdAdd("help", cmdFunctionHelp);
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

void printCurentLanConfig() {
    debugSerial << F("Current LAN config(ip,dns,gw,subnet):");
    printIPAddress(Ethernet.localIP());
//    printIPAddress(Ethernet.dnsServerIP());
    printIPAddress(Ethernet.gatewayIP());
    printIPAddress(Ethernet.subnetMask());
}