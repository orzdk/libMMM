#pragma once 

#include "libMMM_t.h"
#include "libMMM_f.h"

const struct modUnit modUnits[] = {
    {"gtn", &lib3m_offsetB2             },
    {"gvo", &lib3m_offsetB3             },
    {"gvs", &lib3m_setB3                },
    {"ctn", &lib3m_offsetB2IfChannel    },
    {"cvo", &lib3m_offsetB3IfChannel    },
    {"cvs", &lib3m_setB3IfChannel       },
    {"chs", &lib3m_setChannel           },
    {"chm", &lib3m_mapChannel           },
    {"ccm", &lib3m_mapB2                },
    {"pcm", &lib3m_mapB2                },
    {"evm", &lib3m_mapB1                },
    {"lsp", &lib3m_splitKb              }
};

userUnit* userUnits[16];
uint8_t userUnitCount = 0;

void lib3m_AddUserUnit(uint8_t mUnitIdx, uint8_t x, uint8_t y, uint8_t z)
{
    userUnit* uu = (userUnit*)malloc(sizeof(userUnit)); 
    uu->mUnitIdx = mUnitIdx;
    uu->x = x;
    uu->y = y;
    uu->z = z;
    userUnits[userUnitCount++] = uu;   
}

void lib3m_ProcessEvent(midiPacket &pck)
{            
    for (int u=0;u<userUnitCount;u++){
        if (!uz||stsd==uz)(modUnits[uix].fnFn)(&pck, ux, uy, uz);
    }
} 
