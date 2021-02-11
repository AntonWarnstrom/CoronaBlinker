#include "../headers/list.h"
#include "../headers/user.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main() {
	TEST_CASE("Creating list");
	struct list* test_list = list_create();
	struct user* test_user = create_new_user();

	VERIFY(list_is_empty(test_list), "list is not empty");

	list_append(test_list, test_user);

	VERIFY(get_user_from_list(test_list, get_list_size(test_list)), "Valid user appended")
}