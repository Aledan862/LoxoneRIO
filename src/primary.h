#include <Arduino.h>
#include <SPI.h>
#include "options.h"
#include "utils.h"
#include <string.h>
#include <Cmd.h>
#ifndef ETHERNET_DISABLE
#include "ethernetserver.h"
#endif

void main_setup();

void main_loop();

void setupCmdArduino();
void cmdFunctionHelp(int arg_cnt, char **args);
