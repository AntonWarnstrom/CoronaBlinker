#ifndef __FILE_H__
#define __FILE_H__
#include <stdbool.h>

bool check_if_file_exists(char* str, char* mode);
bool add_sentence_to_file(const char* path, const char* mode, const char* str);
void write_data_from_file_to_list(const char* path);
char* read_file(const char* path);

#endif