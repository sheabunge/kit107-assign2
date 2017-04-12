// KIT107 Assignment 2: Flight Path
/*
* Specification for Flight Path
* Author Julian Dermoudy
* Version 8/4/2017
*/

#include <stdbool.h>
#include "waypoint.h"

struct flight_path_int;
typedef struct flight_path_int *flight_path;

void init_flight_path(flight_path *fp, waypoint origin, waypoint destination);
void add_next(flight_path f, waypoint interim);
char *locate(flight_path f, char *name);
char *heading(flight_path f, bool holding);
int remaining(flight_path f, char *name, bool onwards);
void skip(flight_path f);
void reverse(flight_path f);