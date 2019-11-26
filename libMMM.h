
/*  LIB3M 
    Jesper Christensen 2019
    Main Include Header. Put all three files in libMMM folder in Arduino library Folder
    https://github.com/orzdk/libMMM
*/ 

#ifndef _LIB3M_H_
#define _LIB3M_H_
#pragma once 

#include "libMMM_t.h"
#include "libMMM_f.h"

const struct tCommand tCmd[] = {
    {"idl", &lib3m_IDLE,            &lib3m_FALSE    }, // 0x0: Idle
    {"trn", &lib3m_OffsetB2,        &lib3m_sts_note }, // 0x1: Transpose note (transposeBy)
    {"trv", &lib3m_OffsetB3,        &lib3m_sts_note }, // 0x2: Offset velocity (offsetBy)
    {"stv", &lib3m_SetB3,           &lib3m_sts_note }, // 0x3: Set velocity (value)
    {"ctn", &lib3m_OffsetChannelB2, &lib3m_sts_note }, // 0x4: Channel Transpose note (channel, transposeBy)
    {"ctv", &lib3m_OffsetChannelB3, &lib3m_sts_note }, // 0x5: Channel Offset velocity (channel, offsetBy)
    {"cst", &lib3m_SetChannel,      &lib3m_sts_note }, // 0x6: Channel Set velocity (channel, value)    
    {"mch", &lib3m_MapChannel,      &lib3m_sts_nm   }, // 0x8: Map channel (channel, channel)
    {"stc", &lib3m_SetChannel,      &lib3m_sts_nm   }, // 0x7: Set channel (channel)
    {"mcc", &lib3m_MapB2,           &lib3m_sts_cc   }, // 0x9: Map CC (controller, controller)
    {"mpc", &lib3m_MapB2,           &lib3m_sts_pc   }, // 0xA: Map ProgChg (program, program)
    {"mev", &lib3m_MapB1,           &lib3m_sts_rt   }, // 0xB: Map Event (event, event)
    {"lsp", &lib3m_SplitKb,         &lib3m_sts_note }  // 0xC: Split Notes (splitnote, channel, channel)
};

uint8_t decBigByte(uint8_t val, uint8_t decode){ 
    return decode ? midiStatusValArr[val] : val; 
}

uint8_t encBigByte(uint8_t val) { 
    return val <= 0x7F ? val : val <= 0xF0 ? (val >> 4) - 8 : ((val & 0x0F) -1) + 0x10; 
}

#endif

