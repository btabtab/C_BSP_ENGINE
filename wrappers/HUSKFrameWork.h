#ifndef HUSK_FRAMEWORK
#define HUSK_FRAMEWORK

#include "SubWindow.h"
#include "Drawing.h"

#include "../Geometry/Geometry.h"

#include "FrameExport.h"

/*
	I have chosen the name 'HUSK'
	as this is merely going to be
	a barebones carcass for building
	the programs logic within.
*/
typedef struct HUSK
{
	SubWindow sub_windows[5];
	BrushSpace brush_space;

	bool keep_running;
}
HUSK;

HUSK initialiseHUSK()
{
	HUSK ret;

	ret.keep_running = true;

	//Allocate and create brushes.
	ret.brush_space = newBrushSpace(3);
	Brush enclosing_brush = newBrush(
								newPoint(30, 30),
								newPoint(270, 30),
								newPoint(270, 270),
								newPoint(30, 270)
									);
	assignBrushToBrushSpace(&ret.brush_space, 0, enclosing_brush);
	Brush test_brush = newBrush(
							newPoint(300 * 0.4, 300 * 0.3),
							newPoint(300 * 0.7, 300 * 0.4),
							newPoint(300 * 0.6, 300 * 0.7),
							newPoint(300 * 0.3, 300 * 0.6)
								);
	assignBrushToBrushSpace(&ret.brush_space, 1, test_brush);
	
	//Create the sub-windows.
	ret.sub_windows[0] = newSubWindow("Overworld View", newPoint(0, 0), newDimensions(300, 300));
	ret.sub_windows[1] = newSubWindow("Diagnostics", newPoint(300, 0), newDimensions(300, 300));
	ret.sub_windows[2] = newSubWindow("First Person View", newPoint(0, 300), newDimensions(300, 300));
	ret.sub_windows[3] = newSubWindow("CompileView View", newPoint(300, 300), newDimensions(300, 300));

	ret.sub_windows[4] = newSubWindow("Tree View", newPoint(600, 0), newDimensions(300, 600));

	return ret;
}

void drawHUSKBirdsEyeView(HUSK husk)
{
	
	Line slice_line = (Line){(Point){75, 0}, (Point){225, 300}};

	drawToSubWindow(&husk.sub_windows[0]);
	{
	}
	stopDrawingToSubWindow(&husk.sub_windows[0]);
}
void drawDiagnostics(HUSK husk)
{
}
void drawHUSKCompileView(HUSK husk)
{
	drawToSubWindow(&husk.sub_windows[1]);
	clearScreen(0x00);
	//Take test brush.
	Brush enclosing_brush = husk.brush_space.brushes[0];

	Brush test_brush = husk.brush_space.brushes[1];
	//Create split lines.
	Line slice_lines[] =
	{
		getLineExtrapolated(newLine(test_brush.a, test_brush.b), 3),
		getLineExtrapolated(newLine(test_brush.b, test_brush.c), 3),
		getLineExtrapolated(newLine(test_brush.c, test_brush.d), 3),
		getLineExtrapolated(newLine(test_brush.d, test_brush.a), 3)
	};
	Line other_brush_lines[] =
	{
		newLine(enclosing_brush.a, enclosing_brush.b),
		newLine(enclosing_brush.b, enclosing_brush.c),
		newLine(enclosing_brush.c, enclosing_brush.d),
		newLine(enclosing_brush.d, enclosing_brush.a)
	};
	//Stores intersections between the brushes.
	LineIntersectionData intersections[4 * 4];
	//Counts the amount of intersections
	int succsesful_intersection_counter = 0;
	//This will process and cross reference the different lines.
	for(int slice_index = 0; slice_index != 4; slice_index++)
	{
		for(int brush_index = 0; brush_index != 4; brush_index++)
		{
			intersections[succsesful_intersection_counter] =
				getLineIntersectionData(&slice_lines[slice_index], &other_brush_lines[brush_index]);
			
			succsesful_intersection_counter += intersections[succsesful_intersection_counter].do_lines_intersect;
		}
	}

	for(int i = 0; i != succsesful_intersection_counter; i++)
	{
		drawCircle(intersections[i].intersection_point, 6.f, INTRED);
	}

	for(int i = 0; i != 4; i++)
	{
		drawLine(slice_lines[i], INTPORPOL);
	}
	drawBrush(&enclosing_brush, ~0);
	drawBrush(&test_brush, INTGREEN);
	//Split against enclosing brush.

	stopDrawingToSubWindow(&husk.sub_windows[1]);
}

void drawHUSK(HUSK husk)
{
	drawHUSKBirdsEyeView(husk);
	drawHUSKCompileView(husk);
  	for(int i = 0; i != sizeof(husk.sub_windows) / sizeof(*husk.sub_windows); i++)
	{
		drawSubWindow(&husk.sub_windows[i]);
	}
}

void huskLoop(HUSK husk)
{
	while(husk.keep_running)
	{
		beginDrawing();
		drawHUSK(husk);
		endDrawing();
	}
}

#endif