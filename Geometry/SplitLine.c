#include "SplitLine.h"

SplitLine newSplitLine(Line base_line, Line split_line)
{
	SplitLine ret;

	LineIntersectionData intersection_data = getLineIntersectionData(&split_line, &base_line);

	ret.left.a = intersection_data.intersection_point;
	ret.left.b = base_line.b;
	
	ret.right.a = base_line.a;
	ret.right.b = intersection_data.intersection_point;

    ret.was_line_split = intersection_data.do_lines_intersect;
    
	return ret;
}
