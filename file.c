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
		return false;
	}
}

public bool add_sentence_to_file(const char* path, const char* mode, const char* str) {
	
	FILE * file;
    file = fopen(path, mode);
	if (fputs(concat(str, "\n"), file) == 0) {
		fclose(file);
		return true;
	} else {
		return false;
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

public void print_file(const char* path) {
 	char* buffer = 0;
    long length;
    FILE * f = fopen(path, "rb");

    if (f)
    {
      fseek(f, 0, SEEK_END);
      length = ftell(f);
      fseek(f, 0, SEEK_SET);
      buffer = (char*)malloc((length+1)*sizeof(char));
      if (buffer)
      {
        fread(buffer, sizeof(char), length, f);
      }
      fclose(f);
    }
    buffer[length] = '\0';
	for (int i = 0; i < length; i++) {
		//if(buffer[i] == '\0' || buffer[i] == '\n') { i+=2;}
    	printf("buffer[%d] == %c\n", i, buffer[i]);
    }
	
   	//printf("%s\n", buffer);

    free(buffer);
    fclose(f);
}

public int create_date_from_file(char* buffer) {

}
