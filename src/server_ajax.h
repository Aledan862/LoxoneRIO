#pragma once
#include "utils.h"
#include "server_maker.h"
// HTTP request
#define REQ_BUF_SIZE 128
#define MAX_LEN_STRING  128
#define MAX_LEN_REQUEST 256 // 512

// webFile
#define MAX_BUFFER_SIZE 256

// Markers
#define MARKER     0x25 // %
#define LINKS      0x26 // &
#define SCRIPTS    0x23 // #
#define HEADER     0x31 // 1
#define DASH       0x32 // 2
#define MENU       0x33 // 3
#define FOOTER     0x34 // 4
#define BANNERS    0x35 // 5
#define ALT_MENU   0x36 // 6
#define ALT_CSS    0x37 // 7
#define PRO        0x38 // 8
#define ADDRESS    0x21 // !
#define FLOTR2     0x3F // ?
#define PROCESSING 0x2B // +
#define THREE      0x40 // @
#define JQUERY     0x3D // =

int checkMarker(int startPos, int endPos);
void sendDelta(int startPos, int endPos, EthernetClient cl);
void markersWorks(int pos, EthernetClient cl);
