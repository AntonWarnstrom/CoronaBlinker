#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "headers/date.h"
#include "headers/utils.h"

#define DEBUGGING

private bool is_year_leap(int year);
private bool is_date_valid(uint16_t day, uint16_t month, uint16_t year);

struct date
{
	uint16_t day;
	uint16_t month;
	uint16_t year;
};

/**
 * @brief Create a new date
 * 
 * @return public struct* 
 */
public struct date *create_new_date()
{
	struct date *tmp;
	char buffer[100];

	while (true)
	{
		uint32_t day;
		uint32_t month;
		uint32_t year;

		printf("\nEnter date (dd.mm.yy): ");
		fflush(stdout);
		fgets(buffer, 1024, stdin);
		if (sscanf(buffer, "%d.%d.%d", &day, &month, &year) == 3 && is_date_valid(day, month, year))
		{
			break;
		}
	}

	return tmp;
}

/**
 * @brief Checks if given year is valid
 * 
 * @param year 
 * @return private 
 */
private bool is_leap_year(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

/**
 * @brief Checks if given dates are valid
 * 
 * @param day 
 * @param month 
 * @param year 
 * @return private 
 */
private bool is_date_valid(uint16_t day, uint16_t month, uint16_t year) 
{
	if (year > 2021)
	{
		return false;
	}

	if (month < 1 || month > 12) 
	{
		return false;
	}

	if (day < 1 || day > 31) 
	{
		return false;
	}

	if (month == 2) 
	{
		if (!is_leap_year(year) && day > 28 || is_leap_year(year) && day > 29) 
		{
			return false;
		}
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
	{
		return false;
	}

	return true; 
}