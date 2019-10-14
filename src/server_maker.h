/*
  Module Pages Maker
  part of Arduino Mega Server project
*/
#include "utils.h"
#include <SD.h>
#include <Ethernet2.h>


#define NORMAL        0
#define ALL_SCRIPTS   1
#define ALT_CSS_STYLE 2
#define PRO_CARDS     3

#define OPEN_BLOCK_STYLE  "\n<style>\n"
#define CLOSE_BLOCK_STYLE "</style>\n"
#define CLOSE_STYLE       "  }\n"

//File
#define MAX_BUFFER_INSERT 256

String ipString(byte ip[]);
String openStyle(String style);
String backgroundIpAttr(String fileName);

// Design
#define DESIGN_DEFAULT 0
#define DESIGN_HOME    1
#define DESIGN_MODERN  2
#define DESIGN_HACKER  3
#define DESIGN_PART1   4
#define DESIGN_PART2   5
#define DESIGN_PART3   6
#define DESIGN_PART4   7
byte currentDesign = DESIGN_DEFAULT;
void addBackgroundStyle(String style, String file, EthernetClient cl);
String themeSuffix(byte design);

void generateProArray();



// Pages
#define UNKNOWN_PAGE   0
#define THEMES_PAGE    4
#define SETTINGS_PAGE  5
#define PORTS_PAGE     6
#define SUPPLY_PAGE    7
#define ELECTRO_PAGE   8
byte currentPage = UNKNOWN_PAGE;

#define GET           "GET /"
#define INDEX_STR     "index"
#define HTM_EXT       ".htm"

#define BASE_PIR      "pir"
#define BASE_CONTACT  "cont"
#define BASE_LITE     "lite"
#define BASE_MAC      "mac"
#define BASE_IP       "ip"
#define CHECKED_STR   "checked"
#define UNCHECKED_STR "unchecked"

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


void addBackgroundStyle(String style, String file, EthernetClient cl);

void insert(File file, EthernetClient cl);
void insertThis(String fileNname, EthernetClient cl);
void insertBlock(uint8_t operation, EthernetClient cl);
