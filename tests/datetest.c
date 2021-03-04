#include "../headers/date.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main() {
	TEST_CASE("Creating new date");
	struct date* date1 = create_date(29, 2, 2021); // user date, valid 
	printf("%hd %hd %hd\n", getDay(date1), getMonth(date1), getYear(date1));
	VERIFY(is_date_valid(getDay(date1), getMonth(date1), getYear(date1)), "Valid leap year")

	struct date* date2 = create_date(29, 2, 2020); // user date, valid
	printf("%hd %hd %hd\n", getDay(date2), getMonth(date2), getYear(date2));
	VERIFY(is_date_valid(getDay(date2), getMonth(date2), getYear(date2)), "Not a valid leap year")

	struct date* invalid_date1 = create_date(22, 10, 2023); // external date, invalid
	printf("%hd %hd %hd\n", getDay(invalid_date1), getMonth(invalid_date1), getYear(invalid_date1));
	VERIFY(is_date_valid(getDay(invalid_date1), getMonth(invalid_date1), getYear(invalid_date1)), "All dates are valid")

	struct date* invalid_date2 = create_date(32, 10, 2021); // external date, invalid
	printf("%hd %hd %hd\n", getDay(invalid_date2), getMonth(invalid_date2), getYear(invalid_date2));
	VERIFY(is_date_valid(getDay(invalid_date2), getMonth(invalid_date2), getYear(invalid_date2)), "All dates are valid")

	struct date* invalid_date3 = create_date(10, 13, 2021); // external date, invalid
	printf("%hd %hd %hd\n", getDay(invalid_date3), getMonth(invalid_date3), getYear(invalid_date3));
	VERIFY(is_date_valid(getDay(invalid_date3), getMonth(invalid_date3), getYear(invalid_date3)), "All dates are valid")
	printf("\n\n");


	struct date* date3 = create_date(10, 10, 2021); // user date, invalid
	struct date* date4 = create_date(10, 10, 2020); // external date, invalid
	VERIFY(check_date(date3, date4), "Date difference is larger than 21 days")

	struct date* date5 = create_date(1, 1, 2021); // user date, invalid
	struct date* date6 = create_date(1, 3, 2021); // external date, invalid
	VERIFY(check_date(date5, date6), "Date difference is larger than 21 days")

	struct date* date7 = create_date(1, 1, 2021); // user date, invalid
	struct date* date8 = create_date(10, 1, 2021); // external date, invalid
	VERIFY(check_date(date7, date8), "Date difference is larger than 21 days")

	struct date* date9 = create_date(10, 10, 2021); // user date, invalid
	struct date* date10 = create_date(5, 10, 2021); // external date, invalid
	VERIFY(check_date(date9, date10), "Date difference is larger than 21 days")

	struct date* date11 = create_date(10, 10, 2021); // user date, invalid
	struct date* date12 = create_date(2, 2, 2021); // external date, invalid
	VERIFY(check_date(date11, date12), "Date difference is larger than 21 days")
}