/*
	This file will define a "Plane".
	Planes differ from lines as they also
	contain the direction they will be
	drawn from and contain data relevant
	to rendering them, such as style,
	colour and if they are transparent.
*/
#ifndef WALL
#define WALL

#include "Point.h"
#include "Line.h"
#include "LineIntersections.h"

enum PlaneTypes
{
	WALL_TYPE__SOLID,
	WALL_TYPE__IMPLIED,
	WALL_TYPE__TRANSPARENT
};

typedef struct Plane
{
	Line geometry;
	/*
		Used to keep track of the plane
		so that it won't be repeated in
		the same list.
	*/
	int ID;
	//The type of plane.
	int type;
	//Controls how it will look while rendering.
	int style_ID;
}
Plane;

Plane newPlane(Point a, Point b, int type, int style_id);

Plane splitLineFromPlane(Line future_plane, Line split_line);

#endif