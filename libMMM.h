
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
    {"mev", &lib3m_MapEvent,        &lib3m_sts_rt    }, // 0xB: Map Event
    {"lsp", &lib3m_SplitKb,         &lib3m_sts_note  }, // 0xC: Split Notes
    {"idl", &lib3m_IDLE,            &lib3m_FALSE     }, // 0xD: Idle
    {"idl", &lib3m_IDLE,            &lib3m_FALSE     }, // 0xE: Idle
    {"idl", &lib3m_IDLE,            &lib3m_FALSE     }  // 0xF: Idle
};

uint8_t midiStatusValArr[23] = {
    0x80, // 1   
    0x90, // 2   
    0xA0, // 3   
    0xB0, // 4   
    0xC0, // 5   
    0xD0, // 6   
    0xE0, // 7   
    0xF0, // 8   
    0xF1, // 9   
    0xF2, // 10   
    0xF3, // 11   
    0xF4, // 12   
    0xF5, // 13   
    0xF6, // 14   
    0xF7, // 15   
    0xF8, // 16  
    0xF9, // 17  
    0xFA, // 18   
    0xFB, // 19  
    0xFC, // 20   
    0xFD, // 21   
    0xFE, // 22   
    0xFF  // 23
};


#endif

