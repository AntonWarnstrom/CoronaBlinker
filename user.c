#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

#include "headers/utils.h"

#define DEBUGGING

struct user
{
	bool infected;
	uint32_t identification_code;
};

struct user *create_new_user()
{
	struct user *tmp = (struct user *)malloc(sizeof(struct user));

	tmp->identification_code = get_identification_code();
	tmp->infected = false;

#ifdef DEBUGGING
	printf("User identification code: %d\n", get_identification_code());
#endif

	return tmp;
}
