#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/utils.h"

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

