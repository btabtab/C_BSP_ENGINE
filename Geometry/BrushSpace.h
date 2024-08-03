#ifndef BRUSH_SPACE
#define BRUSH_SPACE

#include <stdlib.h>

#include "Brush.h"

/*
	A 'BrushSpace' is a space in which numerous
	'brushes' are stored.

	This will contain all of the geometry of the
	world that will be processed down into a BSP
	tree.
*/
typedef struct BrushSpace
{
	Brush* brushes;
	int brush_count;
}
BrushSpace;

BrushSpace newBrushSpace(int amount_of_brushes);

void assignBrushToBrushSpace(BrushSpace* brush_space, int index, Brush brush_data);

#endif