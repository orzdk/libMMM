
/*  LIB3M 
    Jesper Christensen 2019
    USBMidiKlik4x4 Main Header
    https://github.com/orzdk/libMMM
*/ 

#ifndef _LIB3M_H_
#define _LIB3M_H_
#pragma once 

#include "l3m_mk_f.h"

struct tCommand{
    void ( *modFn )( midiPacket_t* pk, transParms_t tp );
    uint8_t ( *gateFn )( midiPacket_t* pk ); 
};

const struct tCommand tCmd[] = {
    { &lib3m_IDLE,            &lib3m_FALSE     }, // 0x0: Idle
    { &lib3m_OffsetB2,        &lib3m_sts_note  }, // 0x1: Transpose note
    { &lib3m_OffsetB3,        &lib3m_sts_note  }, // 0x2: Offset velocity
    { &lib3m_SetB3,           &lib3m_sts_note  }, // 0x3: Set velocity
    { &lib3m_ChannelOffsetB2, &lib3m_sts_note  }, // 0x4: Channel Transpose note
    { &lib3m_ChannelOffsetB3, &lib3m_sts_note  }, // 0x5: Channel Offset velocity
    { &lib3m_ChannelSetB3,    &lib3m_sts_note  }, // 0x6: Channel Set velocity   
    { &lib3m_MapChannel,      &lib3m_sts_nm    }, // 0x7: Map channel
    { &lib3m_SetChannel,      &lib3m_sts_nm    }, // 0x8: Set channel
    { &lib3m_MapB2,           &lib3m_sts_cc    }, // 0x9: Map CC
    { &lib3m_MapB2,           &lib3m_sts_pc    }, // 0xA: Map ProgChg
    { &lib3m_MapEvent,        &lib3m_sts_rt    }, // 0xB: Map Event
    { &lib3m_SplitKb,         &lib3m_sts_note  }, // 0xC: Split Notes
    { &lib3m_IDLE,            &lib3m_FALSE     }, // 0xD: Idle
    { &lib3m_IDLE,            &lib3m_FALSE     }, // 0xE: Idle
    { &lib3m_IDLE,            &lib3m_FALSE     }  // 0xF: Idle
};

#endif

