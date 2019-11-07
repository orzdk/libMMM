#pragma once 

#include "libMMMt.h"
#include "libMMMf.h"


void mmm_ProcessEvent(midiPacket &pck){         
  for (int r=0;r<userRuleCount;r++){     
    if (userRules[r]->ruleTrigger == pck.packet[1]) {        
      for (int u=0;u<userRules[r]->numUnits;u++){
        userUnit* mru = userUnits[userRules[r]->units.units[u]];
        (unitFunctions[mru->unitFnIdx].fnFn)(&pck,mru->unitParams);                   
      }
    }
  }
} 

void addUserUnit(char title[32], uint8_t function, uint32_t params){

    userUnit* uup = (userUnit*)malloc(sizeof(userUnit)); 
    
    userUnit u;
    strlcpy(u.unitTitle,title,sizeof(u.unitTitle));
    u.unitFnIdx = function;
    u.unitParams.i = params;
    
    *uup = u; 
    
    userUnits[userUnitCount++] = uup;
    
}

void addUserRule(char title[32], uint8_t trigger, uint8_t numUnits, struct uint4 units){

    userRule* ul = (userRule*)malloc(sizeof(userRule)); 
    
    userRule r;
    strlcpy(r.ruleTitle,title,sizeof(r.ruleTitle));
    r.ruleTrigger = trigger;
    r.numUnits = numUnits;
    r.units = units;
  
    *ul = r; 
    
    userRules[userRuleCount++] = ul;
    
}