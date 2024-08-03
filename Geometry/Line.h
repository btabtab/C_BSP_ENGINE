#ifndef LINE
#define LINE

#include <stdlib.h>

#include "Point.h"

typedef struct Line
{
    Point a, b;
}
Line;

Line newLine(Point a, Point b);
Line* allocateLine(Line line_data);
void freeLine(Line* line_pointer);

/*
	This gets the length of the line
	using pythag.
*/
float getLineLength(Line line);
Point getLineExtrapolation(Line line, float degree_of_extrapolation);
Line getLineExtrapolated(Line line, float degrees_of_extrapolation);
void swapLinePointsForConsistency(Line* line);
Point getMidPoint(Line line);
Point getLeftOfLine(Line line);
bool isPointLeftOfLine(Point point, Line line);

#endif