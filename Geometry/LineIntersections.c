#include "LineIntersections.h"

/*
	This will create a new Line intersection data struct.
	It will handle and generate the new information.
*/
LineIntersectionData getLineIntersectionData(Line* new_a, Line* new_b)
{
	LineIntersectionData data;
	
	Point A = new_a->a;
	Point B = new_a->b;
	Point C = new_b->a;
	Point D = new_b->b;

	float tTop = (D.x - C.x) * (A.y - C.y) - (D.y - C.y) * (A.x - C.x);
	float uTop = (C.y - A.y) * (A.x - B.x) - (C.x - A.x) * (A.y - B.y);
	float bottom = (D.y - C.y) * (B.x - A.x) - (D.x - C.x) * (B.y - A.y);

	float eps = 0.001;
	if (fabs(bottom) > eps)
	{
		float t = tTop / bottom;
		float u = uTop / bottom;
		if (t >= 0 && t <= 1 && u >= 0 && u <= 1)
		{
			data.do_lines_intersect = true;
			
            data.intersection_point = getLineExtrapolation(*new_a, t);
		}
	}

	return data;
}