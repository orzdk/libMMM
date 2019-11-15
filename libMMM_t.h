#pragma once 

#define TRANSFORMERS_PR_CHANNEL 3
#define L3M_CABLE_CMD EEPROM_Params.cableTransformers[sourcePort].transformers[t].tPacket.tByte
#define L3M_CABLE_PARMS EEPROM_Params.cableTransformers[sourcePort].transformers[t].tPacket.tParms
#define L3M_SERIAL_CMD EEPROM_Params.serialTransformers[sourcePort].transformers[t].tPacket.tByte
#define L3M_SERIAL_PARMS EEPROM_Params.serialTransformers[sourcePort].transformers[t].tPacket.tParms

typedef struct  {
  uint8_t  x;
  uint8_t  y;
  uint8_t  z;
} __packed transformerParms_t;

typedef struct  {
  uint8_t  tByte;
  transformerParms_t tParms;
} __packed transformerPacket_t;

typedef union  {
    uint32_t i;
    uint8_t tByte[4];
    transformerPacket_t tPacket;
} __packed midiTransformer_t;

typedef struct {
      midiTransformer_t transformers[TRANSFORMERS_PR_CHANNEL];
} __packed channelTransformer_t;

struct modUnit{
    char* command;
    void (*fnFn)(midiPacket_t* pck, transformerParms_t tp);
};

enum tfs{
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

