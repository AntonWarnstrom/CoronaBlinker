#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "headers/list.h"
#include "headers/utils.h"
#include "headers/user.h"

public void remove_user_from_list(struct list* l, int pos);

public struct list 
{
	struct list* next;
	struct list* prev;
	USER user;
};

public struct list* list_create() 
{
	struct list* list = (struct list*) malloc(sizeof (struct list));
	assert(list);

	if (list != NULL) {
		list->next = NULL; 
		list->user = NULL; 
		return list; 
	}
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

public void list_print(struct list *l)
{
	assert(l != NULL);
	if (get_list_size(l) == 0)
	{
		printf("No phones has been detected.");
	}
	else
	{
		for (int i = 1; i <= get_list_size(l); i++)
		{
			printf("User: %d\n", get_verification_code(get_user_from_list(l, i)));
		}
	}
}

public void remove_user_from_list(struct list* l, int pos) 
{
	int i=1;
	struct list* temp;
	struct list* iter;
 
	if(l != NULL)
	{
		iter = l;
		if(pos == 1)
		{
			l = l->next;
			iter->next = NULL;
			free(iter);
		}else 
		{
			while(i++ != pos) {
				iter = iter->next;
			}
			temp = iter->next;
			iter->next = temp->next;
			temp->next = NULL;
			free(temp);
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