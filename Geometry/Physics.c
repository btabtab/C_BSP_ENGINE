#include "Physics.h"

PhysObj newPhysobj(Point position, Point direction, float weight)
{
    PhysObj ret = {position, direction, weight};
    return ret;
}

void updatePhysObj(PhysObj* physobj)
{
    physobj->position = addPoints(physobj->position, physobj->direction);
}