#include "../headers/date.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main() {
	TEST_CASE("Creating new date");
	struct date* date1 = create_date(1, 2, 2021);
	struct date* date2 = create_date(32, 13, 2023);
	
	VERIFY(is_date_valid(getDay(date1), getMonth(date1), getYear(date1)), "All dates are valid")
	VERIFY(is_date_valid(getDay(date2), getMonth(date2), getYear(date2)), "All dates are not valid")
}