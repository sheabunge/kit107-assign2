// KIT107 Assignment 2: Flight Path
/*
* Implementation for Flight Path
* Author <<YOUR STUDENT ID AND NAME HERE>>
* Version <<DATE>>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "flight_path.h"
#include "node.h"

struct flight_path_int {
	list_node origin;
	list_node current;
};

/**
 * Initialise a flight path
 * @param path
 * @param origin
 * @param destination
 */
void init_flight_path(flight_path *path, waypoint origin, waypoint destination) {
	*path = (flight_path) malloc(sizeof(struct flight_path_int));
	(*path)->origin = NULL;
	(*path)->current = NULL;

	add_next(*path, origin);
	add_next(*path, destination);
}

bool is_path_empty(flight_path path) {
	return path->origin == NULL;
}

/**
 * Add an interim waypoint to the end of the flight path
 * @param path
 * @param interim
 */
void add_next(flight_path path, waypoint interim) {
	list_node node;
	init_node(&node, interim);

	/* If the path is empty, add the new node as the origin, and set it as the current node */
	if (path->origin == NULL) {
		path->origin = node;
		path->current = node;

	} else {

		/* Link the node after the current node to be after the new node */
		set_next_node(node, get_next_node(path->current));

		/* Slot in the new node just after the current node */
		set_next_node(path->current, node);
	}
}

/**
 * Locate an item in a flight path by its name
 * @param path the flight path to search
 * @param name the way-point name to search for
 * @return the UTM of the located way-point
 */
char *locate(flight_path path, char *name) {
	list_node current;
	waypoint point;
	char *utm;

	current = path->origin;
	point = get_waypoint(current);

	while (get_next_node(current) != NULL && strcmp(name, get_name(point)) != 0) {
		current = get_next_node(current);
		point = get_waypoint(current);
	}

	if (strcmp(name, get_name(point)) == 0) {
		utm = (char *) malloc(50 * sizeof(char));
		sprintf(utm, "%s %ld %ld", get_grid(point), get_easting(point), get_northing(point));
	} else {
		utm = "";
	}

	return utm;
}

/**
 * Return the name of the next waypoint in the flight path
 * @param path the flight path
 * @param holding if true, return the value of the current waypoint instead of the next one
 * @return the name of the next waypoint
 */
char *heading(flight_path path, bool holding) {
	list_node node;

	if (holding || get_next_node(path->current) == NULL) {
		node = path->current;
	} else {
		node = get_next_node(path->current);
	}

	return get_name(get_waypoint(node));
}

int remaining(flight_path path, char *name, bool onwards) {
	int count;          // final count to return from the function
	list_node current;  // current node in traversal
	waypoint point;     // waypoint value of current node

	count = 0;
	current = path->current;
	point = get_waypoint(current);

	while (get_next_node(current) != NULL && strcmp(name, get_name(point)) != 0) {
		current = get_next_node(current);
		point = get_waypoint(current);
		count++;
	}

	if (strcmp(name, get_name(point)) != 0) {
		count = 0;
	}

	return count;
}

void skip(flight_path path) {
	list_node next;

	if (is_path_empty(path)) {
		fprintf(stderr, "the flight path is empty");
	} else {
		next = get_next_node(path->current);
		set_next_node(path->current, get_next_node(next));
		free(next);
	}
}

void reverse(flight_path path) {
	list_node prev;
	list_node current;
	list_node next;

	/* Begin at the start of the list */
	current = path->origin;
	prev = NULL;

	while (current != NULL) {
		/* Get the node following the current node */
		next = get_next_node(current);

		/* Set the previous node we looked at as the new next */
		set_next_node(current, prev);

		/* Save the current node for use next time */
		prev = current;

		/* Move onto the next node in the list */
		current = next;
	}

	/* Set the beginning of the list to be the final node which was traversed
	 * i.e. what was previously the end of the list */
	path->origin = prev;
}
