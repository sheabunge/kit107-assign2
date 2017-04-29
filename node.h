/**
 * node.h
 *
 * Definition for a node element in a flight path
 *
 * @author Shea Bunge (student 407095)
 * @version 2016.04.26
 */

#include "waypoint.h"

struct list_node_int;
typedef struct list_node_int *list_node;

/**
 * Initialise a list_node struct
 * @param node  an uninitialised instance of the struct
 * @param data  pointer to data to place in the node
 */
void init_node(list_node *node, waypoint point);

/**
 * Retrieve data stored in a node
 * @param  node  the node to retrieve the waypoint from
 * @return       the waypoint stored in the node
 */
waypoint get_waypoint(list_node node);

/**
 * Set data stored in a node
 * @param  node  the node to set the waypoint data on
 * @param point  the waypoint data to store in the node
 */
void set_waypoint(list_node node, waypoint point);

/**
 * Retrieve the next adjacent node in the linked list
 * @param  node  the node to retrieve the adjacent node of
 * @return       the next node in the list
 */
list_node get_next_node(list_node node);

/**
 * Set the next adjacent node in the linked list
 * @param node  the node to set the adjacent node of
 * @param next  the node to become the next node in the list
 */
void set_next_node(list_node node, list_node next);
