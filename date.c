#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "headers/date.h"
#include "headers/utils.h"

#define DEBUGGING

public bool is_leap_year(uint16_t year);
public bool is_date_valid(uint16_t day, uint16_t month, uint16_t year);

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
	struct date *tmp = malloc(sizeof(struct date));
	char buffer[100];

	while (true)
	{
		uint16_t day;
		uint16_t month;
		uint16_t year;

		printf("\nEnter date (dd.mm.yy): ");
		fflush(stdout);
		fgets(buffer, 1024, stdin);
		if (sscanf(buffer, "%hu.%hu.%hu", &day, &month, &year) == 3 && is_date_valid(day, month, year))
		{
			tmp->day = day;
			tmp->month = month;
			tmp->year = year;
			break;
		}
	}
	return tmp;
}

public struct date *create_date(uint16_t day, uint16_t month, uint16_t year)
{
		struct date *tmp = malloc(sizeof(struct date));
		tmp->day = day;
		tmp->month = month;
		tmp->year = year;
		return tmp;
}

/**
 * @brief 
 * 
 * @param user_date 
 * @param external_date 
 * @return bool 
 */
public bool check_date(DATE user_date, DATE external_date) 
{
	int year_difference;
	int start_month = external_date->month;
	int total_days = (external_date->month % 2 == 0) ? (30 - external_date->day) : (31 - external_date->day);

	for (int i = external_date->month; i < user_date->month; i++) 
	{
		total_days += (i % 2 == 0) ? (i == 2 && start_month != 2) ? (is_leap_year(external_date->year) ? 28 : 29) : 30 : 31;
	}
	for (int i = external_date->year; i < user_date->year; i++) 
	{
		year_difference += is_leap_year(i) ? 364 : 365;
	}
	return ((total_days + (external_date->year != user_date->year) ? user_date->month : (user_date->month + year_difference)) > 21) ? false : true;
}

/**
 * @brief Checks if given year is valid
 * 
 * @param year 
 * @return bool 
 */
public bool is_leap_year(uint16_t year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

/**
 * @brief Checks if given dates are valid
 * 
 * @param day 
 * @param month 
 * @param year 
 * @return bool 
 */
public bool is_date_valid(uint16_t day, uint16_t month, uint16_t year) 
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

public uint16_t getDay(struct date* d) 
{
	return d->day;
}

public uint16_t getMonth(struct date* d) 
{
	return d->month;
}

public uint16_t getYear(struct date* d) 
{
	return d->year;
}