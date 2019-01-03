////////////////////////////////////////////////////////////////////////
// COMP2521 19T0 -- A Stack ADT implementation, using arrays.
//
// 2018-11-29	Jashank Jeremy <jashankj@cse.unsw.edu.au>
// 2018-12-06   Wenfei Guo <zN5135080@student.unsw.edu.au>

#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

#include "item.h"
#include "stack.h"
#include "testable.h"

#define DEFAULT_SIZE 10

typedef struct stack stack;
static void wbt_test_single(void);
static void wbt_test_realloc(void);
static void wbt_test_reducesize(void);

struct stack {
	size_t n_items;
	size_t capacity;
	Item *items;
};

/** Create a new, empty Stack. */
stack *stack_new (void)
{
	stack *new = malloc (sizeof *new);
	if (new == NULL)
		err (EX_OSERR, "couldn't allocate stack");

	(*new) = (stack) { .n_items = 0, .capacity = DEFAULT_SIZE };

	new->items = calloc (DEFAULT_SIZE, sizeof(Item));
	if (new->items == NULL)
		err (EX_OSERR, "couldn't allocate stack items");

	return new;
}

/** Destroy a Stack. */
void stack_drop (stack *s)
{
	assert (s != NULL);
	free (s->items);
	free (s);
}

/** Add an item to the top of a Stack. */
void stack_push (stack *s, Item it)
{
	assert (s != NULL);
	/*
	assert (s->n_items >= s->capacity); // never drop below its orignial size
       
    if(s->n_items >= (DEFAULT_SIZE-1)){ // 1.1 when try to add item into full stack
        s = (stack *)realloc(s, DEFAULT_SIZE * 2);     // resize two times bigger
    }
    else if(s->n_items < (DEFAULT_SIZE * 1/4)){ // 1.3  
        s = (stack *)realloc(s, DEFAULT_SIZE * 1/2);// resize half
    }
    assert (s != NULL);
    */
    if(s->n_items >= s->capacity) {
        s->capacity = 2*s->capacity;
        //Item *k = s->items;
        s->items = realloc(s->items, s->capacity * sizeof(Item));
        
        assert(s->items != NULL);
        //assert(s->items >= k);
    }
    
    s->items[s->n_items] = it;
    s->n_items++;
    //return;
}


/** Remove an item from the top of a Stack. */
Item stack_pop (stack *s)
{   
	assert (s != NULL);
	Item it;
	it  = 0;
	if (s->n_items == 0){                         
	    perror("stack underflow");
	    //fprintf(stderr, "stack underflow!\n");
	    abort();                            // call function abort to terminate program
    } 
    
    if((s->n_items < (s->capacity * 1/4)) && (s->capacity > DEFAULT_SIZE)){ // 1.3  
        s->capacity = s->capacity / 2;// resize half
        Item *new = calloc(1, s->capacity * sizeof(Item));
    
        int i = 0;
        while(i < (int) s->capacity) {
            new[i] = s->items[i];
            i++;
        }
        
        free(s->items);
        s->items  = new;
    }
    
	it = s->items[s->n_items - 1];
	s->items[s->n_items - 1] = 0;
	s->n_items--;
	
	return it;
}

/** Get the number of items in a Stack. */
size_t stack_size (stack *s)
{
	assert (s != NULL);
	return s->n_items;
}

void white_box_tests (void)
{
	// ... you need to write these!
	wbt_test_single();
	wbt_test_realloc();
	wbt_test_reducesize();
	
	puts("\nAll wbt passed!");
	
}

static void wbt_test_single(void) 
{
    puts("test wbt single item");
    stack *s = stack_new();
    Item it = 0;
    
    stack_push(s, it);
    
    assert(s->capacity == 10);
    assert(s->n_items == 1);
    assert(*(s->items) == 0);
    
    stack_drop(s);
    
}

static void wbt_test_realloc(void) 
{
    puts("test wbt realloc after pushing 20 items");
    stack *s = stack_new();
    Item it;
    
    for(int i = 0; i <= 2*DEFAULT_SIZE; i++) {
        it = i;
        stack_push(s, it);
    }
    
    assert(s->capacity == 4*DEFAULT_SIZE);
    assert(s->n_items == 2*DEFAULT_SIZE + 1);
    assert(s->items[20] == 2 * DEFAULT_SIZE);
    
    stack_drop(s);
}

static void wbt_test_reducesize(void) 
{
    puts("test wbt reduce size from 20 to 10");
    stack *s = stack_new();
    Item it = 0;
    
    for(int i = 0; i <= DEFAULT_SIZE; i++){
        it = i;
        stack_push(s, it);
    }
    assert(s->capacity == 2*DEFAULT_SIZE);
    assert(s->n_items == DEFAULT_SIZE + 1);
    assert(s->items[10] == DEFAULT_SIZE);
    
    //[0][1][2][3][4][5][6][7][8][9][10]
    
    it = stack_pop(s); // [0][1][2][3][4][5][6][7][8][9]
    assert(it == 10);
    assert(s->capacity == 20);
    assert(s->n_items == 10);
    assert(s->items[9] == 9);
    
    it = stack_pop(s); // [0][1][2][3][4][5][6][7][8]
    it = stack_pop(s); // [0][1][2][3][4][5][6][7]
    it = stack_pop(s); // [0][1][2][3][4][5][6]
    it = stack_pop(s); // [0][1][2][3][4][5]
    it = stack_pop(s); // [0][1][2][3][4]
    it = stack_pop(s); // [0][1][2][3]
    it = stack_pop(s); // [0][1][2]
    
    // 2 < 10/4
    assert(it == 3);
    assert(s->capacity == 10);
    assert(s->n_items == 3);
    assert(s->items[2] == 2);
    assert(s->items[3] == 0);
    
    stack_drop(s);
}
