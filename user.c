#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "headers/utils.h"
#include "headers/date.h"
#include "headers/list.h"
#include "headers/file.h"
#include "headers/main.h"

private void update_user_list(struct user *u, DATE_T date);
public uint32_t get_verification_code(struct user* u); 
/**
 * @brief User struct 
 * 
 */
public struct user
{
	bool infected;
	uint32_t verification_code;
	DATE_T date;
	LIST list;
};

/**
 * @brief Create a new user and gets a unique token from the server
 * 
 * @return public user struct* 
 */
public struct user *create_new_user()
{
	struct user *tmp = (struct user*) malloc(sizeof(struct user));
	assert(tmp);

	if (tmp != NULL) 
	{
		tmp->infected = false;
		tmp->verification_code = 0;
		tmp->date = NULL;
		tmp->list = list_create();
		return tmp;
	}
	return tmp;
}

/**
 * @brief Add a verification code to the user
 * 
 * @param u - user struct
 * @param unique_code 
 * @return public 
 */
public void add_verification_code(struct user *u, uint32_t unique_code)
{
	u->verification_code = unique_code;
	u->infected = true;
}

public void add_date(struct user *u, DATE_T date) 
{
	u->date = date;
}

public void update_list(struct user* u) 
{
	update_user_list(u, u->date);
}

public uint32_t get_verification_code(struct user *u) 
{
	return u->verification_code;
}

public struct user *add_external_user_to_file(struct user *u, uint32_t unique_code, DATE_T date)
{
	assert(u);
	assert(date);

	if (date != NULL && u != NULL && check_if_file_exists("users.bin", "rb")) {

		u->verification_code = unique_code;
		u->date = date;
		char* convertedString;
		char* s_number = concat(itoa(unique_code, convertedString, 10), "-");
		char* s_date = date_to_string(getDay(date), getMonth(date), getYear(date));

		char* s_result = concat(s_number, s_date);
		if (add_sentence_to_file("users.bin", "ab", s_result)) {
			//printf("SUCCESS");
		} else {
			//printf("FAIL");
		}
		return u;
	}
	return u;
}

public struct user *create_external_user(struct user *u, uint32_t unique_code, DATE_T date) {
		u->verification_code = unique_code;
		u->date = date;
		return u;
}

public USER get_user(){
	return return_user();
}

public DATE_T get_date(struct user *u) {
	return u->date;
}

public LIST get_list(struct user *u) {
	return u->list;
}

public void print_infection(struct user *u)
{
	assert(u);
	u->infected == true ? printf("Infection status: true") : printf("Infection status: false");
}

public bool check_infection(struct user *u)
{
	assert(u != NULL);
	return u->infected;
}

public void set_infection(struct user *u, bool infection_status)
{
	assert(u != NULL);
	u->infected = infection_status;
}

public void add_external_user_to_list(struct user* u, struct user *external_u, char* str)
{
	assert(u != NULL);
	assert(external_u != NULL);
	if (strcmp(str, "file") == 0) {
		add_external_user_to_file(external_u, external_u->verification_code, external_u->date);
	}
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
	assert(u != NULL);
	if (get_list_size(u->list) == 0)
	{
		printf("No phones has been detected.");
	}
	else
	{
		for (int i = 1; i <= get_list_size(u->list); i++)
		{
			printf("#%d User: %d - %hu.%hu.%hu\n", i, get_user_from_list(u->list, i)->verification_code, getDay(get_user_from_list(u->list, i)->date), getMonth(get_user_from_list(u->list, i)->date), getYear(get_user_from_list(u->list, i)->date));
		}
	}
}

public bool check_user_for_infection(USER user, int pos) 
{
	return check_date(get_date(user), get_date(get_user_from_list(user->list, pos)));
}

private void update_user_list(struct user* u, DATE_T date)
{
	assert(u != NULL);
	if (get_list_size(u->list) == 0)
	{
		printf("No phones to remove");
	}
	else
	{
		//printf("%d\n", get_list_size(u->list));
		for (int i = 1; i <= get_list_size(u->list); i++)
		{
			if (check_date(date, get_user_from_list(u->list, i)->date)) 
			{
			//printf("Run: %d User to be remove: %d - %hu.%hu.%hu\n\n", i, get_user_from_list(u->list, i)->verification_code, getDay(get_user_from_list(u->list, i)->date), getMonth(get_user_from_list(u->list, i)->date), getYear(get_user_from_list(u->list, i)->date));
			remove_user_from_list(u->list, i);
			}
		}
	//list_print(u->list);
	}
}