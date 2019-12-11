
/*  LIB3M 
    Jesper Christensen 2019
    Control-Display Header
    https://github.com/orzdk/libMMM
*/ 

#ifndef _LIB3M_CLI_H_
#define _LIB3M_CLI_H_
#pragma once 


struct cliCommand{
    uint8_t commandIndex;
    uint8_t parameterCount;    
    char* commandTitle;    
    char* parameterTitles[3];
};

const struct cliCommand cCmd[] = {
    {0x1, 1, "Transpose Note",      {"Value",}                          }, // 0x1: Transpose note
    {0x2, 1, "Offset Velocity",     {"Value",}                          }, // 0x2: Offset velocity
    {0x3, 1, "Set Velocity",        {"Value",}                          }, // 0x3: Set velocity
    {0x4, 2, "C Transpose Note",    {"Value", "Channel",}               }, // 0x4: Channel Transpose note
    {0x5, 2, "C Offset Velocity",   {"Value", "Channel",}               }, // 0x5: Channel Offset velocity
    {0x6, 2, "C Set Velocity",      {"Value", "Channel",}               }, // 0x6: Channel Set velocity   
    {0x7, 2, "Map Channel",         {"ChannelIN", "ChannelOUT",}        }, // 0x7: Map channel
    {0x8, 1, "Set Channel",         {"Channel",}                        }, // 0x8: Set channel
    {0x9, 2, "Map CC",              {"CCIN", "CCOUT",}                  }, // 0x9: Map CC
    {0xA, 2, "Map PC",              {"PCIN", "PCOUT",}                  }, // 0xA: Map ProgChg
    {0xB, 2, "Map Event",           {"EventIN","EventOUT",}             }, // 0xB: Map Event
    {0xC, 3, "Split KB",            {"SplitPnt","ChnLow","ChnHigh"}     }, // 0xC: Split Notes
};

#endif
