#pragma once 

#include "libMMMt.h"
#include "libMMMf.h"

void lib3m_ProcessEvent(midiPacket &pck)
{            
    for (int u=0;u<userUnitCount;u++){
        userUnit *uu = userUnits[u];
        (unitFunctions[uu->unitFnIdx].fnFn)( &pck, uu->x, uu->y, uu->x1, uu->y1 );                       
    }
} 

void lib3m_AddModuleUnit(char cmd[4], uint8_t fnIdx, uint8_t x, uint8_t y, uint8_t x1, uint8_t y1)
{

    userUnit* uup = (userUnit*)malloc(sizeof(userUnit)); 

    strlcpy(uup->command,cmd,sizeof(*uup->command));
    uup->unitFnIdx = fnIdx;
    uup->x = x; 
    uup->y = y;
    uup->x1 = x1; 
    uup->y1 = y1;

    userUnits[userUnitCount++] = uup;
    
}


