/* Copyright © 2017-2018 Andrey Klimov. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

Homepage: http://lazyhome.ru
GIT:      https://github.com/anklimov/lighthub
e-mail    anklimov@gmail.com

*/
#pragma once

#ifndef utils_h
#define utils_h

#define Q(x) #x
#define QUOTE(x) Q(x)
#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "="  VALUE(var)

#include <Arduino.h>
#include <IPAddress.h>
//#include "aJSON.h"
#include "options.h"

#include "Streaming.h"

void PrintBytes(uint8_t* addr, uint8_t count, bool newline);
void SetBytes(uint8_t* addr, uint8_t count, char * out);
void SetAddr(char * out,  uint8_t* addr);
uint8_t HEX2DEC(char i);
int getInt(char ** chan);
unsigned long freeRam ();
void parseBytes(const char* str, char separator, byte* bytes, int maxBytes, int base);
int log(const char *str, ...);
void printFloatValueToStr(float value, char *valstr);
void ReadUniqueID( uint32_t * pdwUniqueID );

void printIPAddress(IPAddress ipAddress);

void printUlongValueToStr(char *valstr, unsigned long value);
void scan_i2c_bus();
void softRebootFunc();

void StrClear(char *str, char length);
char StrContains(char *str, char *sfind);
char StrContains(char *str, String strfind);

#endif