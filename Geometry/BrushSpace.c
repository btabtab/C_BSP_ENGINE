#include "BrushSpace.h"

BrushSpace newBrushSpace(int amount_of_brushes)
{
    BrushSpace ret;
    ret.brush_count = amount_of_brushes;
    //Allocates space for all of the brushes.
    ret.brushes = calloc(amount_of_brushes, sizeof(Brush));
    return ret;
}

void assignBrushToBrushSpace(BrushSpace* brush_space, int index, Brush brush_data)
{
    brush_space->brushes[index] = brush_data;
}