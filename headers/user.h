#ifndef __USER_H__
#define __USER_H__
#include <stdint.h>
#include <stdbool.h>

typedef struct user *USER;
typedef struct list *LIST;
typedef struct date *DATE_T;

USER create_new_user();
USER get_user();
LIST get_list(struct user *u);
DATE_T get_date(struct user *u);
uint32_t get_verification_code(struct user *u);
struct user* create_external_user(struct user* u, uint32_t unique_code, DATE_T date);
struct user *add_external_user_to_file(struct user *u, uint32_t unique_code, DATE_T date);
bool check_user_for_infection(USER user, int pos);
bool check_infection(struct user *u);
void add_date(struct user *u, DATE_T date) ;
void update_list(struct user* u);
void add_verification_code(USER u, uint32_t verification_code);
void print_infection(struct user* u);
void set_infection(struct user* u, bool infection_status);
void add_external_user_to_list(struct user* u, struct user* external_u, char* str);
void print_list(struct user* u);
#endif
