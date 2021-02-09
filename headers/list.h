#ifndef __LIST_H__
#define __LIST_H__
#include <stdint.h>

typedef struct list *LIST;
typedef struct user *USER;

struct list* list_create();
void list_append(struct list* l, USER user);
USER get_user_from_list(struct list* l, int pos);
int get_list_size(struct list* l);

#endif
