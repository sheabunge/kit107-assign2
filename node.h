/**
 * @author shea
 * @date 12/04/17
 */

#include "waypoint.h"

struct list_node_int;
typedef struct list_node_int *list_node;

void init_node(list_node *node, waypoint point);

waypoint get_waypoint(list_node node);
void set_waypoint(list_node node, waypoint point);

list_node get_next_node(list_node node);
void set_next_node(list_node node, list_node next);
