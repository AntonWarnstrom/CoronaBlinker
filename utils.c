#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "headers/utils.h"
#include "headers/date.h"
#include "headers/user.h"
#include "headers/list.h"

public char* concat(const char *s1, const char *s2)
{
	//printf("%s %s\n", s1, s2);
    char* result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
    strcat(result, s2);
	/*
	for(int i = 0; i < strlen(result); i++) {
		printf("%d %c\n", i, result[i]);
	}*/
	//printf("Result: %s\n", result);
    return result;
}

public void read_data_from_string(char* str) 
{
	uint16_t day, month, year;
	uint32_t code;
	if (sscanf(str, "%u-%hu.%hu.%hu ", &code, &day, &month, &year) == 4 && is_date_valid(day, month, year) && !check_date(get_date(get_user()), create_date(day, month, year))) {
		//printf("values from file: code:%d day:%d, month:%d, year:%d\n", code, day, month, year);

		add_external_user_to_list(get_user(), create_external_user(create_new_user(), code, create_date(day, month, year)), "notfile");
	}
}