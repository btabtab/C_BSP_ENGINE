#include "Brush.h"

Brush newBrush(Point a, Point b, Point c, Point d)
{
	return (Brush){a, b, c, d};
}

//This splits a brush into a front and back side.
Brush* splitBrush(Brush brush, Line slice_line)
{
	static Brush ret[2];
	Line brush_lines[] =
	{
		newLine(brush.a, brush.b),
		newLine(brush.b, brush.c),
		newLine(brush.c, brush.d),
		newLine(brush.d, brush.a)
	};
	LineIntersectionData line_intersections[2] = { 0 };
	int total_intersections = 0;
	for(int i = 0; i != 4; i++)
	{
		swapLinePointsForConsistency(&brush_lines[i]);

		line_intersections[total_intersections] =
			getLineIntersectionData(&brush_lines[i], &slice_line);
		
		total_intersections += line_intersections[total_intersections].do_lines_intersect;
		if(total_intersections == 2)
		{
			break;
		}
	}
	ret[0] = newBrush(
				brush_lines[0].a,
				brush_lines[1].a,
				brush_lines[2].a,
				brush_lines[3].a
					);
	return ret;
}