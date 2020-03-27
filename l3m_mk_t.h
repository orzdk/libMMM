
/*  LIB3M 
    USBMidiKlik4x4 Type Definitions Header
    Jesper Christensen 2019
    https://github.com/orzdk/libMMM
*/

#ifndef _LIB3M_T_H_
#define _LIB3M_T_H_
#pragma once 
                     
#define cts_slot_i     EEPROM_Params.transformersCable[i].slot[t]
#define cts_routing    EEPROM_Params.midiRoutingRulesCable[i]
#define cts_slot(s)    EEPROM_Params.transformersCable[sourcePort].slot[s]
#define cts_parms(s)   cts_slot(s).modParms
#define cts_cmd(s)     cts_slot(s).cmdIdx
#define cts_opt(s)     cts_slot(s).cmdOpt
#define cts_fns(s)     tCmd[cts_cmd(s)]

#define sts_slot_i     EEPROM_Params.transformersSerial[i].slot[t] 
#define sts_routing    EEPROM_Params.midiRoutingRulesSerial[i]
#define sts_slot(s)    EEPROM_Params.transformersSerial[sourcePort].slot[s]
#define sts_parms(s)   sts_slot(s).modParms    
#define sts_cmd(s)     sts_slot(s).cmdIdx 
#define sts_opt(s)     sts_slot(s).cmdOpt      
#define sts_fns(s)     tCmd[sts_cmd(s)]

#define NUM_TRANSFORMER_SLOTS 2

typedef struct  {
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t s;    
} __packed transParms_t;

typedef struct  {
    uint8_t cmdIdx;
    transParms_t modParms; 
} __packed configuredTransformer;

typedef struct {
    configuredTransformer slot[NUM_TRANSFORMER_SLOTS];   
} __packed midiTransformerSlots_t; 

#endif