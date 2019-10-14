#ifndef ethernetmodule_h
#define ethernetmodule_h
#include <Arduino.h>
#include <Ethernet2.h>
#include "utils.h"
#include "options.h"


// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):

void serverinit(); // start the Ethernet connection and the server:

#ifndef SIMPLE_SERVER
#include "server_ajax.h"
#else
void simplepage();
#endif

#endif
