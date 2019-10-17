#include "iomodule.h"
    // TODO: добавить проверку для конфигурируемых выводов

uint8_t dipinout[24][2] = {
    {1,  PIN_A6},
    {2,  PIN_A4},
    {3,  PIN_A2},
    {4,  PIN_A0},
    {5,  PIN_A8},
    {6,  PIN_A10},
    {7,  PIN_A12},
    {8,  PIN_A14},
    {9,  39},
    {10, 37},
    {11, 35},
    {12, 33},
    {13, 41},
    {14, 42},
    {15, 47},
    {16, 49},
    {17, PIN_A1},
    {18, PIN_A3},
    {19, PIN_A5},
    {20, PIN_A7},
    {21, PIN_A9},
    {22, PIN_A11},
    {23, PIN_A13},
    {24, PIN_A15}        
};

uint8_t dopinout[32][2] = {
    {1,  2},
    {2,  4},
    {3,  6},
    {4,  8},
    {5,  10},
    {6,  12},
    {7,  23},
    {8,  25},
    {9,  3},
    {10, 5},
    {11, 7},
    {12, 9},
    {13, 11},
    {14, 34},
    {15, 36},
    {16, 38},
    {17, 22},
    {18, 24},
    {19, 26},
    {20, 27},
    {21, 28},
    {22, 29},
    {23, 30},
    {24, 31},
    {25, PIN_A1},
    {26, PIN_A3},
    {27, PIN_A5},
    {28, PIN_A7},
    {29, PIN_A9},
    {30, PIN_A11},
    {31, PIN_A13},
    {32, PIN_A15}         
};

uint8_t aipinout[8][2] = {
    {1,  PIN_A1},
    {2,  PIN_A3},
    {3,  PIN_A5},
    {4,  PIN_A7},
    {5,  PIN_A9},
    {6,  PIN_A11},
    {7,  PIN_A13},
    {8,  PIN_A15}
}; 

uint8_t DI (uint8_t number){
    return dipinout[number-1][1];
};


void doInit(){
    for (uint8_t i=0;i<25;i++){
        pinMode(dopinout[i][1],OUTPUT);
    }

    for (uint8_t i = 0; i < MAX_DIGITAL_IN_PORTS; i++)
    {
        di[]
    }
    

    // добавить проверку для конфигурируемых выводов
    
}

uint8_t DO (uint8_t number){
    return dopinout[number-1][1];
}

uint8_t AI (uint8_t number){
    return aipinout[number-1][1];
}