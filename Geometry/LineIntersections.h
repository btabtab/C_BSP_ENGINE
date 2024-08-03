#ifndef LINE_INTERSECTIONS
#define LINE_INTERSECTIONS

#include <math.h>
#include <stdbool.h>

#include "Point.h"
#include "Line.h"

/*
    This is used to store and check
    line intersection data.
*/
typedef struct LineIntersectionData
{
    Point intersection_point;
    Line* a;
    Line* b;
    bool do_lines_intersect;
    
	Point A_aa, B_ab, C_ba, D_bb;
	float top_t, top_u;
	float bottom;
	float t, u;
}
LineIntersectionData;

/*
    This will create a new Line intersection data struct.
    It will handle and generate the new information.
*/
LineIntersectionData getLineIntersectionData(Line* new_a, Line* new_b);

/*
    This will update the contents based on any changes that
    may have occurred.
*/
void updateLineIntersectionData(LineIntersectionData* data_to_update);

Line* splitLine(Line split_line, Line victim);

#endif