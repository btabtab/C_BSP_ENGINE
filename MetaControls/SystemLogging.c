#include "SystemLogging.h"

int log_index = 0;

void printSystemLog(char* log_message)
{
    printf("%d :: > %s", log_index, log_message);
    printf("\n");
    log_index++;
}