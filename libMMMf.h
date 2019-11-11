#pragma once 

void eventIncByte(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t x2){
  pck->packet[x] += y;
}

void eventIncByteIf(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t x2){
  if (pck->packet[x1] == x2) pck->packet[x] += y;
}

void eventDecByte(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t x2){
  pck->packet[x] -= y;
}

void eventDecByteIf(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t x2){
 if (pck->packet[x1] == x2) pck->packet[x] -= y;
}

void eventSetByte(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t x2){
  pck->packet[x] = y;
}

void eventSetByteIf(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t x2){
  if (pck->packet[x1] == x2) pck->packet[x] = y;
}

void eventSetChannel(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t x2){
  pck->packet[1] = (pck->packet[1] & 0xF0) | x;
}

void eventSetChannelIf(midiPacket* pck, uint8_t x, uint8_t y, uint8_t x1, uint8_t x2){
  if (pck->packet[x1] == x2) pck->packet[1] = (pck->packet[1] & 0xF0) | x;
}

enum unitDefinitions{
  eventIncByteDef=0x0,
  eventIncByteIfDef=0x1,
  eventDecByteDef=0x2,
  eventDecByteIfDef=0x3,
  eventSetByteDef=0x4,
  eventSetByteIfDef=0x5,
  eventSetChannelDef=0x6,
  eventSetChannelIfDef=0x7
};

void lib3m_InitModules(){  
   unitFunctions[eventIncByteDef]      = (unitFunction){ "eventIncByte"      ,  &eventIncByte       }; 
   unitFunctions[eventIncByteIfDef]    = (unitFunction){ "eventIncByteIf"    ,  &eventIncByteIf     }; 
   unitFunctions[eventDecByteDef]      = (unitFunction){ "eventDecByte"      ,  &eventDecByte       };   
   unitFunctions[eventDecByteIfDef]    = (unitFunction){ "eventDecByteIf"    ,  &eventDecByteIf     };  
   unitFunctions[eventSetByteDef]      = (unitFunction){ "eventSetByte"      ,  &eventSetByte       }; 
   unitFunctions[eventSetByteIfDef]    = (unitFunction){ "eventSetByteIf"    ,  &eventSetByteIf     }; 
   unitFunctions[eventSetChannelDef]   = (unitFunction){ "eventSetChanl"     ,  &eventSetChannel    }; 
   unitFunctions[eventSetChannelIfDef] = (unitFunction){ "eventSetChanlIf"   ,  &eventSetChannelIf  }; 
}
