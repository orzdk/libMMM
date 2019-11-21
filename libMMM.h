
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
    {"gtn", &lib3m_offsetB2           }, // 0x1: All channels transpose note (transposeBy)
    {"gvo", &lib3m_offsetB3           }, // 0x2: All channels offset velocity (offsetBy)
    {"gvs", &lib3m_setB3              }, // 0x3: All channels set velocity (value)
    {"ctn", &lib3m_offsetB2IfChannel  }, // 0x4: Channel transpose note (channel, transposeBy)
    {"cvo", &lib3m_offsetB3IfChannel  }, // 0x5: Channel offset velocity (channel, offsetBy)
    {"cvs", &lib3m_setB3IfChannel     }, // 0x6: Channel set velocity (channel, value)
    {"chs", &lib3m_setChannel         }, // 0x7: Set channel (channel)
    {"chm", &lib3m_mapChannel         }, // 0x8: Map channel (channel, channel)
    {"ccm", &lib3m_mapB2              }, // 0x9: Map CC (controller, controller)
    {"pcm", &lib3m_mapB2              }, // 0xA: Map ProgChg (program, program)
    {"evm", &lib3m_mapB1              }, // 0xB: Map Event (event, event)
    {"lsp", &lib3m_splitKb            }  // 0xC: Split Notes (splitnote, channel, channel)
};

uint8_t decBigByte(uint8_t val, uint8_t decode){ 
    return decode ? midiStatusValArr[val] : val; 
}

uint8_t encBigByte(uint8_t val) { 
    return val <= 0x7F ? val : val <= 0xF0 ? (val >> 4) - 8 : ((val & 0x0F) -1) + 0x10; 
}

#endif
