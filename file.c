#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "headers/utils.h"
#include "headers/date.h"
#include "headers/list.h"
#include "headers/user.h"

char* read_file(const char* path);

/**
 * @brief 
 *
 * @param path Path to a file 
 * @param mode which mode a file should be opened with
 * @return bool returns true if a file exists 
 */
public bool check_if_file_exists(const char *path, const char *mode)
{
	FILE *file;
	if ((file = fopen(path, mode)))
	{
		fclose(file);
		return true;
	}
	else
	{
		fclose(file);
		return false;
	}
}

public bool add_sentence_to_file(const char* path, const char* mode, const char* str) {
	char* string = concat(str, "\n");
	FILE * file;
    file = fopen(path, mode);
	if (fwrite(string, sizeof(char), strlen(string), file) == 0) {
		fclose(file);
		return false;
	} else {
		fclose(file);
		//printf("%s", read_file(path));
		return true;
	}
}

public char* read_file(const char* path) {
	char* buffer = 0;
    long length;
    FILE * f = fopen(path, "rb");

    if (f)
    {
      fseek(f, 0, SEEK_END);
      length = ftell(f);
      fseek(f, 0, SEEK_SET);
      buffer = (char*)malloc ((length+1)*sizeof(char));
      if (buffer)
      {
        fread(buffer, sizeof(char), length, f);
      }
      fclose(f);
    }
    buffer[length] = '\0';
    fclose(f);
	return buffer;
}

public void write_data_from_file_to_list(const char* path) {
 	char* buffer = 0;
	int i;
    FILE * f = fopen(path, "rb");
	buffer = (char*)malloc ((ftell(f)+1)*sizeof(char));
    i = 1;
    while (fgets(buffer, 80, f) != NULL){
		read_data_from_string(buffer);
        i++;
    }
    fseek(f, 10, SEEK_SET);
}
