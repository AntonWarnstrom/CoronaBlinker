#include "../headers/list.h"
#include "../headers/user.h"
#include "../headers/date.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main() {
	TEST_CASE("Creating list");
	struct list* test_list = list_create();
	struct user* test_external_user_1 = create_external_user(create_new_user(), 1234, create_date(14,6,2021));
	struct user* test_external_user_2 = create_external_user(create_new_user(), 6534, create_date(3,7,2021));
	struct user* test_external_user_3 = create_external_user(create_new_user(), 7564, create_date(6,3,2021));
	struct user* test_external_user_4 = create_external_user(create_new_user(), 2355, create_date(21,5,2021));

	VERIFY(list_is_empty(test_list), "list is not empty");
	//printf("%d\n", get_verification_code(test_external_user_1));

	list_append(test_list, test_external_user_1);
	VERIFY(get_user_from_list(test_list, 1), "Valid user appended");
	//printf("%d\n", get_verification_code(get_user_from_list(test_list, get_list_size(test_list))));
	
	list_append(test_list, test_external_user_2);
	VERIFY(get_user_from_list(test_list, get_list_size(test_list)), "Valid user appended");
	//printf("%d\n", get_verification_code(get_user_from_list(test_list, get_list_size(test_list))));
	
	list_append(test_list, test_external_user_3);
	VERIFY(get_user_from_list(test_list, get_list_size(test_list)), "Valid user appended");
	//printf("%d\n", get_verification_code(get_user_from_list(test_list, get_list_size(test_list))));
	
	list_append(test_list, test_external_user_4);
	VERIFY(get_user_from_list(test_list, get_list_size(test_list)), "Valid user appended");
	//printf("%d\n", get_verification_code(get_user_from_list(test_list, get_list_size(test_list))));

	list_print(test_list);

	test_list = list_remove_user(test_list, get_verification_code(get_user_from_list(test_list, get_list_size(test_list))));

	list_print(test_list);

	test_list = list_remove_user(test_list, get_verification_code(get_user_from_list(test_list, get_list_size(test_list)-2)));

	list_print(test_list);
	
}