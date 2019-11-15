#pragma once 

#include "libMMM_t.h"
#include "libMMM_f.h"

const struct modUnit transformerCommands[] = {
    {"idl", &lib3m_idle                 },
    {"gtn", &lib3m_offsetB2             },
    {"gvo", &lib3m_offsetB3             },
    {"gvs", &lib3m_setB3                },
    {"ctn", &lib3m_offsetB2IfChannel    },
    {"cvo", &lib3m_offsetB3IfChannel    },
    {"cvs", &lib3m_setB3IfChannel       },
    {"chs", &lib3m_setChannel           },
    {"chm", &lib3m_mapChannel           },
    {"ccm", &lib3m_mapB2                },
    {"pcm", &lib3m_mapB2                },
    {"evm", &lib3m_mapB1                },
    {"lsp", &lib3m_splitKb              }
};