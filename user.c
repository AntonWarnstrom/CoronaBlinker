#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

#include "headers/utils.h"
#include "headers/server.h"

/**
 * @brief User struct 
 * 
 */
struct user
{
	uint32_t identification_code;
	uint32_t verification_code;
};


/**
 * @brief Create a new user and gets a unique token from the server
 * 
 * @return public user struct* 
 */
public struct user *create_new_user()
{
	struct user *tmp = malloc(sizeof(struct user));
	tmp->identification_code = get_user_token();
	printf("Identification code: %d\n", tmp->identification_code);
	return tmp;
}

/**
 * @brief Add a verification code to the user
 * 
 * @param u - user struct
 * @param unique_code 
 * @return public 
 */
public void add_verification_code(struct user* u, uint32_t unique_code) 
{
	u->verification_code = unique_code;
	printf("Phone with identification code: %d\n> Requested verification code\n", u->identification_code);
	printf("Verification code: %d\n", u->verification_code);
}

/**
 * @brief Get user identification code
 * 
 * @param u - user struct
 * @return public struct* 
 */
public uint32_t get_identification_code(struct user* u) {
	return u->identification_code;
}