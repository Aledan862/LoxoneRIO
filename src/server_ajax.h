#pragma once
#include "utils.h"
#include "iomodule.h"
#include "server_maker.h"
// HTTP request
#define REQ_BUF_SIZE 128
#define MAX_LEN_STRING  128
#define MAX_LEN_REQUEST 256 // 512

// webFile
#define MAX_BUFFER_SIZE 256

int checkMarker(int startPos, int endPos);
void sendDelta(int startPos, int endPos, EthernetClient cl);
void markersWorks(int pos, EthernetClient cl);

// Server works

void serverWorks2(EthernetClient sclient);
void serverWorks();


// Server Answers

String makeAnswer(String content);

void sendHtmlAnswer(EthernetClient cl);
void sendCssAnswer (EthernetClient cl);
void sendJsAnswer  (EthernetClient cl);
void sendGifAnswer (EthernetClient cl);
void sendPngAnswer (EthernetClient cl);
void sendJpgAnswer (EthernetClient cl);
void sendXmlAnswer (EthernetClient cl);
void sendIcoAnswer (EthernetClient cl);

//void sendDownAnswer(EthernetClient cl);
//void sendPdfAnswer (EthernetClient cl);
//void sendZipAnswer (EthernetClient cl);
//void sendGzAnswer  (EthernetClient cl);
//void sendElseAnswer(EthernetClient cl);

void sendErrorAnswer(char mess[], EthernetClient cl);
String tagXmlVersion();
String openInputs();
String closeInputs();

// Tags

String makeTag(String tagBase, String tagCount, String value);

// File

bool openWebFile();
bool openIndexFile(String s);
String partSuffix(byte design);

// Parse Request

void parseRequest(EthernetClient cl);

// For creating Requests

String makeDigitalPorts();
String makeAnalogPorts();
String makeHttpReq();
// Indicators
void respIndicators(EthernetClient cl);
// Generic
void setGeneric();