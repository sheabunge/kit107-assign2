// KIT107 Assignment 2: Waypoint
/*
* Implementation for Waypoint
* Author Julian Dermoudy
* Version 8/4/2017
*/

#include <string.h>
#include <stdlib.h>
#include "waypoint.h"


struct waypoint_int {
	char name[5];
	char grid[4];
	long int easting;
	long int northing;
};

/*
* 'Constructor' for waypoint
*/
void init_waypoint(waypoint *wp, char *m, char *g, long int e, long int n)
{
	(*wp) = (waypoint)malloc(sizeof(struct waypoint_int));
	strcpy((*wp)->name, m);
	strcpy((*wp)->grid, g);
	(*wp)->easting = e;
	(*wp)->northing = n;
}

/*
* Getter for name
* Return name field
*/
char *get_name(waypoint w)
{
	return w->name;
}

/*
* Getter for grid
* Return grid field
*/
char *get_grid(waypoint w)
{
	return w->grid;
}

/*
* Getter for easting
* Return easting field
*/
long int get_easting(waypoint w)
{
	return w->easting;
}

/*
* Getter for northing
* Return northing field
*/
long int get_northing(waypoint w)
{
	return w->northing;
}

/*
* Setter for name
* Param m value to be placed into the waypoint's name field
*/
void set_name(waypoint w, char *m)
{
	strcpy(w->name, m);
}

/*
* Setter for grid
* Param g value to be placed into the waypoint's grid field
*/
void set_grid(waypoint w, char *g)
{
	strcpy(w->grid, g);
}

/*
* Setter for easting
* Param e value to be placed into the waypoint's easting field
*/
void set_easting(waypoint w, long int e)
{
	w->easting = e;
}

/*
* Setter for northing
* Param n value to be placed into the waypoint's northing field
*/
void set_northing(waypoint w, long int n)
{
	w->northing = n;
}
