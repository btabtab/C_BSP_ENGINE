#ifndef POINT
#define POINT
/*
    This "Point" struct will hold and contain
    the data for a point in space.
*/
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/*
    Stores a point in 2D space.
*/
typedef struct Point
{
    float x, y;
}
Point;
/*
    Stores the dimensions for resolution
    or volumetric reasons.
*/
typedef Point Dimensions;

/*
    Creates a new point with:
        "x" = "new_x",
        "y" = "new_y",
*/
Point newPoint(float new_x, float new_y);

/*
    Creates new Dimensions with:
        "x" = "new_x",
        "y" = "new_y",
    
    A stolen redefine of "newPoint"
*/
#define newDimensions newPoint

/*
    Allocates the memory for a new point
    and sets it to the value given by
    "point".
*/
Point* allocatePoint(Point point);

/*
    Deallocates a point.
    Not needed but is good
    for readability reasons.
*/
void deallocatePoint(Point* point);

/*
    Swaps 2 points around, good for any
    sorting or other such shenanigans.
*/
void swapPoints(Point* a, Point* b);

//Adds two points together.
Point addPoints(Point a, Point b);

//Subtracts point "b" from "a".
Point subPoints(Point b, Point a);

/*
    Rotates "target" around "center" by the
    specified degrees.
*/
Point getRotatedPoint(Point target, Point center, float degrees);

Point dividePoint(Point a, float divide_amount);
Point multiplyPoint(Point a, float multiply_amount);

bool isAPointLeftOfBPoint(Point a, Point b);
bool isAPointRightOfBPoint(Point a, Point b);
bool isAPointAboveBPoint(Point a, Point b);
bool isAPointBelowBPoint(Point a, Point b);

void swapPointsForConsistensy(Point* a, Point* b);

bool arePointsEqual(Point a, Point b);

void printPointDebug(Point a);

#endif