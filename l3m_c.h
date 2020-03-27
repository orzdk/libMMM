
/*  LIB3M 
    Jesper Christensen 2019
    Control-Display-Box Header
    https://github.com/orzdk/libMMM
*/ 

#ifndef _LIB3M_CLI_H_
#define _LIB3M_CLI_H_
#pragma once 

struct controlCommand{
    char* commandTitle;    
    char* parameterTitles[4];
};

const struct controlCommand cCmd[] = {
    { "None",        { NULL, }                          }, // 0x1: No transform
    { "Trp Nt",      { "Val", NULL, }                   }, // 0x1: Transpose note
    { "Ofs Vel",     { "Val", NULL, }                   }, // 0x2: Offset velocity
    { "Set Vel",     { "Val", NULL, }                   }, // 0x3: Set velocity
    { "C Trp Nt",    { "Val", "Chn", NULL }             }, // 0x4: Channel Transpose note
    { "C Ofs Vel",   { "Val", "Chn", NULL }             }, // 0x5: Channel Offset velocity
    { "C Set Vel",   { "Val", "Chn", NULL }             }, // 0x6: Channel Set velocity   
    { "Map Chnl",    { "Chn F", "Chn T", NULL }         }, // 0x7: Map channel
    { "Set Chnl",    { "Chn", NULL, }                   }, // 0x8: Set channel
    { "Map CC",      { "CC F", "CC T", NULL }           }, // 0x9: Map CC
    { "Map PC",      { "PC F", "PC T", NULL }           }, // 0xA: Map ProgChg
    { "Map Evt",     { "Evt F", "Evt T", NULL }         }, // 0xB: Map Event
    { "Split",       { "Note", "Chn L", "Chn H", NULL } }, // 0xC: Split Notes
    { "None",        { NULL, }                          }, // 0xD: No transform
    { "None",        { NULL, }                          }, // 0xE: No transform
    { "None",        { NULL, }                          }  // 0xF: No transform
};

#endif
