#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "headers/list.h"
#include "headers/utils.h"
#include "headers/user.h"

public struct list 
{
	struct list* next;
	USER user;
};

public struct list* list_create() 
{
	struct list* list = (struct list*) malloc(sizeof (struct list));
	list->next = NULL; 
	list->user = NULL; 
	return list; 
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

public void list_remove_user(struct list* l, uint32_t user_code) 
{
	struct list* current;
	struct list* previous;

	current = l;
	previous = NULL;
	while (current != NULL) {
		if (get_verification_code(l->user) == user_code) { 
			if(previous == NULL) {
				l = current->next;
				free(current);
				current = l;
			} else {
				previous->next = current->next;
				free(current);
				current = l;
			}
		} else {
			previous = current;
			current = current->next;
		}
	}

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

public bool list_is_empty(struct list* l) 
{
	return (l != NULL);
}