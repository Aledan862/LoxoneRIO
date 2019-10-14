#pragma once
#include "options.h"

#ifndef ETHERNET_DISABLE
#include "ethernetmodule.h"
#endif
#include <Arduino.h>
#include <SPI.h>
#include "utils.h"
#include <string.h>
#include <Cmd.h>


void setup_main();

void loop_main();

void setupCmdArduino();
void cmdFunctionHelp(int arg_cnt, char **args);
void printCurentLanConfig();
