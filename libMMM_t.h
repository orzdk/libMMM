
/*  LIB3M 
    Type Definitions
    Jesper Christensen 2019
    https://github.com/orzdk/libMMM
*/

#ifndef _LIB3M_T_H_
#define _LIB3M_T_H_
#pragma once 

#define cts_slot(s)  EEPROM_Params.transformersCable[sourcePort].transformers[s]  
#define cts_parms(s) cts_slot(s).transformer.modParms
#define cts_cmd(s)   cts_slot(s).transformer.cmdIdx
#define cts_fns(s)   tCmd[cts_cmd(s)]

#define sts_slot(s)  EEPROM_Params.transformersSerial[sourcePort].transformers[s]  
#define sts_parms(s) sts_slot(s).transformer.modParms    
#define sts_cmd(s)   sts_slot(s).transformer.cmdIdx      
#define sts_fns(s)   tCmd[sts_cmd(s)]

#define p_psts  (pk->packet[1] & 0xF0)
#define p_pchn  (pk->packet[1] & 0x0F)

typedef struct  {
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t d; 
    uint8_t s; 
    uint8_t c;    
} __packed trModParms_t;

typedef struct  {
    uint16_t cmdIdx;
    trModParms_t modParms; 
} __packed transformer_t;

typedef union  { 
    uint64_t i;
    transformer_t transformer; 
} __packed midiTransformer_t;

typedef struct {
    midiTransformer_t transformers[TRANSFORMERS_PR_CHANNEL];   
} __packed midiTransformerSlots_t; 

struct tCommand{
    char* commandName;
    void (*modFn)(midiPacket_t* pk, trModParms_t tp);
    uint8_t (*gateFn)(midiPacket_t* pk); 
};

enum tCodes{
    idl = 0x0,
    trn = 0x1,
    trv = 0x2,
    stv = 0x3,
    ctn = 0x4,
    ctv = 0x5,
    cst = 0x6,
    mch = 0x7,
    stc = 0x8,
    mcc = 0x9,
    mpc = 0xA,
    mev = 0xB,
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