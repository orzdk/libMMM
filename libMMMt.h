#pragma once 

typedef union  {
    uint32_t i;
    uint8_t  packet[4];
} midiPacket;

struct unitFunction {
   char fnTitle[16];
   void (*fnFn)(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t y1);
};

struct userUnit {
   char command[4];
   uint8_t unitFnIdx;
   uint8_t x; 
   uint8_t y;
   uint8_t x1; 
   uint8_t y1;
};

userUnit* userUnits[16];
unitFunction unitFunctions[8];

uint8_t userUnitCount = 0;

enum midiStatusValue {
    stsNOTEOFF      = 0x80,
    stsNOTEON       = 0x90,
    stsKEYPRESSURE  = 0xA0,
    stsCC           = 0xB0,
    stsPC           = 0xC0,
    stsCHNLPRESSURE = 0xD0,
    stsPITCHBEND    = 0xE0,
    stsSOX          = 0xF0,
    stsTIMECODE     = 0xF1,
    stsSONGPOS      = 0xF2,
    stsSONGSELECT   = 0xF3,
    stsRESERVED1    = 0xF4,
    stsRESERVED2    = 0xF5,
    stsTUNEREQ      = 0xF6,
    stsEOX          = 0xF7,
    stsTIMECLOCK    = 0xF8,
    stsRESERVED3    = 0xF9,
    stsSTART        = 0xFA,
    stsCONTINUE     = 0xFB,
    stsSTOP         = 0xFC,
    stsRESERVED4    = 0xFD,
    stsACTIVESENSE  = 0xFE,
    stsSYSTEMRESET  = 0xFF
};     