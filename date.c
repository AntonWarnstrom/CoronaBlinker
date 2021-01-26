#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>	

#include "headers/utils.h"

#undef DEBUGGING

struct date
{
	uint16_t day;
	uint16_t month;
	uint16_t year;
};

struct date *create_new_date(uint16_t day, uint16_t month, uint16_t year)
{
	struct date *tmp = (struct date *)malloc(sizeof(struct date));

	tmp->day = day;
	tmp->month = month;
	tmp->year = year;

#ifdef DEBUGGING
	printf("%d", get_identification_code());
#endif

	return tmp;
}
