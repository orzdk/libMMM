#pragma once 

void lib3m_mapB1(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  if (pb1 == x) pb1 = y;
}

void lib3m_mapB2(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  if (pb2 == x) pb2 = y;
}

void lib3m_offsetB2(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  pb2 += x;
}

void lib3m_offsetB3(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  pb3 += x;
}

void lib3m_setB3(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  pb3 = x;
}

void lib3m_setChannel(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  pb1 = sts | x;
}

void lib3m_offsetB2IfChannel(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  if (chn == x) pb2 += y;
}

void lib3m_offsetB3IfChannel(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  if (chn == x) pb3 += y;
}

void lib3m_setB3IfChannel(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  if (chn == x) pb3 = y;
}

void lib3m_mapChannel(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  if (chn == x) pb1 = sts | y;
}

void lib3m_splitKb(midiPacket* pck, uint8_t x, uint8_t y, uint8_t z){
  if (sts <= stsNOTEON)
  if (pb2 > x) 
      pb1 = (sts | y);
   else 
      pb1 = (sts | z);
}
