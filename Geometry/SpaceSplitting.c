#include "SpaceSplitting.h"

Space newSpace(Point a, Point b, Point c, Point d)
{
	Space ret;

	ret.planes[0].geometry.a = a;
	ret.planes[0].geometry.b = b;
	
	ret.planes[1].geometry.a = b;
	ret.planes[1].geometry.b = c;
	
	ret.planes[2].geometry.a = c;
	ret.planes[2].geometry.b = d;
	
	ret.planes[3].geometry.a = d;
	ret.planes[3].geometry.b = a;

	return ret;
}