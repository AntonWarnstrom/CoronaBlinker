#ifndef __DATE_H__
#define __DATE_H__
#include <stdint.h>

typedef struct date* DATE;

DATE create_new_date();
bool check_date(DATE user_date, DATE external_date);

#endif
