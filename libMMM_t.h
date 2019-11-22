
/*  LIB3M 
    Type Definitions
    Jesper Christensen 2019
    https://github.com/orzdk/libMMM
*/

#ifndef _LIB3M_T_H_
#define _LIB3M_T_H_
#pragma once 

#define L3M_CABLE_TR_UNIT           EEPROM_Params.transformersCable[sourcePort]
#define L3M_CABLE_TR_SLOT           L3M_CABLE_TR_UNIT.transformers[slot]
#define L3M_CABLE_TR_GATE           L3M_CABLE_TR_SLOT.tPacket.tGate.gate

#define L3M_SERIAL_TR_UNIT          EEPROM_Params.transformersSerial[sourcePort]
#define L3M_SERIAL_TR_SLOT          L3M_SERIAL_TR_UNIT.transformers[slot]
#define L3M_SERIAL_TR_GATE          L3M_SERIAL_TR_SLOT.tPacket.tGate.gate

#define BETWEEN(value, min, max) (value <= max && value >= min)

#define psts (pk->packet[1] & 0xF0)
#define pchn (pk->packet[1] & 0x0F)
#define pb1 pk->packet[1]
#define pb2 pk->packet[2]
#define pb3 pk->packet[3]

typedef struct  {
    uint8_t lower;
    uint8_t upper;
} __packed transformerStatusGate_t;

typedef union  {
    uint16_t i;
    transformerStatusGate_t gate;
} __packed transformerGate_t;

typedef struct  {
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t v;
} __packed transformerParms_t;

typedef struct  {
    uint16_t tCmdCode;
    transformerParms_t tParms; 
    transformerGate_t tGate; 
} __packed transformerPacket_t;


typedef union  { 
    uint64_t i;
    uint8_t tByte[8]; 
    transformerPacket_t tPacket; 
} __packed midiTransformer_t;


typedef struct {
      midiTransformer_t transformers[TRANSFORMERS_PR_CHANNEL];
      uint8_t slotsInUse;    
} __packed midiTransformerSlots_t; 


struct tCommand{
    char* command;
    void (*fnFn)(midiPacket_t* pk, transformerParms_t tp);
};

enum tCodes{
    idl = 0x0,
    gtn = 0x1,
    gvo = 0x2,
    gvs = 0x3,
    ctn = 0x4,
    cvo = 0x5,
    cvs = 0x6,
    chs = 0x7,
    chm = 0x8,
    ccm = 0x9,
    pcm = 0xA,
    evm = 0xB,
    lsp = 0xC
};

uint8_t midiStatusValArr[23] = {
    0x80,
    0x90,
    0xA0,
    0xB0,
    0xC0,
    0xD0,
    0xE0,
    0xF0,
    0xF1,
    0xF2,
    0xF3,
    0xF4,
    0xF5,
    0xF6,
    0xF7,
    0xF8,
    0xF9,
    0xFA,
    0xFB,
    0xFC,
    0xFD,
    0xFE,
    0xFF
};

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

#endif