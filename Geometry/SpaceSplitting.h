#ifndef SPACE_SPLITTING
#define SPACE_SPLITTING

#include "Point.h"
#include "Line.h"
#include "LineIntersections.h"
#include "Plane.h"

/*
	A "Space" is an area defined by 4 planes
	that can be cut into smaller segments
	and handles tracking it's internal
	sub-spaces.
*/
typedef struct Space
{
	Plane planes[4];
	//The label of the split space.
	char label;
	//The sub_ID of the split space.
	int sub_ID;

	/*
		The space cardinality(?) is important
		for BSP rendering as it allows for
		traversal within the space.
	*/
	struct Space* left_sub_space;
	struct Space* right_sub_space;
}
Space;

Space newSpace(Point a, Point b, Point c, Point d);

#endif