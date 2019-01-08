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

void bbt_leaf1(void);
void bbt_leaf3(void);
void bbt_neg_bst(void);

int main (void)
{
	white_box_tests ();

	// add more tests of your own!
    bbt_leaf1();
    bbt_leaf3();
    
    bbt_neg_bst();
    
	puts ("\nAll tests passed. You are awesome!");
	return EXIT_SUCCESS;
}

void bbt_leaf1(void){
    Item it = int_item_new(5);
    BTreeNode Tree = NULL;
    Tree = btree_insert(Tree, it);
    
    assert(Tree != NULL);
    assert(btree_search(Tree, it) != NULL);
    
    assert(btree_size(Tree) == 1);
    assert(btree_size_leaf(Tree) == 1);
    
    assert(btree_count_if(Tree, even_p) == 0);
    assert(btree_count_if(Tree, odd_p) == 1);
    assert(btree_count_if(Tree, negative_p) == 0);
    
    puts("bbt-leaf1 - passed!");
    
    btree_drop(Tree);
}

void bbt_leaf3(void){
    Item it = int_item_new(5);
    BTreeNode Tree = NULL;
    Tree = btree_insert(Tree, it);

    
    it = int_item_new(10);
    Tree = btree_insert(Tree, it);
    
    it = int_item_new(1);
    Tree = btree_insert(Tree, it);  
    
    assert(btree_size(Tree) == 3);
    assert(btree_size_leaf(Tree) == 2);
    
    assert(btree_count_if(Tree, even_p) == 1);
    assert(btree_count_if(Tree, odd_p) == 2);
    assert(btree_count_if(Tree, negative_p) == 0);
    
    puts("bbt-leaf2 - passed!");
    
    btree_drop(Tree);
}

void bbt_neg_bst(void){
    Item it = int_item_new(-5);
    BTreeNode Tree = NULL;
    Tree = btree_insert(Tree, it);

    
    it = int_item_new(-10);
    Tree = btree_insert(Tree, it);
    
    it = int_item_new(1);
    Tree = btree_insert(Tree, it);  
    
    assert(btree_size(Tree) == 3);
    assert(btree_size_leaf(Tree) == 2);
    
    assert(btree_count_if(Tree, even_p) == 1);
    assert(btree_count_if(Tree, odd_p) == 2);
    assert(btree_count_if(Tree, negative_p) == 2);
    
    puts("bbt-neg-bst - passed!");
    
    btree_drop(Tree);

}


