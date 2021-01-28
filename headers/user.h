#ifndef __USER_H__
#define __USER_H__
#include <stdint.h>

typedef struct user *USER;

USER create_new_user();
void add_verification_code(USER u, uint32_t verification_code);
uint32_t get_identification_code(struct user *u);

#endif
