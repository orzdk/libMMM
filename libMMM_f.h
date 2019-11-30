
/*  LIB3M 
    Jesper Christensen 2019
    Transformer Functions
    https://github.com/orzdk/libMMM
*/

#ifndef _LIB3M_F_H_
#define _LIB3M_F_H_
#pragma once 


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
    if (tp.c-1 == p_pchn) pk->packet[2] += (((tp.s & 8) >> 3) ? -1 : 1);
}

void lib3m_ChannelOffsetB3(midiPacket_t* pk, trModParms_t tp){
    if (tp.c-1 == p_pchn) pk->packet[3] += (((tp.s & 8) >> 3) ? -1 : 1);
}

void lib3m_SetB2(midiPacket_t* pk, trModParms_t tp){
    pk->packet[2] = tp.x;
}

void lib3m_SetB3(midiPacket_t* pk, trModParms_t tp){
    pk->packet[3] = tp.x;
}

void lib3m_ChannelSetB3(midiPacket_t* pk, trModParms_t tp){
    if (tp.c-1 == p_pchn) pk->packet[3] = tp.x;
}

void lib3m_SetChannel(midiPacket_t* pk, trModParms_t tp){
    pk->packet[1] = p_psts | (tp.x - 1);
}

void lib3m_MapB1(midiPacket_t* pk, trModParms_t tp){
    if (pk->packet[1] == tp.x) pk->packet[1] = tp.y;
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
