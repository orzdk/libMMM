
/*  LIB3M 
    Jesper Christensen 2019
    Main Include Header. Put all three files in libMMM folder in Arduino library Folder
    https://github.com/orzdk/libMMM
*/ 

#ifndef _LIB3M_H_
#define _LIB3M_H_
#pragma once 

#include "libMMM_f.h"

const struct tCommand tCmd[] = {
    {"idl", &lib3m_IDLE,            &lib3m_FALSE     }, // 0x0: Idle
    {"trn", &lib3m_OffsetB2,        &lib3m_sts_note  }, // 0x1: Transpose note
    {"trv", &lib3m_OffsetB3,        &lib3m_sts_note  }, // 0x2: Offset velocity
    {"stv", &lib3m_SetB3,           &lib3m_sts_note  }, // 0x3: Set velocity
    {"ctn", &lib3m_ChannelOffsetB2, &lib3m_sts_note  }, // 0x4: Channel Transpose note
    {"ctv", &lib3m_ChannelOffsetB3, &lib3m_sts_note  }, // 0x5: Channel Offset velocity
    {"cst", &lib3m_ChannelSetB3,    &lib3m_sts_note  }, // 0x6: Channel Set velocity   
    {"mch", &lib3m_MapChannel,      &lib3m_sts_nm    }, // 0x7: Map channel
    {"stc", &lib3m_SetChannel,      &lib3m_sts_nm    }, // 0x8: Set channel
    {"mcc", &lib3m_MapB2,           &lib3m_sts_cc    }, // 0x9: Map CC
    {"mpc", &lib3m_MapB2,           &lib3m_sts_pc    }, // 0xA: Map ProgChg
    {"mev", &lib3m_MapB1,           &lib3m_sts_rt    }, // 0xB: Map Event
    {"lsp", &lib3m_SplitKb,         &lib3m_sts_note  }  // 0xC: Split Notes
};

uint8_t midiStatusValArr[23] = {
    0x80,    0x90,    0xA0,    0xB0,    0xC0,    0xD0,    
    0xE0,    0xF0,    0xF1,    0xF2,    0xF3,    0xF4,    
    0xF5,    0xF6,    0xF7,    0xF8,    0xF9,    0xFA,    
    0xFB,    0xFC,    0xFD,    0xFE,    0xFF
};

uint8_t decBigByte(uint8_t val, uint8_t decode){ 
    return decode ? midiStatusValArr[val] : val; 
}

uint8_t encBigByte(uint8_t val) { 
    return val <= 0x7F ? val : val <= 0xF0 ? (val >> 4) - 8 : ((val & 0x0F) -1) + 0x10; 
}

#endif

