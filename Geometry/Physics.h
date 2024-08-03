#ifndef PHYSICS
#define PHYSICS

#include "Geometry.h"

typedef struct PhysObj
{
    Point position;
    Point direction;
    float weight;
}
PhysObj;

PhysObj newPhysobj(Point position, Point direction, float weight);
void updatePhysObj(PhysObj* physobj);

#endif