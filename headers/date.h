#ifndef __DATE_H__
#define __DATE_H__
#include <stdint.h>
#include <stdbool.h>

typedef struct date* DATE;

DATE create_new_date();
DATE create_date(uint16_t day, uint16_t month, uint16_t year);
bool check_date(DATE user_date, DATE external_date);
bool is_date_valid(uint16_t day, uint16_t month, uint16_t year);
bool is_leap_year(uint16_t year);
uint16_t getDay(struct date* d);
uint16_t getMonth(struct date* d);
uint16_t getYear(struct date* d);
#endif
