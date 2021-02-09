#ifndef __USER_H__
#define __USER_H__
#include <stdint.h>

typedef struct user *USER;
typedef struct date *DATE;

USER create_new_user();
uint32_t get_identification_code(struct user *u);
void add_verification_code(USER u, uint32_t verification_code, DATE date);
void check_infection(struct user* u);
void set_infection(struct user* u, bool infection_status);
void add_external_user_to_list(struct user* u, struct user* external_u);
void print_list(struct user* u);
struct user* create_external_user(struct user* u, uint32_t unique_code, DATE date);

#endif
