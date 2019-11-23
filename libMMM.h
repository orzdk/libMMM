
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

const struct tCommand transformerCommands[] = {
    {"idl", &lib3m_idle               }, // 0x0: Idle
    {"gtu", &lib3m_INCB2              }, // 0x1: All channels transpose note up (transposeBy)
    {"gtd", &lib3m_DECB2              }, // 0x2: All channels transpose note down (transposeBy)
    {"gvu", &lib3m_INCB3              }, // 0x3: All channels offset velocity up (offsetBy)
    {"gvd", &lib3m_DECB3              }, // 0x4: All channels offset velocity down (offsetBy)
    {"gvs", &lib3m_setB3              }, // 0x5: All channels set velocity (value)
    {"ctu", &lib3m_INCB2IfChannel     }, // 0x6: Channel transpose note up (channel, transposeBy)
    {"ctd", &lib3m_DECB2IfChannel     }, // 0x7: Channel transpose note down (channel, transposeBy)
    {"cvu", &lib3m_INCB3IfChannel     }, // 0x8: Channel offset velocity up (channel, offsetBy)
    {"cvd", &lib3m_DECB3IfChannel     }, // 0x9: Channel offset velocity down (channel, offsetBy)
    {"cvs", &lib3m_setB3IfChannel     }, // 0xA: Channel set velocity (channel, value)
    {"chs", &lib3m_setChannel         }, // 0xB: Set channel (channel)
    {"chm", &lib3m_mapChannel         }, // 0xC: Map channel (channel, channel)
    {"ccm", &lib3m_mapB2              }, // 0xD: Map CC (controller, controller)
    {"pcm", &lib3m_mapB2              }, // 0xE: Map ProgChg (program, program)
    {"evm", &lib3m_mapB1              }, // 0xF: Map Event (event, event)
    {"lsp", &lib3m_splitKb            }  // 0x10: Split Notes (splitnote, channel, channel)
};

uint8_t decBigByte(uint8_t val, uint8_t decode){ 
    return decode ? midiStatusValArr[val] : val; 
}

uint8_t encBigByte(uint8_t val) { 
    return val <= 0x7F ? val : val <= 0xF0 ? (val >> 4) - 8 : ((val & 0x0F) -1) + 0x10; 
}

#endif
