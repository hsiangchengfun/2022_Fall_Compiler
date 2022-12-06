#ifndef __LOC_H__
#define __LOC_H__

#include <stdint.h>

typedef struct {
    uint32_t first_line;
    uint32_t first_column;
    uint32_t last_line;
    uint32_t last_column;
} LocType;

#endif
