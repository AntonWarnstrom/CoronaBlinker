#include "../headers/date.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main() {
	TEST_CASE("Creating new date");
	struct date* date1 = create_date(22, 10, 2021);
	struct date* date2 = create_date(32, 13, 2023);

	struct date* date3 = create_date(1, 10, 2021);
	struct date* date4 = create_date(10, 10, 2021);

	VERIFY(is_date_valid(getDay(date1), getMonth(date1), getYear(date1)), "All dates are valid")
	VERIFY(is_date_valid(getDay(date2), getMonth(date2), getYear(date2)), "All dates are not valid")

	VERIFY(check_date(date1, date3), "Date difference is larger than 21 days")
	VERIFY(check_date(date1, date4), "Date difference is not larger than 21 days")
}