#pragma once 

#define uix userUnits[u]->mUnitIdx
#define ux userUnits[u]->x
#define uy userUnits[u]->y
#define uz userUnits[u]->z
#define sts ((pck->packet[1] & 0xF0) >> 4)
#define stsd ((pck.packet[1] & 0xF0) >> 4)
#define chn (pck->packet[1] & 0x0F)
#define pb1 pck->packet[1]
#define pb2 pck->packet[2]
#define pb3 pck->packet[3]

typedef union  {
     uint32_t i;
     uint8_t  packet[4];
} midiPacket;

struct modUnit{
    char* command;
    void (*fnFn)(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z);
};

struct userUnit {
    uint8_t mUnitIdx;
    uint8_t x; 
    uint8_t y;
    uint8_t z; 
};

enum units{
    gtn = 0x0,
    gvo = 0x1,
    gvs = 0x2,
    ctn = 0x3,
    cvo = 0x4,
    cvs = 0x5,
    chs = 0x6,
    chm = 0x7,
    ccm = 0x8,
    pcm = 0x9,
    evm = 0xA,
    lsp = 0xB
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

