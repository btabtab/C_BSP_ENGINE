#include "Sector.h"

Sector newSector(Point a, Point b, Point c, Point d)
{
	Sector ret;

	//Assigns the sector it's points.
	ret.a = a;
	ret.b = b;
	ret.c = c;
	ret.d = d;

	//Grants the sector a new ID.
	static int new_sector_ID = 0;
	ret.ID = new_sector_ID;
	new_sector_ID++;

	return ret;
}
Sector splitSector(Sector sector, Line split_line, int direction)
{
	printSystemLog("splitSector(S, L, d) has not been written out yet");
	return sector;
}
Line getSectorLines(Sector sector, int line_index)
{
	if(line_index < 0 || 3 < line_index)
	{
		printf("Index [ %d ] does not exist, evading segfault...\n", line_index);
		exit(0);
	}

	//Generate the lines.
	Line lines[4] =
	{
		newLine(sector.a, sector.b),
		newLine(sector.b, sector.c),
		newLine(sector.c, sector.d),
		newLine(sector.d, sector.a)
	};
	//Return the lines.
	return lines[line_index];
}