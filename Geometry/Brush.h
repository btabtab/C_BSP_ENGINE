#ifndef BRUSH
#define BRUSH

#include "Point.h"
#include "Line.h"
#include "LineIntersections.h"

/*
    A brush is a four sided shape that will
    be used to create spaces out of the "world".
*/
typedef struct Brush
{
    Point a, b, c, d;
}
Brush;

Brush newBrush(Point a, Point b, Point c, Point d);
Brush* splitBrush(Brush brush, Line slice_line);

#endif