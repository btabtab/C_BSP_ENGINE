#include "Polygon.h"

Polygon newPolygon(Point a, Point b, Point c)
{
	return (Polygon){a, b, c};
}

Polygon getLeftSideOfPolygon(Polygon polygon, Line split_line)
{
	Polygon ret;
	Line polygon_lines[3];
	
	return ret;
}

Polygon* splitPolygon(Polygon polygon, Line split_line)
{
	static Polygon ret[2];
	return ret;
}

bool isPolygonCorrect(Polygon polygon)
{
	return 0;
}

void correctPolygon(Polygon* polygon)
{
}