#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "headers/user.h"

#define BUFF_SIZE 128
#undef DEBUGGING

void print_menu();
void program_shutdown();
int get_input_number();
void init();

USER user;

int main(void)
{
	init();
	bool program_running = true;
	char *buffer = malloc(sizeof(char) * 5); // Allocates memory for 5 characters

	do
	{
		print_menu();
		switch (get_input_number(1, 3, &buffer))
		{
		case 1:
			printf("Getting openingcode...\n");
			break;
		case 2:
			printf("Getting identificationcode...\n");
			break;
		case 3:
			program_running = false;
			(&buffer == NULL) ? exit(0) : program_shutdown(&buffer); // This check could probably be done inside the function block
			break;
		}
	} while (program_running == true);
	return 0;
}

void init()
{
	user = create_new_user();
}

void print_menu()
{
	printf("\nMenu\n\n");
	printf("1. Check exposures\n");
	printf("2. Report infection\n");
	printf("3. Exit the program\n");
}

/**
* @brief Continuous loop that reads value from stdin and returns if the input was allowed
* @param min - Minimum allowed user input number,
* @param max - Maximum allowed user input number,
* @param buffer - Character array for fgets to save value from stdin
* @return - Integer between 1-3 from user input
*/
int get_input_number(int min, int max, char *buffer)
{
	int num = min;

	if (min <= max)
	{
		do
		{
			printf("> ");
			fgets(buffer, BUFF_SIZE, stdin);
#ifdef DEBUGGING
			printf("%d\n", *buffer);
#endif
		} while (!isdigit(*buffer) || (sscanf(buffer, "%d", &num) && (num < min || num > max)));
	} // !isdigit(*buffer) checks for characters that has the ASCII value
#ifdef DEBUGGING
	printf("\nUser chose: %d\n ", num);
#endif
	return num;
}

void program_shutdown(char *buffer)
{
	printf("Goodbye.\n");
	free(buffer);
	exit(0);
}