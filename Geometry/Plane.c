#include "Plane.h"

Plane newPlane(Point a, Point b, int type, int style_id)
{
	Plane ret;
	ret.geometry = newLine(a, b);
	ret.type = type;
	ret.style_ID = style_id;

	static int new_ID_tracker = 0;
	ret.ID = new_ID_tracker;
	new_ID_tracker++;

	return ret;
}

Plane splitLineFromPlane(Line future_plane, Line split_line)
{
    swapLinePointsForConsistency(&future_plane);
    LineIntersectionData intersection_data = getLineIntersectionData(&split_line, &future_plane);
	return newPlane(
			intersection_data.intersection_point,
			future_plane.b,
			intersection_data.do_lines_intersect,
			0x00
			);
}