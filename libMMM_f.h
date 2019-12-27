
/*  LIB3M 
    Jesper Christensen 2019
    Transformer Functions
    https://github.com/orzdk/libMMM
*/

#ifndef _LIB3M_F_H_
#define _LIB3M_F_H_
#pragma once 

uint8_t midiStatusValArr[23] = {
    0x80, // 1  Note off 
    0x90, // 2  Note on 
    0xA0, // 3  Poly Aftertouch 
    0xB0, // 4  CC 
    0xC0, // 5  PC  
    0xD0, // 6  Channel Aftertouch 
    0xE0, // 7  Pitch Wheel 
    0xF0, // 8  sysex 
    0xF1, // 9  common, undefined 
    0xF2, // 10 common, song pointer  
    0xF3, // 11 common, song select  
    0xF4, // 12 common, undefined   
    0xF5, // 13 common, undefined  
    0xF6, // 14 common, tune request  
    0xF7, // 15 EOX  
    0xF8, // 16 realtime, clock
    0xF9, // 17 realtime, undefined
    0xFA, // 18 realtime, start 
    0xFB, // 19 realtime, stop
    0xFC, // 20 realtime, continue
    0xFD, // 21 realtime, undefined
    0xFE, // 22 realtime, active sensing 
    0xFF  // 23 realtime, sysreset
};

#define p_psts  (pk->packet[1] & 0xF0)
#define p_pchn  (pk->packet[1] & 0x0F)

/* Gates */

uint8_t lib3m_FALSE(midiPacket_t* pk){ 
    return 0; 
}

uint8_t lib3m_sts_note(midiPacket_t* pk){
    return (unsigned)(pk->packet[1]-0x80)<=0x1F;
}

uint8_t lib3m_sts_cc(midiPacket_t* pk){
    return pk->packet[1] & 0xB0;
}

uint8_t lib3m_sts_pc(midiPacket_t* pk){
    return pk->packet[1] & 0xC0;
}

uint8_t lib3m_sts_rt(midiPacket_t* pk){
    return pk->packet[1] > 0xF0;
}

uint8_t lib3m_sts_nm(midiPacket_t* pk){
    return pk->packet[1] < 0xF0;
}

/* Modifiers */

void lib3m_IDLE(midiPacket_t* pk, trModParms_t tp){ 

}

void lib3m_OffsetB2(midiPacket_t* pk, trModParms_t tp){
    pk->packet[2] += tp.x * (((tp.s & 8) >> 3) ? -1 : 1);
}

void lib3m_OffsetB3(midiPacket_t* pk, trModParms_t tp){
    pk->packet[3] += tp.x * (((tp.s & 8) >> 3) ? -1 : 1);
}

void lib3m_ChannelOffsetB2(midiPacket_t* pk, trModParms_t tp){
    if (tp.y-1 == p_pchn) pk->packet[2] += tp.x * (((tp.s & 8) >> 3) ? -1 : 1);
}

void lib3m_ChannelOffsetB3(midiPacket_t* pk, trModParms_t tp){
    if (tp.y-1 == p_pchn) pk->packet[3] += tp.x * (((tp.s & 8) >> 3) ? -1 : 1);
}

void lib3m_ChannelSetB3(midiPacket_t* pk, trModParms_t tp){
    if (tp.y-1 == p_pchn) pk->packet[3] = tp.x;
}

void lib3m_SetB2(midiPacket_t* pk, trModParms_t tp){
    pk->packet[2] = tp.x;
}

void lib3m_SetB3(midiPacket_t* pk, trModParms_t tp){
    pk->packet[3] = tp.x;
}

void lib3m_SetChannel(midiPacket_t* pk, trModParms_t tp){
    pk->packet[1] = p_psts | (tp.x - 1);
}

void lib3m_MapEvent(midiPacket_t* pk, trModParms_t tp){
    if (pk->packet[1] == midiStatusValArr[tp.x] ) pk->packet[1] = midiStatusValArr[tp.y];
}

void lib3m_MapB2(midiPacket_t* pk, trModParms_t tp){
    if (pk->packet[2] == tp.x) pk->packet[2] = tp.y;
}

void lib3m_MapChannel(midiPacket_t* pk, trModParms_t tp){
    if (p_pchn == tp.x - 1) pk->packet[1] = p_psts | (tp.y - 1);
}

void lib3m_SplitKb(midiPacket_t* pk, trModParms_t tp){
    if (pk->packet[2] > tp.x){ 
        pk->packet[1] = (p_psts | tp.y);
    } else {
        pk->packet[1] = (p_psts | tp.z);
    }
}

#endif
