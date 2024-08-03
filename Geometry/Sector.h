#ifndef SECTOR
#define SECTOR
/*
    Sectors will store and track areas of space.
    This will allow for the BSP renderer to hold
    and track areas of space within the "world".

    The difference between this and a "Brush" is
    that a "Brush" is a physical object and a
    "Sector" is a space.
*/

#include "../MetaControls/MetaControls.h"

#include "Point.h"
#include "Line.h"

typedef struct Sector
{
    int ID;
    /*
        The points that the sector will
        take up.
    */
    Point a, b, c, d;
}
Sector;

Sector newSector(Point a, Point b, Point c, Point d);
Sector splitSector(Sector sector, Line split_line, int direction);

#endif