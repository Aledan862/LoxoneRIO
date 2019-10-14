// Configuration of drivers enabled

#ifndef AVR_DMXOUT_PIN
#define AVR_DMXOUT_PIN 3
#endif

#ifndef INTERVAL_CHECK_INPUT
#define INTERVAL_CHECK_INPUT  50
#endif

#ifndef OW_UPDATE_INTERVAL
#define OW_UPDATE_INTERVAL 5000
#endif

#ifndef SERIAL_BAUD
#define SERIAL_BAUD 115200
#endif

#ifndef CUSTOM_FIRMWARE_MAC
#define DEFAULT_FIRMWARE_MAC {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xFF}
#endif

#ifndef CUSTOM_FIRMWARE_IP
#define DEFAULT_FIRMWARE_IP {192, 168,  0, 122}
// DNS[]    = {   ,    ,   ,   }
// GATEWAY[]  = {192, 168,  1,  1}
#endif

#ifndef LAN_INIT_DELAY
#define LAN_INIT_DELAY 500
#endif

#define DHT_POLL_DELAY_DEFAULT 15000
#define UPTIME_POLL_DELAY_DEFAULT 30000

#ifndef debugSerial
#define debugSerial Serial
#endif

#define W5500_ETHERNET_SHIELD
#define W5500_CS_PIN 53

// Sockets
#define FREE_SOCKETS 1


//Analog ports

#define MAX_ANALOG_PORTS 8

//Digital inputs ports

#define MAX_DIGITAL_IN_PORTS 16

//Digital outputs ports

#define MAX_DIGITAL_OUT_PORTS 24