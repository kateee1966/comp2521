// COMP2521 19T0 ... lab 01: a linked list implementation
//
// 2018-11-24	Jashank Jeremy <jashank.jeremy@unsw.edu.au>
// 2018-11-28	Wenfei Guo <z5135080@student.unsw.edu.au>

#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

// Remove `__unused' tags from your functions before flight.
//#define __attribute__((unused))

#include "lists.h"

/** Traverses and prints the list. */
void list_print (link list)
{
	link curr = list;
	while (curr != NULL) {
		printf ("[%d]->", curr->item);
		curr = curr->next;
	}
	puts ("|");
}

/** Create a new node, initialised with the item provided.
 * Return a pointer to node (link) */
link node_new (Item it)
{
	link n = malloc (sizeof (*n));
	if (n == NULL)
	    err (1, "couldn' t allocate");
    n->item = it;
    n->next = NULL;
	return n;
}

/** Insert a new node into a given non-empty list.
 * The node is inserted directly after the head of the list. */
void list_insert_next (link list, link node)
{
	assert (list != NULL);
	assert (node != NULL);
	node->next = list->next;
	list->next = node;
}

/** Return the sum of all items in list */
int list_sum_items (link list)
{
	link curr = list;
	int sum = 0;
	while (curr != NULL) {
		sum += curr->item;
		curr = curr->next;
	}
	return sum;
}

/** Frees all memory used in the list */
void list_drop (link list)
{
	/* before exercise 3
	assert (list != NULL);
	link curr = list;
	while (curr != NULL) {
		link temp = curr->next;
		free(curr);
		curr = temp;
	}
	*/
	if (list != NULL){
	    link curr = list;
	    link temp = curr;
	    while (curr != NULL && curr->next != list) {
	        temp = curr->next;
		    free(curr);
		    curr = temp;
	    }
    }
}


/** Create a circular list with the specified number of nodes,
 * with each link storing data from 1 to the number of nodes. */
link clist_new (int n_nodes)
{
	if (n_nodes == 0) {
	    return NULL;
    } else {
	    int it = 0;
	    link curr = node_new(1);
	    link head = curr;
	    for(int i=1; i<n_nodes; i++){
	        it = i+1;
	        curr->next = node_new(it);
	        curr = curr->next;
        }
        curr->next = head; 
	    return head;
    }
}

/** print the data in a circular fashion starting from any node */
void clist_print (link clist)
{
	if(clist != NULL){
	    
	    link curr = clist;
	    printf("[%d]->", curr->item);
	    curr = curr->next;
	    while (curr != clist) {
		    printf ("[%d]->", curr->item);
		    curr = curr->next;
	    }
	    puts ("|");
    }
}


/** Create a double-linked list which contains the same values,
 * in the same order as 'list' */
dlink dlist_new_from_list (link list)
{
	dlink dnew = malloc (sizeof (dnode));
	if (dnew == NULL)
	    err (1, "couldn' t allocate");
    dnew->item = list->item;
    dnew->next = NULL;
    dnew->prev = NULL;
    
    dlink temphead = dnew;
    dlink temp = dnew;
    link curr = list->next;
    
    while(curr != NULL){
        //temp = node;
        dnew = malloc (sizeof (dnode));
        if (dnew == NULL)
	        err (1, "couldn' t allocate");
        temp->next = dnew;
        dnew->item = curr->item;
        dnew->next = NULL;
        dnew->prev = temp;
        temp =temp->next;
        curr = curr->next;
    }

	return temphead;
}


/** Print a doubly-linked list. */
void dlist_print (dlink list)
{
	dlink curr = list;
	dlink temp = curr;
	while(curr != NULL){
	    temp = curr;
	    printf("[%d]->", curr->item);
	    curr = curr->next;
    }
    puts ("|");
    
    curr = temp;
    while(curr != NULL){
	    temp = curr;
	    printf("[%d]->", curr->item);
	    curr = curr->prev;
    }
    puts ("|");
    
}

/** Frees all the memory used in the double-linked list */
void dlist_drop (dlink list)
{
	/*assert (list != NULL);
	link curr = list;
	link temp = curr;
	while (curr != NULL && curr->next != list) {
	    temp = curr->next;
		free(curr);
		curr = temp;
	}*/
	
	assert(list != NULL);
	dlink curr = list;
	dlink temp = curr;
	while(curr != NULL){
	    temp = curr->next;
	    free(curr);
	    curr = temp;
    }
//    free(curr);
}
