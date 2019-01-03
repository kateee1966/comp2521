////////////////////////////////////////////////////////////////////////
// COMP2521 19T0 -- Test a Stack ADT implementation.
//
// 2018-11-29	Jashank Jeremy <jashankj@cse.unsw.edu.au>
// 2018-12-06   Wenfei Guo <zN5135080@student.unsw.edu.au>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "stack.h"
#include "testable.h"

static void test_empty_stack (void);
static void test_one_item_stack (void);
static void test_muti_item_stack (void);
static void test_muti_item_keep_pop (void);

int main (void)
{
	white_box_tests ();

	test_empty_stack ();
	test_one_item_stack ();    
	// add more tests of your own!
    
    test_muti_item_stack ();
    test_muti_item_keep_pop ();
    
	puts ("\nAll tests passed. You are awesome!");
	return EXIT_SUCCESS;
}

static void test_empty_stack (void)
{
	puts ("Test 1: testing an empty stack.\n");
	Stack s = stack_new ();
	assert (stack_size (s) == 0);
	stack_drop (s);
	puts ("Test 1 Passed\n");
}

static void test_one_item_stack (void)
{
	puts ("Test 2: testing a stack with one item.\n");
	Stack s = stack_new ();
	stack_push (s, 1);

	assert (stack_size (s) == 1);

	assert (stack_pop (s) == 1);
	assert (stack_size (s) == 0);

	stack_drop (s);
	puts ("Test 2 Passed\n");
}

static void test_muti_item_stack (void)
{
	puts ("Test 3: testing a stack with mutiple(21) items.\n");
	Stack s = stack_new ();
	Item it;
	
	for (int i = 0; i<= 20; i++){
        it = i;
        stack_push(s, i);
    }
	
	
	assert (stack_pop (s) == 20);
	
	stack_drop (s);
	puts ("Test 3 Passed\n");
}	

static void test_muti_item_keep_pop (void)
{
    puts ("Test 4: testing pop from 20-item to 10-item stack.\n");
	Stack s = stack_new ();
	Item it = 0;
	int i = 0;
	for (i = 0; i<= 20; i++){
        it = i;
        stack_push(s, i);
    }
	i--;
	
	while(i >= 10) {
	    it = stack_pop (s);
	    i--;
    }
	
	assert (it == 10);
	
	stack_drop (s);
	puts ("Test 4 Passed\n");
}
