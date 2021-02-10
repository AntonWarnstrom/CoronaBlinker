#ifndef __LIST_H__
#define __LIST_H__
#include <stdint.h>

typedef struct list *LIST;
typedef struct user *USER;
typedef struct date *DATE;

struct list* list_create();
void list_append(struct list* l, USER user);
void list_remove_user(struct list* l, uint32_t user);
int get_list_size(struct list* l);
USER get_user_from_list(struct list* l, int pos);

#endif
