#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "headers/server.h"
#include "headers/utils.h"

#undef DEBUGGING

DATE date;

public struct report
{
	uint32_t user_identification_code;
	DATE date;
};

/**
 * @brief Create a new infection report
 * 
 * @param user_identification_code 
 * @param date 
 * @return Infection report based with identification code and date of report
 */
public struct report *create_new_report(uint32_t user_identification_code, DATE date)
{

	struct report *tmp = malloc(sizeof(struct report));
	tmp->user_identification_code = user_identification_code;
	tmp->date = date;
	printf("Server got infection report from identification code: %d\n", tmp->user_identification_code);
	return tmp;
}