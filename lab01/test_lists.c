// COMP2521 19T0 ... lab 01: test a linked list implementation
//
// 2018-11-28	Wenfei Guo <z5135080@student.unsw.edu.au>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

int main (void)
{
	// Creates an empty list, and then prints it.
	link list = NULL;
	list_print (list);

	// Exercise1 ---- Creates a 3 node list, and then prints it.
	printf("Test 1.1: Test if node_new and list_insert_next work...\n");
	Item val_1 = 1;
	Item val_2 = 2;
	Item val_3 = 3;
	
	printf("Create the three nodes that will be put into list.\n");
	link node_one = node_new(val_1);
	link node_two = node_new(val_2);
	link node_three = node_new(val_3);
	
	printf("Put three node into list and print it.\n");
	link head = node_one;
	list_insert_next(head, node_two);
	list_insert_next(node_two, node_three);
	list_print (head);
	printf("Test 1.1 Passed!!! -----a 3-node-list is created.\n");
	
	// Exercise1 ---- Test function list_sum_items
    printf("Test 1.2: Test if list_sum_items works...\n");
    
    printf("Test 1.2.1: case with 0 element...\n");
    link ls1 = NULL;
    int sum_1 = list_sum_items(ls1);
    printf("Sum of case1.2.1 is %d.\n", sum_1);   
    printf("Test 1.2.1 Passed!!!\n");
    
    printf("Test 1.2.2: case with 1 element...\n");
    Item val_4 = 4;
    link node_four = node_new(val_4);
    link ls2 = node_four;
    int sum_2 = list_sum_items(ls2);
    printf("Sum of case1.2.2 is %d.\n", sum_2);
    printf("Test 1.2.2 Passed!!!\n");
    
    printf("Test 1.2.3: case with more than one elements...\n");
    link ls3 = head;
    int sum_3 = list_sum_items(ls3);
    printf("Sum of case1.2.3 is %d.\n", sum_3);
    printf("Test 1.2.3 Passed!!!\n");
    
    // Exercise2 ---- Test function list_drop
    printf("Test 2: Test if list_drop works...\n");
    link ls4 = head;
    list_print (ls4);
    list_drop(ls4);
    list_drop(node_four);
    //list_print (ls4);
    printf("Test 2 Passed!!!\n");
    
    // Exercise3 ---- Test function clist_new and clist_print
    printf("Test 3: Test if clist_new and clist_print works...\n");
    
    printf("Test 3.1: case with 0 element...\n");
    link ls5 = clist_new (0);
    clist_print(ls5);
    printf("Test 3.1 Passed!!!\n");
    
    printf("Test 3.2: case with 1 element...\n");
    link ls6 = clist_new (1);
    clist_print(ls6);
    printf("Test 3.2 Passed!!!\n");
    
    printf("Test 3.3: case with more than one elements...\n");
    link ls7 = clist_new (8);
    clist_print(ls7);
    list_drop(ls5);
    list_drop(ls6);
    list_drop(ls7);

    printf("Test 3.3 Passed!!!\n");
    
    // Exercise4 ---- Test function dlist_new_from_list,dlist_print and dlist_drop works
    printf("Test 4: Test if dlist_new_from_list,dlist_print and dlist_drop works...\n");
    Item val_5 = 5;
	Item val_6 = 6;
	Item val_7 = 7;
	
	printf("Create the three nodes that will be put into list.\n");
	link node_five = node_new(val_5);
	link node_six = node_new(val_6);
	link node_seven = node_new(val_7);
	
	printf("Put three node into list and print it.\n");
	link lista = node_five;
	list_insert_next(lista, node_six);
	list_insert_next(node_six, node_seven);
	list_print (lista);
	
    link ls8 = lista;
    dlink ls9 = dlist_new_from_list(ls8);
    
    printf("Test 4.1 Passed!!!\n");
    dlist_print(ls9);
    
    printf("Test 4.2 Passed!!!\n");
    dlist_drop(ls9);
    list_drop(lista);
    
    printf("Test 4.3 Passed!!!\n");
    printf("Test 4 Passed!!!\n");
	return EXIT_SUCCESS;
}
