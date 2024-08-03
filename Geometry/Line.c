#include "Line.h"

Line newLine(Point a, Point b)
{
	return (Line){a, b};
}
Line* allocateLine(Line line_data)
{
	Line* ret;
	ret = malloc(sizeof(Line));
	*ret = line_data;
	return ret;
}
void freeLine(Line* line_pointer)
{
	free(line_pointer);
}
/*
	This gets the length of the line
	using pythag.
*/
float getLineLength(Line line)
{
	//find the lengths of the triangle sides.
	float length_a = line.b.x - line.a.x;
	float length_b = line.b.y - line.a.y;

	//Written like this just to make it neater. :)
	float pre_square_rooted_value = (length_a * length_a) + (length_b * length_b);
	return sqrt(pre_square_rooted_value);
}

float interpolate(float a, float b, float t)
{
	return a + (b - a) * t;
}

Point getLineExtrapolation(Line line, float degree_of_extrapolation)
{
	Point ret =
	(Point)
	{
		interpolate(line.a.x, line.b.x, degree_of_extrapolation),
		interpolate(line.a.y, line.b.y, degree_of_extrapolation)
	};
	return ret;
}

Line getLineExtrapolated(Line line, float degrees_of_extrapolation)
{
	Line inverse_line = line;
	swapPoints(&line.a, &line.b);
	Point inverse_extrapolation = getLineExtrapolation(line, (-degrees_of_extrapolation));
	return newLine(
					getLineExtrapolation(line, degrees_of_extrapolation),
					inverse_extrapolation
					);
}

void swapLinePointsForConsistency(Line* line)
{
	swapPointsForConsistensy(&line->a, &line->b);
}

Point getMidPoint(Line line)
{
	return dividePoint(addPoints(line.a, line.b), 2);
}

Point getLeftOfLine(Line line)
{
	Point mid_point = getMidPoint(line);

	return getMidPoint(
					newLine(
						mid_point,
						getRotatedPoint(line.a, getMidPoint(line), -90)
							)
					);
}

bool isPointLeftOfLine(Point point, Line line)
{
	getLeftOfLine(line);
	return false;
}