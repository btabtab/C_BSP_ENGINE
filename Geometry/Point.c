#include "Point.h"

Point newPoint(float new_x, float new_y)
{
	return (Point){new_x, new_y};
}

Point* allocatePoint(Point point)
{
	Point* ret;
	*ret = point;
	return ret;
}

void swapPoints(Point* a, Point* b)
{
	Point swap = *a;
	(*a) = *b;
	(*b) = swap;
}

Point addPoints(Point a, Point b)
{
	return newPoint(a.x + b.x, a.y + b.y);
}

Point subPoints(Point b, Point a)
{
	return newPoint(a.x - b.x, a.y - b.y);
}

#define PI 3.14159265359

Point getRotatedPoint(Point target, Point center, float degrees)
{
    degrees = degrees * (PI / 180);
	Point local = subPoints(center, target);
    Point ret = { 0 };
	ret.x = (local.x * cos(degrees) - local.y * sin(degrees));
	ret.y = (local.y * cos(degrees) + local.x * sin(degrees));
	
	return addPoints(ret, center);
}

Point dividePoint(Point a, float divide_amount)
{
    return newPoint(
                    a.x / divide_amount,
                    a.y / divide_amount
                    );
}
Point multiplyPoint(Point a, float multiply_amount)
{
    return newPoint(
                    a.x * multiply_amount,
                    a.y * multiply_amount
                    );
}

bool isAPointLeftOfBPoint(Point a, Point b)
{
    return (a.x < b.x);
}
bool isAPointRightOfBPoint(Point a, Point b)
{
    return (b.x < a.x);
}
bool isAPointAboveBPoint(Point a, Point b)
{
    return (b.y < a.y);
}
bool isAPointBelowBPoint(Point a, Point b)
{
    return (a.y < b.y);
}

void swapPointsForConsistensy(Point* a, Point* b)
{
	if(isAPointAboveBPoint(*a, *b))
	{
        float swap = a->y;
        a->y = b->y;
        b->y = swap;
	}
    
	if(isAPointRightOfBPoint(*a, *b))
	{
        float swap = a->x;
        a->x = b->x;
        b->x = swap;
	}
}

bool arePointsEqual(Point a, Point b)
{
    return (
            (int)a.x == (int)b.x
            &&
            (int)a.y == (int)b.y
            );
}

void printPointDebug(Point a)
{
	printf("point: %f, %f\n", a.x, a.y);
}