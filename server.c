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
	struct report *tmp;
	tmp->user_identification_code = user_identification_code;
	tmp->date = date;
	printf("%d\n", tmp->date);
	printf("Server got infection report from identification code: %d\n", tmp->user_identification_code);
	return tmp;
}

/**
 * @brief Get the user token based on a time seeded random number
 * 
 * @return public 
 */
public uint32_t get_user_token(void)
{
	srand(time(NULL));
	int random = rand();
	return random;
}

/**

static uint64_t state = 0x4d595df4d0f33173; // Or something seed-dependent
static uint64_t const multiplier = 6364136223846793005u;
static uint64_t const increment = 1442695040888963407u; // Or an arbitrary odd constant

 * @brief Rotates shifting
 * https://en.wikipedia.org/wiki/Permuted_congruential_generator
 * 
 * @param x 
 * @param r 
 * @return uint32_t 
static uint32_t rotr32(uint32_t x, unsigned r)
{
	return x >> r | x << (-r & 31);
}

uint32_t pcg32(void)
{
	uint64_t x = state;
	unsigned count = (unsigned)(x >> 59);		// 59 = 64 - 5

	state = x * multiplier + increment;
	x ^= x >> 18;								// 18 = (64 - 27)/2
	return rotr32((uint32_t)(x >> 27), count);	// 27 = 32 - 5
}

void pcg32_init(uint64_t seed)
{
	state = seed + increment;
	(void)pcg32();
}
 */
