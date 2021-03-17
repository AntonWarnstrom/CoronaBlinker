#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

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
	struct date *tmp = (struct date*) malloc(sizeof(struct date));
	assert(tmp != NULL);
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
		assert(tmp);

		if (tmp != NULL) {
			tmp->day = day;
			tmp->month = month;
			tmp->year = year;
			//printf("%hu %hu %hu ", tmp->day, tmp->month, tmp->year);
		}
	return tmp;
}

/**
 * @brief 
 * 
 * @param user_date user date will always be newer than external date (2021 > 2020)
 * @param external_date 
 * @return returns true if total days is greater than 21
 */
public bool check_date(struct date* date_1, struct date* date_2){
	uint16_t start_year1 = date_1->year;
	uint16_t start_year2 = date_2->year;
    uint16_t days1, days2;
	//printf("Date1> %hu.%hu.%hu \nDate2> %hu.%hu.%hu", getDay(date_1), getMonth(date_1), getYear(date_1), getDay(date_2), getMonth(date_2), getYear(date_2));
	struct date *date1 = malloc(sizeof(struct date));
	date1->day = date_1->day;
	date1->month = date_1->month;
	date1->year = date_1->year;

	struct date *date2 = malloc(sizeof(struct date));
	date2->day = date_2->day;
	date2->month = date_2->month;
	date2->year = date_2->year;

    date1->month = (date1->month + 9)%12;
    date1->year = date1->year - date1->month/10;

    date2->month = (date2->month + 9)%12;
    date2->year = date2->year - date2->month/10;
 
    days1 = 365*date1->year + date1->year/4 - date1->year/100 + date1->year/400 + (date1->month*306 + 5)/10 + ( date1->day - 1 );
    days2 = 365*date2->year + date2->year/4 - date2->year/100 + date2->year/400 + (date2->month*306 + 5)/10 + ( date2->day - 1 );
	//printf("\nTotal days: %d \n\n", (start_year1 == start_year2) ? abs(days1 - days2) : abs(days2 - days1));
    return (start_year1 == start_year2) ? (abs((days1 - days2)) > 21 ? true : false) : abs((days2 - days1)) > 21 ? true : false;
}

public bool get_number_of_days(struct date* date_1, struct date* date_2) {
	uint16_t start_year1 = date_1->year;
	uint16_t start_year2 = date_2->year;
    uint16_t days1, days2;
	printf("\nDate1> %hu.%hu.%hu \nDate2> %hu.%hu.%hu", getDay(date_1), getMonth(date_1), getYear(date_1), getDay(date_2), getMonth(date_2), getYear(date_2));
	struct date *date1 = malloc(sizeof(struct date));
	date1->day = date_1->day;
	date1->month = date_1->month;
	date1->year = date_1->year;

	struct date *date2 = malloc(sizeof(struct date));
	date2->day = date_2->day;
	date2->month = date_2->month;
	date2->year = date_2->year;

    date1->month = (date1->month + 9)%12;
    date1->year = date1->year - date1->month/10;

    date2->month = (date2->month + 9)%12;
    date2->year = date2->year - date2->month/10;
 
    days1 = 365*date1->year + date1->year/4 - date1->year/100 + date1->year/400 + (date1->month*306 + 5)/10 + ( date1->day - 1 );
    days2 = 365*date2->year + date2->year/4 - date2->year/100 + date2->year/400 + (date2->month*306 + 5)/10 + ( date2->day - 1 );
	printf("Total days: %d \n", (start_year1 == start_year2) ? days1 - days2 : days2 - days1);
    return (days1 - days2 < 0 || days1 - days2 == 0) ? false : true;
} // Return true if date1 is 'older' than date2


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
		if ((!is_leap_year(year) && day > 28)  || (is_leap_year(year) && day > 29)) 
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

public void print_date(struct date* d) 
{
	printf("%hd.%hd.%hd", d->day, d->month, d->year);
}

public char* date_to_string(uint16_t day, uint16_t month, uint16_t year) {
	char* buffer = (char*)malloc((sizeof(day) + sizeof(month) + sizeof(year)+1));

	if(sprintf(buffer, "%hu.%hu.%hu", day,month,year))  {
		//printf("%d %d %d \n", day, month, year);

		//printf("%s\n", buffer);

		return buffer;
	}
	return buffer;
}