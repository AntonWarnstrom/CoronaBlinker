#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "headers/user.h"
#include "headers/date.h"
#include "headers/server.h"
#include "headers/utils.h"

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
			print_infection(user);
			break;
		case 2:
			printf("Please enter your verification code.\n");

			uint32_t verification_code =  get_input_number(1000, 100000, &buffer);
			DATE date = create_new_date();

			add_verification_code(user, verification_code, date);

			break;

		case 3:
			add_external_user_to_list(user, create_external_user(create_new_user(), get_input_number(1000, 100000, &buffer), create_new_date()));
			break;
		case 4: 
			print_list(user);
			break;
		case 5:
			program_running = false;
			(&buffer == NULL) ? exit(0) : program_shutdown(&buffer); // This check could probably be done inside the function 
			break;
		}
	} while (program_running == true);
	return 0;
}

private void init()
{
	user = create_new_user();
}

private void print_menu()
{
	printf("\nMenu\n\n");
	printf("1. Check exposures\n");
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