// KIT107 Assignment 2: Waypoint
/*
* Specification for Time
* Author Julian Dermoudy
* Version 8/4/2017
*/

struct waypoint_int;
typedef struct waypoint_int *waypoint;

void init_waypoint(waypoint *wp, char *m, char *g, long int e, long int n);
char *get_name(waypoint w);
char *get_grid(waypoint w);
long int get_easting(waypoint w);
long int get_northing(waypoint w);
void set_name(waypoint w, char *m);
void set_grid(waypoint w, char *g);
void set_easting(waypoint w, long int e);
void set_northing(waypoint w, long int n);
