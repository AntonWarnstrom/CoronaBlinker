#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

#include "headers/utils.h"
#include "headers/server.h"
#include "headers/list.h"

/**
 * @brief User struct 
 * 
 */
public struct user
{
	bool infected;
	uint32_t verification_code;
	DATE date;
	LIST list;
};

/**
 * @brief Create a new user and gets a unique token from the server
 * 
 * @return public user struct* 
 */
public struct user *create_new_user()
{
	struct user *tmp = malloc(sizeof(struct user));
	tmp->infected = false;
	tmp->list = list_create();
	return tmp;
}

/**
 * @brief Add a verification code to the user
 * 
 * @param u - user struct
 * @param unique_code 
 * @return public 
 */
public void add_verification_code(struct user* u, uint32_t unique_code, DATE date) 
{
	u->verification_code = unique_code;
	u->date = date;
	u->infected = true;
	printf("Verification code: %d\n", u->verification_code);
}

public struct user* create_external_user(struct user* u, uint32_t unique_code, DATE date) 
{
	u->verification_code = unique_code;
	u->date = date;

	return u;
}

public void check_infection(struct user* u) 
{
	u->infected == true ? printf("Infection status: true") : printf("Infection status: false");
}

public void set_infection(struct user* u, bool infection_status) {
	u->infected = infection_status;
}

public void add_external_user_to_list(struct user* u, struct user* external_u) 
{
	list_append(u->list, external_u);
	printf("%d\n", u->verification_code);
	printf("%d\n", u->infected);
	printf("External: %d\n", external_u->verification_code);
	printf("External: %d\n", external_u->infected);
}

/**
 * @brief Prints list of phones that has been in close proximity of a given users
 * 
 * @param u 
 * @return public 
 */
public void print_list(struct user* u) 
{
	for (int i = 1; i <= get_list_size(u->list); i++ ){
		printf("%d\n", get_user_from_list(u->list, i)->verification_code);
	}
}