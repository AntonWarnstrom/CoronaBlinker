#include "../headers/list.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main() {
	TEST_CASE("Creating list");
	struct list* test_list = list_create();
	
	VERIFY(list_is_empty(test_list), "list is empty");

}