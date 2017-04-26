// KIT107 Assignment 2: Flight Path

/**
 * Implementation for Flight Path
 * @author Shea Bunge (407095)
 * @version 2016.04.26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "flight_path.h"
#include "node.h"

struct flight_path_int {
	list_node origin;  // points to the first element in the path
	list_node current; // points to the waypoint node currently being visited
};

/**
 * Initialise a flight path
 * @param path         an uninitialised instance of the struct
 * @param origin       the origin waypoint to become first waypoint in the flight path
 * @param destination  the destination waypoint to become the final waypoint in the flight path
 */
void init_flight_path(flight_path *path, waypoint origin, waypoint destination) {
	/* Allocate memory to store the struct */
	*path = (flight_path) malloc(sizeof(struct flight_path_int));

	/* Set the initial values of the struct properties to NULL as no elements have been added yet */
	(*path)->origin = NULL;
	(*path)->current = NULL;

	/* Add the origin and destination points as the first points in the flight path */
	add_next(*path, origin);
	add_next(*path, destination);
}

/**
 * Check if a flight path contains any points
 * @param  path  the flight path to check
 * @return       true if there are no points, false otherwise
 */
bool is_path_empty(flight_path path) {
	return path->origin == NULL;
}

/**
 * Add an interim waypoint to the end of the flight path
 * @param path     the flight path to modify
 * @param interim  the waypoint to insert into the flight path
 */
void add_next(flight_path path, waypoint interim) {
	list_node node; // the node to insert into the flight path
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
 * @param  path  the flight path to search
 * @param  name  the way-point name to search for
 * @return       the UTM of the located waypoint
 */
char *locate(flight_path path, char *name) {
	list_node current; // holds the current node as the list is traversed
	waypoint point;    // the waypoint data stored in the current node
	char *utm;         // a string holding the UTM of the located waypoint

	/* Begin traversing at the beginning of the flight path */
	current = path->origin;
	point = get_waypoint(current);

	/* Traverse the nodes until either the end of the path is reached, or the target point is located */
	while (get_next_node(current) != NULL && strcmp(name, get_name(point)) != 0) {
		current = get_next_node(current);
		point = get_waypoint(current);
	}

	/* Check whether the loop ended because the target was found */
	if (strcmp(name, get_name(point)) == 0) {

		/* If so, allocate enough memory to store the UTM and build it using properties from the waypoint */
		utm = (char *) malloc(50 * sizeof(char));
		sprintf(utm, "%s %ld %ld", get_grid(point), get_easting(point), get_northing(point));
	} else {

		/* If the end of the list was reached without the target being found, use an empty string in lieu of a UTM */
		utm = "";
	}

	return utm;
}

/**
 * Return the name of the next waypoint in the flight path
 * @param  path    the flight path
 * @param  holding if true, return the value of the current waypoint instead of the next one
 * @return         the name of the next waypoint
 */
char *heading(flight_path path, bool holding) {
	list_node node; // used to store the node where the desired waypoint name is stored

	/* If the flight is holding or the we are at the destination (end of the path), use the current node */
	if (holding || get_next_node(path->current) == NULL) {
		node = path->current;
	} else {
		/* Otherwise, retrieve the next node */
		node = get_next_node(path->current);
	}

	return get_name(get_waypoint(node));
}

/**
 * Determine how many points are between the current pointer and a given waypoint
 * @param  path     the flight path to check
 * @param  name     the name of the point to locate
 * @param  onwards  whether to traverse forwards (true) or backwards (false) through the flight path
 * @return          the number of points between the current point and the given point, including the given point
 */
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

/**
 * Remove the next waypoint from the flight path
 * @param path  the flight path to remove the next waypoint from
 */
void skip(flight_path path) {
	list_node next; // used to store the next waypoint, which is to be deleted

	/* If there are no points in the flight path, print a message to the error stream */
	if (is_path_empty(path)) {
		fprintf(stderr, "the flight path is empty");
	} else {

		/* Retrieve the next node in the flight path */
		next = get_next_node(path->current);

		/* Change the next node to skip over this one */
		set_next_node(path->current, get_next_node(next));

		/* Free up the memory allocated to this point */
		free(next);
	}
}

/**
 * Reverse the direction of the flight path
 * @param path  the flight path to reverse
 */
void reverse(flight_path path) {
	list_node prev;    // the node that was previously traversed
	list_node current; // the node being currently traversed over
	list_node next;    // the node following the node being currently traversed over

	/* Begin at the start of the list */
	current = path->origin;
	prev = NULL;

	/* Continue looping until the end of the list */
	while (current != NULL) {

		/* Retrieve the node following the current node */
		next = get_next_node(current);

		/* Set the previous node that we looked at as the new next */
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
