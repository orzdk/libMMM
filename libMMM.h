
/* 
    LIB3M 
    Jesper Christensen 2019
    https://github.com/orzdk/libMMM
*/

#ifndef _LIB3M_H_
#define _LIB3M_H_
#pragma once 

#include "libMMM_t.h"
#include "libMMM_f.h"

const struct tCommand transformerCommands[] = {
    {"idl", &lib3m_idle               }, // 0x0: Idle
    {"gtn", &lib3m_offsetB2           }, // 0x1: All channels transpose note (transposeBy)      - F0 77 77 78 0F 03 00 00 01 10 00 00 08 09 F7
    {"gvo", &lib3m_offsetB3           }, // 0x2: All channels offset velocity (offsetBy)        - F0 77 77 78 0F 03 00 00 02 10 00 00 08 09 F7
    {"gvs", &lib3m_setB3              }, // 0x3: All channels set velocity (value)              - F0 77 77 78 0F 03 00 00 03 10 00 00 08 09 F7
    {"ctn", &lib3m_offsetB2IfChannel  }, // 0x4: Channel transpose note (channel, transposeBy)  - F0 77 77 78 0F 03 00 00 04 06 0A 00 08 09 F7
    {"cvo", &lib3m_offsetB3IfChannel  }, // 0x5: Channel offset velocity (channel, offsetBy)    - F0 77 77 78 0F 03 00 00 05 06 0A 00 08 09 F7
    {"cvs", &lib3m_setB3IfChannel     }, // 0x6: Channel set velocity (channel, value)          - F0 77 77 78 0F 03 00 00 06 06 0A 00 08 09 F7
    {"chs", &lib3m_setChannel         }, // 0x7: Set channel (channel)                          - F0 77 77 78 0F 03 00 00 07 06 00 00 09 E0 F7
    {"chm", &lib3m_mapChannel         }, // 0x8: Map channel (channel, channel)                 - F0 77 77 78 0F 03 00 00 08 06 07 00 09 E0 F7
    {"ccm", &lib3m_mapB2              }, // 0x9: Map CC (controller, controller)                - F0 77 77 78 0F 03 00 00 09 10 10 00 B0 B0 F7
    {"pcm", &lib3m_mapB2              }, // 0xA: Map ProgChg (program, program)                 - F0 77 77 78 0F 03 00 00 0A 10 10 00 C0 C0 F7
    {"evm", &lib3m_mapB1              }, // 0xB: Map Event (event, event)                       - F0 77 77 78 0F 03 00 00 0B 10 10 00 FA FF F7
    {"lsp", &lib3m_splitKb            }  // 0xC: Split Notes (splitnote, channel, channel)      - F0 77 77 78 0F 03 00 00 0C FB FA 00 08 09 F7
};

#endif
