
#include <ethernetmodule.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = DEFAULT_FIRMWARE_MAC;
IPAddress ip(DEFAULT_FIRMWARE_IP);

EthernetServer server(80);

void serverinit(){ // start the Ethernet connection and the server:
  Ethernet.w5500_cspin = W5500_CS_PIN;
  Ethernet.begin(mac,ip);
  server.begin();
  debugSerial<<("server is at")<<(Ethernet.localIP());
}

void simplepage(){
// listen for incoming clients
  for (int sock = 0; sock < MAX_SOCK_NUM - FREE_SOCKETS; sock++) {
    EthernetClient client = server.available_(sock);
    // EthernetClient client = server.available();
    if (client) {
      debugSerial<<"new client";
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
            client<<F("HTTP/1.1 200 OK")<<endl;
            client<<F("Content-Type: text/html")<<endl;
            client<<F("Connection: close")<<endl;  // the connection will be closed after completion of the response
            client<<F("Refresh: 5")<<endl;  // refresh the page automatically every 5 sec
            client<<"\n";
            client<<F("<!DOCTYPE HTML>")<<endl;
            client<<F("<html><head><meta charset='utf-8'><title>LOXONE RIO</title>");
            client<<F("<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css\" "); 
			      client<<F("integrity=\"sha384-GJzZqFGwb1QTTN6wy59ffF1BuGJpLSa9DkKMp0DgiMDm4iYMj70gZWKYbI706tWS\" ");
            client<<F("crossorigin=\"anonymous\"/></head>")<<endl;

            client<<F("<div class=\"container\"><div class=\"row\">")<<endl;
            client<<F("<div class=\"col-4\">")<<endl;

            // output the value of each digital input pin
            client<<F("<h2> Цифровые входы </h2>")<<endl;
            for (int digitalChannel = 1; digitalChannel <= MAX_DIGITAL_IN_PORTS; digitalChannel++) {
              bool sensorReading = !digitalRead(DI(digitalChannel));
              client<<F("DI")<<digitalChannel<<"  "<<sensorReading<<("<br />")<<endl;
            }
            client<<F("</div>")<<endl;
            client<<F("<div class=\"col-4\">")<<endl;
            client<<"<h2> Analog inputs </h2>"<<endl;
            for (int digitalChannel = 1; digitalChannel <= MAX_ANALOG_PORTS; digitalChannel++) {
              int sensorReading = analogRead(AI(digitalChannel));
              client<<"MIX"<<digitalChannel<<"  "<<sensorReading<<("<br />")<<endl;
            }
            client<<F("</div>")<<endl;
            client<<F("<div class=\"col-4\">")<<endl;
            client<<"<h2> Digital outputs </h2>"<<endl;
            for (int digitalChannel = 1; digitalChannel <= MAX_DIGITAL_OUT_PORTS; digitalChannel++) {
              bool sensorReading = digitalRead(DO(digitalChannel));
              client<<"DO"<<digitalChannel<<"  "<<sensorReading<<F("<br />")<<endl;
            }            
            client<<F("</div></div></div></html>");
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
      Serial<<("client disconnected");
    }
  }
}