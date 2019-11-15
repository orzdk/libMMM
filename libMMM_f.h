#pragma once 

#define sts ((pck->packet[1] & 0xF0) >> 4)
#define stsd ((pck.packet[1] & 0xF0) >> 4)
#define chn (pck->packet[1] & 0x0F)
#define pb1 pck->packet[1]
#define pb2 pck->packet[2]
#define pb3 pck->packet[3]

void lib3m_idle(midiPacket_t* pck, transformerParms_t tp){}

void lib3m_mapB1(midiPacket_t* pck, transformerParms_t tp){
  if (pb1 == tp.x) pb1 = tp.y;
}

void lib3m_mapB2(midiPacket_t* pck, transformerParms_t tp){
  if (pb2 == tp.x) pb2 = tp.y;
}

void lib3m_offsetB2(midiPacket_t* pck, transformerParms_t tp){
  pb2 += tp.x;
}

void lib3m_offsetB3(midiPacket_t* pck, transformerParms_t tp){
  pb3 += tp.x;
}

void lib3m_setB3(midiPacket_t* pck, transformerParms_t tp){
  pb3 = tp.x;
}

void lib3m_setChannel(midiPacket_t* pck, transformerParms_t tp){
  pb1 = sts | tp.x;
}

void lib3m_offsetB2IfChannel(midiPacket_t* pck, transformerParms_t tp){
  if (chn == tp.x) pb2 += tp.y;
}

void lib3m_offsetB3IfChannel(midiPacket_t* pck, transformerParms_t tp){
  if (chn == tp.x) pb3 += tp.y;
}

void lib3m_setB3IfChannel(midiPacket_t* pck, transformerParms_t tp){
  if (chn == tp.x) pb3 = tp.y;
}

void lib3m_mapChannel(midiPacket_t* pck, transformerParms_t tp){
  if (chn == tp.x) pb1 = sts | tp.y;
}

void lib3m_splitKb(midiPacket_t* pck, transformerParms_t tp){
  if (sts <= stsNOTEON)
  if (pb2 > tp.x) 
      pb1 = (sts | tp.y);
   else 
      pb1 = (sts | tp.z);
}


