////////////////////////////////////////////////////////////////////////
// COMP2521 19t0 ... the Fury of Dracula
// Map.c: an implementation of a Map type
// You can change this as much as you want!
//
// 2017-11-30   v1.0    Team Dracula <cs2521@cse.unsw.edu.au>

#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

#include "map.h"
#include "places.h"

typedef struct vNode *VList;
struct vNode {
	LocationID  v;    // ALICANTE, etc
	TransportID type; // ROAD, RAIL, BOAT
	VList       next; // link to next node
};

struct map {
	int nV; // #vertices
	int nE; // #edges
	VList connections[NUM_MAP_LOCATIONS]; // array of lists
};

static void addConnections(Map);

// Create a new empty graph (for a map)
// #Vertices always same as NUM_PLACES
Map
newMap (void)
{
	Map g = malloc (sizeof *g);
	if (g == NULL) err (EX_OSERR, "couldn't allocate Map");

	(*g) = (struct map){
		.nV = NUM_MAP_LOCATIONS,
		.nE = 0,
		.connections = { NULL }
	};

	addConnections (g);
	return g;
}

// Remove an existing graph
void disposeMap (Map g)
{
	// wait, what?
	if (g == NULL) return;

	for (int i = 0; i < g->nV; i++) {
		VList curr = g->connections[i];
		while (curr != NULL) {
			VList next = curr->next;
			free (curr);
			curr = next;
		}
	}
	free (g);
}

static VList insertVList (VList L, LocationID v, TransportID type)
{
	VList new = malloc (sizeof(struct vNode));
	if (new == NULL) err (EX_OSERR, "couldn't allocate vNode");

	(*new) = (struct vNode){
		.v = v,
		.type = type,
		.next = L
	};
	return new;
}

static int inVList (VList L, LocationID v, TransportID type)
{
	for (VList cur = L; cur != NULL; cur = cur->next)
		if (cur->v == v && cur->type == type)
			return 1;

	return 0;
}

// Add a new edge to the Map/Graph
static void addLink (Map g, LocationID start, LocationID end, TransportID type)
{
	assert (g != NULL);

	// don't add edges twice
	if (inVList (g->connections[start], end, type)) return;

	g->connections[start] = insertVList(g->connections[start],end,type);
	g->connections[end] = insertVList(g->connections[end],start,type);
	g->nE++;
}

static const char *typeToString (TransportID t)
{
	switch (t) {
	case ROAD: return "road";
	case RAIL: return "rail";
	case BOAT: return "boat";
	default:   return "????";
	}
}

// Display content of Map/Graph
void showMap (Map g)
{
	assert (g != NULL);

	printf ("V=%d, E=%d\n", g->nV, g->nE);
	for (int i = 0; i < g->nV; i++)
		for (VList n = g->connections[i]; n != NULL; n = n->next)
			printf ("%s connects to %s by %s\n",
					idToName (i), idToName (n->v), typeToString (n->type));
}

// Return count of nodes
int numV (Map g)
{
	assert (g != NULL);
	return g->nV;
}

// Return count of edges of a particular type
int numE (Map g, TransportID type)
{
	assert (g != NULL);
	assert (0 <= type && type <= ANY);

	int nE = 0;
	for (int i = 0; i < g->nV; i++)
		for (VList n = g->connections[i]; n != NULL; n = n->next)
			if (n->type == type || type == ANY)
				nE++;

	return nE;
}

// Add edges to Graph representing map of Europe
static void addConnections (Map g)
{
#define IS_SENTINEL(x) ((x).v == -1 && (x).w == -1 && (x).t == ANY)
	for (int i = 0; ! IS_SENTINEL (CONNECTIONS[i]); i++)
		addLink (g, CONNECTIONS[i].v, CONNECTIONS[i].w, CONNECTIONS[i].t);
}


// Returns the number of direct connections between two nodes
// Also fills the type[] array with the various connection types
// Returns 0 if no direct connection (i.e. not adjacent in graph)
int connections (Map g, LocationID start, LocationID end, TransportID type[])
{
	assert (g != NULL);
    // TODO: complete this fucntion
    assert(g != NULL);// checks the validity of its parameters
    int i = 0;        // Returns 0 if no direct connection
    type[i] = NONE;
    int already_boat=0;
    if(inVList(g->connections[start],end,ROAD)) // transporID is road
    {
        type[i] = ROAD;
        i++;
    }
    if(inVList(g->connections[start],end,RAIL)) // transporID is rail
    {
        type[i] = RAIL;
        i++;
    }
    for (VList curr = g->connections[start]; curr != NULL; curr = curr->next) {
        if(curr->v == end &&curr->type==BOAT) {
        //check if the sea connects to the start node
           type[i]= curr->type;
           i++;
           already_boat=1;
        }
        else if(curr->type == BOAT&& already_boat!=1) {
        //check if the sea connects to the end node
             for(VList s = g->connections[curr->v];s!=NULL ;s = s->next)
             {
                if(s->v==end&&s->type == BOAT)
                {
                //which is always boat in here
                type[i] = s->type;
                i++;
                already_boat=1;
                break;
                }
             }
        }
    }
    return i;
    /*
    if(inVList(g->connections[start],end,BOAT)) // transporID is boat
    {
        type[i] = BOAT;
        i++;
    } else {

       VList cur1 = g->connections[start]; // cur1 refers the start place
       VList cur2 = g->connections[end];   // cur2 refers the end place
       
       while ((cur1 != NULL)&&(cur2 != NULL))
       {
            if ((cur1->v == cur2->v)&&(cur1->type == cur2->type)&&(idToType(cur1->v)==SEA))
            {   // same  ID           // port city              // loction of start is SEA
                // both port city on the same sea ->BOAT
               type[i] = BOAT;
               i++;
               break;
            }
            cur2 = cur2->next;
            cur1 = cur1->next;
       }
       
    }*/
      // to keep the compiler happy
    //return 0;  // to keep the compiler happy
}
