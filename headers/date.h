#ifndef __DATE_H__
#define __DATE_H__
#include <stdint.h>
#include <stdbool.h>

typedef struct date* DATE_T;

DATE_T create_new_date();
DATE_T create_date(uint16_t day, uint16_t month, uint16_t year);
bool check_date(DATE_T user_date, DATE_T external_date);
bool is_date_valid(uint16_t day, uint16_t month, uint16_t year);
bool is_leap_year(uint16_t year);
uint16_t getDay(struct date* d);
uint16_t getMonth(struct date* d);
uint16_t getYear(struct date* d);
bool get_number_of_days(struct date* date_1, struct date* date_2);
void print_date(struct date* d);
char* date_to_string(uint16_t day, uint16_t month, uint16_t year);
#endif
