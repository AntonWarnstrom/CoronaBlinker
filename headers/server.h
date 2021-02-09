#ifndef __SERVER_H__
#define __SERVER_H__
#include <stdint.h>

typedef struct report* REPORT;
typedef struct date* DATE;

REPORT create_new_report(uint32_t user_identification_code, DATE date);

#endif
