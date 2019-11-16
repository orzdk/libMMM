
/*  LIB3M 
    Jesper Christensen 2019
    Transformer Functions
    https://github.com/orzdk/libMMM
*/

#ifndef _LIB3M_F_H_
#define _LIB3M_F_H_
#pragma once 

void lib3m_idle(midiPacket_t* pk, transformerParms_t tp){

}

void lib3m_offsetB2(midiPacket_t* pk, transformerParms_t tp){ 
    pb2 += tp.x;
}

void lib3m_offsetB3(midiPacket_t* pk, transformerParms_t tp){
    pb3 += tp.x;
}

void lib3m_setB3(midiPacket_t* pk, transformerParms_t tp){
    pb3 = tp.x;
}

void lib3m_setChannel(midiPacket_t* pk, transformerParms_t tp){
    pb1 = sts | tp.x;
}

void lib3m_mapB1(midiPacket_t* pk, transformerParms_t tp){
    if (pb1 == tp.x) pb1 = tp.y;
}

void lib3m_mapB2(midiPacket_t* pk, transformerParms_t tp){
    if (pb2 == tp.x) pb2 = tp.y;
}

void lib3m_mapChannel(midiPacket_t* pk, transformerParms_t tp){
    if (chn == tp.x) pb1 = sts | tp.y;
}

void lib3m_offsetB2IfChannel(midiPacket_t* pk, transformerParms_t tp){
    if (chn == tp.x) pb2 += tp.y;
}

void lib3m_offsetB3IfChannel(midiPacket_t* pk, transformerParms_t tp){
    if (chn == tp.x) pb3 += tp.y;
}

void lib3m_setB3IfChannel(midiPacket_t* pk, transformerParms_t tp){
    if (chn == tp.x) pb3 = tp.y;
}

void lib3m_splitKb(midiPacket_t* pk, transformerParms_t tp){
    if (sts <= stsNOTEON)
    if (pb2 > tp.x) 
        pb1 = (sts | tp.y);
     else 
        pb1 = (sts | tp.z);
}

#endif
