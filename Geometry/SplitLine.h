#ifndef SPLIT_LINE
#define SPLIT_LINE

#include "Line.h"
#include "LineIntersections.h"

typedef struct SplitLine
{
    bool was_line_split;
    Line left, right;
}
SplitLine;

SplitLine newSplitLine(Line base_line, Line split_line);

#endif