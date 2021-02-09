#include <stdlib.h>
#include <assert.h>

#include "headers/list.h"
#include "headers/utils.h"

public struct list 
{
	struct list* next;
	USER user;
};

public struct list* list_create() 
{
	struct list* list_head = (struct list*) malloc(sizeof (struct list));
	list_head->next = NULL; 
	list_head->user = NULL; 
	return list_head; 
}

/**
 * @brief Adds an external user to a list
 * 
 * @param l 
 * @param user 
 * @return public 
 */
public void list_append(struct list* l, USER user) 
{
    struct list* new_list_item = (struct list*) malloc(sizeof (struct list));
	new_list_item->user = user;

    while (l->next) {
        l = l->next;
    }

    new_list_item->next = NULL;
    l->next = new_list_item;
}

public USER get_user_from_list(struct list* l, int pos) 
{
	while (pos--) {
        l = l->next;
    }
    return l->user;
}

public int get_list_size(struct list* l) 
{
    int size = 0;

    while (l->next) {
        l = l->next;
        size++;
    }

    return size;
}