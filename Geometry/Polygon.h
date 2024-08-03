#ifndef POLYGON
#define POLYGON

#include "Point.h"
#include "Line.h"
#include "LineIntersections.h"

typedef struct Polygon
{
	Point a, b, c;
}
Polygon;

Polygon newPolygon(Point a, Point b, Point c);
Polygon getLeftSideOfPolygon(Polygon polygon, Line split_line);
Polygon* splitPolygon(Polygon polygon, Line split_line);

bool isPolygonCorrect(Polygon polygon);
void correctPolygon(Polygon* polygon);

#endif