#pragma once 

void FF_Channel_Modify(midiPacket *pck, unitParam param){
  pck->packet[1] = (pck->packet[1] & 0xF0) | param.param[0];
}

void FF_Any_Replace(midiPacket *pck, unitParam param){
  pck->packet[param.param[1]] = param.param[0];
}

void FF_Any_Modify(midiPacket *pck, unitParam param){
  if(param.param[2] == 0x1){
    pck->packet[param.param[1]] += param.param[0];
  } else
  if(param.param[2] == 0x0){
    pck->packet[param.param[1]] -= param.param[0];
  }
}

enum unitDefinitions{
  FN_CHANNEL_MODIFY=0x0,
  FN_ANY_REPLACE=0x1,
  FN_ANY_MODIFY=0x2
};

void mmm_InitUnits(){  
   unitFunctions[FN_CHANNEL_MODIFY]   = (unitFunction){ "CHANNEL_MODIFY",  &FF_Channel_Modify,  1 };   
   unitFunctions[FN_ANY_REPLACE]      = (unitFunction){ "ANY_REPLACE",     &FF_Any_Replace,     1 }; 
   unitFunctions[FN_ANY_MODIFY]       = (unitFunction){ "ANY_MODIFY",      &FF_Any_Modify,      1 }; 
}
