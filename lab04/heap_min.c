#include <stdbool.h>
#include <stdlib.h>

#include "heap_min.h"

/**
 * Return `true` if the array heap with a sepcified number of items is
 * in heap order.  You must assume that the heap items are in indexes
 * 1..heap_size, and that index 0 is empty and not used to store items.
 */
bool heap_min_p (int heap[], size_t heap_size)
{
	size_t i = 0;
	i++;
	
	while (i <= heap_size) {
	    if (i > (heap_size -1)/2){
	        return true;
        }
        if (heap[i] > heap[2*i] || heap[i] > heap[2*i+1]) {
            return false;
        }
	    i++;
	}
    return true;
    
}

