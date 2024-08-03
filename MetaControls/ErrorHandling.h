#ifndef ERROR_HANLDING
#define ERROR_HANLDING

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "SystemLogging.h"

#define ISSUE_COUNT_MAXIMUM 32

void emergencyKill();
void countedKill();
bool isPointerNull(void* pointer);
void checkForProgramKill(void* pointer_to_check, char* guilty_function_name);

#endif