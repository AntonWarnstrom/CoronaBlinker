#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <windows.h>

#include "headers/user.h"
#include "headers/date.h"
#include "headers/utils.h"
#include "headers/file.h"
#include "headers/list.h"

#define BUFF_SIZE 128
#undef DEBUGGING


private void print_menu();
private void program_shutdown();
private void init();
private int get_input_number();

USER user;
public int main(void)
{

	init();
	bool program_running = true;
	char *buffer = malloc(sizeof(char) * 20);

	do
	{
		print_menu();
		switch (get_input_number(1, 5, &buffer))
		{
		case 1:
			if (!check_infection(user)) {
				print_list(user);
				printf("\nChoose a phone to check for exposure\n");
				if (!check_user_for_infection(user, get_input_number(1, get_list_size(get_list(user)), &buffer))) {
					set_infection(user, true);
					printf("\nYou've been infected\n");
					print_infection(user);
					break;
				}
			} else {
				printf("\nYou're infected.\n");
				print_infection(user);
			}
			break;
		case 2:
			printf("Please enter your verification code.\n");

			uint32_t verification_code =  get_input_number(1000, 100000, &buffer);
			add_verification_code(user, verification_code);
			//update_list(user);
			//add_verification_code(user, verification_code, create_new_date());
			break;

		case 3:
			add_external_user_to_list(user, create_external_user(create_new_user(), get_input_number(1000, 100000, &buffer), create_new_date()), "file");
			break;
		case 4: 
			print_list(user);
			break;
		case 5:
			program_running = false;
			(buffer == NULL) ? exit(0) : program_shutdown(&buffer); // This check could probably be done inside the function 
			break;
		}
	} while (program_running);
	return 0;
}

private void init()
{
	SYSTEMTIME t;
    GetLocalTime(&t);
	uint16_t day = t.wDay;
	uint16_t month = t.wMonth;
	uint16_t year = t.wYear;
	printf("\nToday's date: %d.%d.%d\n", t.wDay, t.wMonth, t.wYear);
	user = create_new_user();
	add_date(user, create_date(day, month, year));
	write_data_from_file_to_list("users.bin");

}

public USER return_user() {
	return user;
}

private void print_menu()
{
	printf("\nWelcome\n");
	printf("1. Check exposure\n");
	printf("2. Report your infection\n");
	printf("3. Enter external phone\n");
	printf("4. Print list\n");
	printf("5. Exit the program\n");
}

/**
* @brief Continuous loop that reads value from stdin and returns if the input was allowed
* @param min - Minimum allowed user input number,
* @param max - Maximum allowed user input number,
* @param buffer - Character array for fgets to save value from stdin
* @return - Integer between 1-3 from user input
*/
private int get_input_number(int min, int max, char *buffer)
{
	int num = min;

	if (min <= max)
	{
		do
		{
			printf("> ");
			fflush(stdout);
			fgets(buffer, BUFF_SIZE, stdin);
		} while (!isdigit(*buffer) || (sscanf(buffer, "%d", &num) && (num < min || num > max)));
	} // !isdigit(*buffer) checks for if it's a valid digit between 0-9
	return num;
}

private void program_shutdown(char *buffer)
{
	printf("Goodbye.\n");
	free(buffer);
	exit(0);
}