#include <raylib.h>

#include "SubWindow.h"
#include "../wrappers/Drawing.h"
#include "../MetaControls/MetaControls.h"

SubWindow newSubWindow(char* name, Point position, Dimensions dimensions)
{
	static int next_ID = 0;

	SubWindow ret;
	ret.ID = next_ID;
	next_ID++;

	char message[100] = "";
	sprintf(message, "Creating new subwindow - %s - [ %d ] -\n", ret.name, ret.ID);
	printSystemLog(message);
	ret.render_texture = malloc(sizeof(RenderTexture));

	ret.position = position;
	ret.resolution = dimensions;
	(*(RenderTexture*)ret.render_texture) = LoadRenderTexture(ret.resolution.x, ret.resolution.y);

	ret.is_paused = false;
	strcpy(ret.name, name);
	printf("Finished creating new subwindow - [ %d ] -\n", ret.ID);
	return ret;
}

void pauseSubWindow(SubWindow* sub_window)
{
	sub_window->is_paused = true;
}

void skipNextUpdate(SubWindow* sub_window)
{
	sub_window->skip_next_update = true;
}

SubWindow drawSubWindow(SubWindow* sub_window)
{
	//Draw blank rectangle for positioning.
	DrawRectangle(sub_window->position.x, sub_window->position.y, sub_window->resolution.x, sub_window->resolution.y + 1, WHITE);
	
	//Draw the actual rendertexture.
	RenderTexture render_texture = *((RenderTexture*)sub_window->render_texture);
	DrawTextureRec(	render_texture.texture,
					(Rectangle) { sub_window->position.x + 1, sub_window->position.y + 1, (float)render_texture.texture.width - 2, (float)-(render_texture.texture.height - 2) },
					(Vector2) { sub_window->position.x + 1, sub_window->position.y + 1 },
					WHITE);
	//Remove this line.
	return (*sub_window);
}

void closeSubWindow(SubWindow* sub_window)
{
	UnloadRenderTexture(*(RenderTexture*)sub_window->render_texture);
}

void drawToSubWindow(SubWindow* sub_window)
{
	BeginTextureMode(*(RenderTexture*)sub_window->render_texture);
	ClearBackground(BLANK);
}

void stopDrawingToSubWindow(SubWindow* sub_window)
{
	drawText(sub_window->name, newPoint(5, 5), 5, ~0);
	EndTextureMode();
}

void scaleSubWindow(SubWindow* sub_window, float scale)
{
	printf("\n\t\t: -- -- Experimental, not yet tested.\n");
	UnloadRenderTexture(*(RenderTexture*)sub_window->render_texture);
	sub_window->resolution.x *= scale;
	sub_window->resolution.y *= scale;

	(*(RenderTexture*)sub_window->render_texture) = LoadRenderTexture(sub_window->resolution.x, sub_window->resolution.y);
}