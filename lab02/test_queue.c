////////////////////////////////////////////////////////////////////////
// COMP2521 19T0 -- Test a Queue ADT implementation.
//
// 2018-12-01	Jashank Jeremy <jashankj@cse.unsw.edu.au>
// 2018-12-06   Wenfei Guo <zN5135080@student.unsw.edu.au>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "queue.h"
#include "testable.h"


static void test_single_node_queue (void);
static void test_double_node_queue (void);
static void test_ten_node_queue (void);

int main (void)
{
	white_box_tests ();

	
    test_single_node_queue ();
    test_double_node_queue ();
    test_ten_node_queue ();
    
	puts ("\nAll tests passed. You are awesome!");
	return EXIT_SUCCESS;
}

static void test_single_node_queue (void)
{
    puts ("Test 1: testing a signle-node queue.\n");
	Queue q = queue_new();
	Item it = 0;
	
	queue_en(q, it);
	assert(queue_size(q) == (size_t) 1);
	
	assert (queue_de (q) == 0);
	assert(queue_size(q) == 0);
	
	queue_drop(q);
	puts ("Test 1 Passed\n");
}
static void test_double_node_queue (void)
{
    puts ("Test 2: testing a double-node queue.\n");
	Queue q = queue_new ();
	Item it = 0;
	
	queue_en(q, it);
	it = 1;
	queue_en(q, it);
	assert(queue_size(q) == (size_t) 2);
	
	assert (queue_de (q) == 0);
	assert (queue_de (q) == 1);
	assert(queue_size(q) == 0);
	

	queue_drop (q);
	puts ("Test 2 Passed\n");
}
static void test_ten_node_queue (void)
{
    puts ("Test 3: testing a ten-node queue.\n");
	Queue q = queue_new ();
	Item it = 0;
	
	int i = 0;
	while(i < 10){
	    it = i;
	    printf("i is %d\n", i);
	    queue_en(q, it);    
	    i++;
    }
    
    i = 0;
    while(i < 10){
	    assert(queue_de(q) == i);	    
	    i++;
    }
    assert(queue_size(q) == (size_t) 0);
    queue_drop(q);
	puts ("Test 3 Passed\n");
}

