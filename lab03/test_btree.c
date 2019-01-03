////////////////////////////////////////////////////////////////////////
// COMP2521 19T0 -- Test a binary search tree implementation.
//
// 2018-12-08	Jashank Jeremy <jashankj@cse.unsw.edu.au>
// YYYY-mm-dd	Your Name Here <zNNNNNNN@student.unsw.edu.au>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "item_int.h"
#include "btree.h"
#include "testable.h"

//static void test_btree_one_leaf(void);

int main (void)
{
	white_box_tests ();

	// add more tests of your own!
    // test_btree_one_leaf();
    
	puts ("\nAll tests passed. You are awesome!");
	return EXIT_SUCCESS;
}

/*static void test_btree_one_leaf(void)
{
    Item it = int_item_new(5);
    btree_node tree = btree_node_new(it);
    assert(btree_size_leaf(tree) == 1);
}*/
