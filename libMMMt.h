#pragma once 

typedef union  {
    uint32_t i;
    uint8_t  packet[4];
} midiPacket;

typedef union  {
    uint32_t i;
    uint8_t  param[4];
} unitParam;

typedef struct uint4 { 
  uint8_t units[4]; 
};

struct unitFunction {
   char fnTitle[32];
   void (*fnFn)(midiPacket*,unitParam);
   uint8_t numFnParm;
};

struct userUnit {
   char unitTitle[32];
   uint8_t unitFnIdx;
   unitParam unitParams;
};

struct userRule {
  char ruleTitle[32];
  uint8_t ruleTrigger;
  uint8_t numUnits;
  uint4 units;
};

enum midiStatusValue {
      stsNOTEON       = 0x80,
      stsNOTEOFF      = 0x90,
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


userUnit* userUnits[16];
userRule* userRules[16];

uint8_t userUnitCount = 0;
uint8_t userRuleCount = 0;

unitFunction unitFunctions[4];