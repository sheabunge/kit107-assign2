// KIT107 Assignment 2: Harness
/*
* Assignment 2
* Author Julian Dermoudy
* Version 8/4/2017
*/

#include <stdbool.h>
#include <stdio.h>
#include "flight_path.h"


int main(int argc, char *argv[])
{
	flight_path path;	// flight path being constructed
	waypoint orig;		// origin
	waypoint dest;		// destination
	waypoint tmp;		// interim waypoint

	printf("Building flight path...");
	// set-up the two ends of the flight path
	init_waypoint(&orig, "YMHB", "55G", 541270, 5257130);
	init_waypoint(&dest, "YBBN", "56J", 511617, 6971100);

	// create basic flight path
	init_flight_path(&path,orig,dest);
	printf("%s <- ", get_name(dest));

	// insert waypoints from destination to origin
	init_waypoint(&tmp, "YSSY", "56H", 331759, 6242189);	// Sydney
	add_next(path,tmp);
	printf("YSSY <- ");

	init_waypoint(&tmp, "YSNW", "56H", 279345, 6137343);	// Nowra
	add_next(path, tmp);
	printf("YSNW <- ");

	init_waypoint(&tmp, "YMER", "55H", 758488, 5911327);	// Merimbula
	add_next(path, tmp);
	printf("YMER <- ");

	printf("%s...", get_name(orig));
	printf("done.\n\n");

	// manipulate flight path
	printf("Locating Brisbane  (YBBN): %s\n", locate(path, "YBBN"));
	printf("Locating Melbourne (YMEL): %s\n\n", locate(path, "YMEL"));

	printf("Holding at: %s %s\n", heading(path, true), locate(path, heading(path, true)));
	printf("Heading to: %s %s\n\n", heading(path, false), locate(path, heading(path, false)));

	while (remaining(path, "YSSY", true) != 1)
	{
		skip(path);
		printf("Now heading to: %s %s\n", heading(path, false), locate(path, heading(path, false)));
	}

	printf("Turning back.\n\n");
	reverse(path);

	printf("Heading directly to %s %s\n", heading(path, false), locate(path, heading(path, false)));

	return 0;
}