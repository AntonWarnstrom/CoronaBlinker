#include "../headers/file.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main() {
	VERIFY(check_if_file_exists("users.txt", "r"), "Found a file")
	VERIFY(add_sentence_to_file("users.txt", "a", "2364-10.10.2021"), "Added a sentence to file")
	VERIFY(add_sentence_to_file("users.txt", "a", "34536-10.2.2021"), "Added a sentence to file")
	print_file("users.txt");
}