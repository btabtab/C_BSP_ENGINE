#include "ErrorHandling.h"

void emergencyKill()
{
	printSystemLog("Performing emergency kill.");
	exit(0);
}

/*
	This will count if the program
	has run into enough errors and
	warnings so that it knows to kill
	the program.
*/
void countedKill()
{
	//Counts issues.
	static int issue_count = 0;
	//Increments issue count.
	issue_count++;
	/*
		Checks if the issue count is at max,
		if so then kill the program
	*/
	if(issue_count == ISSUE_COUNT_MAXIMUM)
	{
		printSystemLog("Issue count has reached maximum value.");
		emergencyKill();
	}
}

bool isPointerNull(void* pointer)
{
	if(pointer)
	{
		return false;
	}
	printSystemLog("Pointer ? is null");
	return true;
}

/*
	This function will handle if the pointer
	is NULL or not, it will kill the program
	and report that there is a fault.
*/
void checkForProgramKill(void* pointer_to_check, char* guilty_function_name)
{
	char guilty_function_message[60] = "";
	sprintf(guilty_function_message, "[ Guilty function == \"%s\" ]", guilty_function_name);
	printSystemLog(guilty_function_message);
	if(isPointerNull(pointer_to_check))
	{
		emergencyKill();
	}
}

void correctUnallocatedPointer(void** pointer_to_fix, size_t size_to_allocate)
{
	*pointer_to_fix = malloc(size_to_allocate);
}