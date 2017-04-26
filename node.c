/**
 * @author shea
 * @date 12/04/17
 */

#include <stdlib.h>
#include "node.h"

struct list_node_int {
	waypoint point;
	list_node next;
};

/**
 * Initialise a list_node struct
 * @param node an uninitialised instance of the struct
 * @param data pointer to data to place in the node
 */
void init_node(list_node *node, waypoint point) {
	*node = (list_node) malloc(sizeof(struct list_node_int));
	(*node)->point = point;
	(*node)->next = NULL;
}

/**
 * Retrieve data stored in a node
 * @param node initialised list_node struct
 * @return waypoint stored in node
 */
waypoint get_waypoint(list_node node) {
	return node->point;
}

/**
 * Set data stored in a node
 * @param node initialised list_node struct
 * @param point
 */
void set_waypoint(list_node node, waypoint point) {
	node->point = point;
}

/**
 * Retrieve the next adjacent node in the linked list
 * @param node
 * @return
 */
list_node get_next_node(list_node node) {
	return node->next;
}

/**
 * Set the next adjacent node in the linked list
 * @param node
 * @param next
 */
void set_next_node(list_node node, list_node next) {
	node->next = next;
}