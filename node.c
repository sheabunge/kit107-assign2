/**
 * node.c
 *
 * Implementation for a node element in a flight path
 *
 * @author Shea Bunge (student 407095)
 * @version 2016.04.26
 */

#include <stdlib.h>
#include "node.h"

struct list_node_int {
	waypoint point; // the waypoint data stored in this node
	list_node next; // the next node in the list
};

/**
 * Initialise a list_node struct
 * @param node  an uninitialised instance of the struct
 * @param data  pointer to data to place in the node
 */
void init_node(list_node *node, waypoint point) {
	*node = (list_node) malloc(sizeof(struct list_node_int));
	(*node)->point = point;
	(*node)->next = NULL;
}

/**
 * Retrieve data stored in a node
 * @param  node  the node to retrieve the waypoint from
 * @return       the waypoint stored in the node
 */
waypoint get_waypoint(list_node node) {
	return node->point;
}

/**
 * Set data stored in a node
 * @param  node  the node to set the waypoint data on
 * @param point  the waypoint data to store in the node
 */
void set_waypoint(list_node node, waypoint point) {
	node->point = point;
}

/**
 * Retrieve the next adjacent node in the linked list
 * @param  node  the node to retrieve the adjacent node of
 * @return       the next node in the list
 */
list_node get_next_node(list_node node) {
	return node->next;
}

/**
 * Set the next adjacent node in the linked list
 * @param node  the node to set the adjacent node of
 * @param next  the node to become the next node in the list
 */
void set_next_node(list_node node, list_node next) {
	node->next = next;
}