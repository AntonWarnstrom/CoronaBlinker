#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

#include "headers/utils.h"
#include "headers/server.h"
#include "headers/date.h"
#include "headers/list.h"

private void update_user_list(struct user *u, DATE date);
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
public void add_verification_code(struct user *u, uint32_t unique_code, DATE date)
{
	u->verification_code = unique_code;
	u->date = date;
	u->infected = true;
	update_user_list(u, u->date);
	printf("Verification code: %d\n", u->verification_code);
}

public uint32_t get_verification_code(struct user *u) 
{
	printf("%d", u->verification_code);
	return u->verification_code;
}

public struct user *create_external_user(struct user *u, uint32_t unique_code, DATE date)
{
	u->verification_code = unique_code;
	u->date = date;
	return u;
}

public void print_infection(struct user *u)
{
	u->infected == true ? printf("Infection status: true") : printf("Infection status: false");
}

public bool check_infection(struct user *u)
{
	return u->infected;
}

public void set_infection(struct user *u, bool infection_status)
{
	u->infected = infection_status;
}

public void add_external_user_to_list(struct user* u, struct user *external_u)
{
	list_append(u->list, external_u);
}

/**
 * @brief Prints list of phones that has been in close proximity of a given users
 * 
 * @param u 
 * @return public 
 */
public void print_list(struct user *u)
{
	if (get_list_size(u->list) == 0)
	{
		printf("No phones has been detected.");
	}
	else
	{
		for (int i = 1; i <= get_list_size(u->list); i++)
		{
			printf("%d\n", get_user_from_list(u->list, i)->verification_code);
		}
	}
}

private void update_user_list(struct user *u, DATE date)
{
	if (get_list_size(u->list) == 0)
	{
		printf("No phones to remove");
	}
	else
	{
		for (int i = 1; i <= get_list_size(u->list); i++)
		{
			if (check_date(get_user_from_list(u->list, i)->date, date)) 
			{
				list_remove_user(u->list, get_user_from_list(u->list, i)->verification_code);
			}
		}
	print_list(u);
	}
}