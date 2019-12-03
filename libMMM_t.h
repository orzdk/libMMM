
/*  LIB3M 
    Type Definitions
    Jesper Christensen 2019
    https://github.com/orzdk/libMMM
*/

#ifndef _LIB3M_T_H_
#define _LIB3M_T_H_
#pragma once 

#define cts_slot(s)  EEPROM_Params.transformersCable[sourcePort].transformers[s]  
#define cts_parms(s) cts_slot(s).modParms
#define cts_cmd(s)   cts_slot(s).cmdIdx
#define cts_opt(s)   cts_slot(s).cmdOpt
#define cts_fns(s)   tCmd[cts_cmd(s)]

#define sts_slot(s)  EEPROM_Params.transformersSerial[sourcePort].transformers[s]  
#define sts_parms(s) sts_slot(s).modParms    
#define sts_cmd(s)   sts_slot(s).cmdIdx 
#define sts_opt(s)   sts_slot(s).cmdOpt      
#define sts_fns(s)   tCmd[sts_cmd(s)]

typedef struct  {
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t d; 
    uint8_t s;    
} __packed trModParms_t;

typedef struct  {
    uint8_t cmdIdx;
    trModParms_t modParms; 
} __packed midiTransformer_t;

typedef struct {
    midiTransformer_t transformers[TRANSFORMERS_PR_CHANNEL];   
} __packed midiTransformerSlots_t; 

struct tCommand{
    char* commandName;
    void (*modFn)(midiPacket_t* pk, trModParms_t tp);
    uint8_t (*gateFn)(midiPacket_t* pk); 
};

#endif