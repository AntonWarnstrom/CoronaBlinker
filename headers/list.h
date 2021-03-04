#ifndef __LIST_H__
#define __LIST_H__
#include <stdint.h>
#include <stdbool.h>

typedef struct list *LIST;
typedef struct user *USER;
typedef struct date *DATE;

bool list_is_empty(struct list* l);
USER get_user_from_list(struct list* l, int pos);
struct list* list_create();
void remove_user_from_list(struct list* l, int pos);
void list_append(struct list* l, USER user);
void list_print(struct list* l);
int get_list_size(struct list* l);

#endif
