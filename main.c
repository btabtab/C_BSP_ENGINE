#include "wrappers/HUSKFrameWork.h"

int main(int argc, char const *argv[])
{
    printSystemLog("Starting Program...");

    HUSK husk = initialiseHUSK();
    huskLoop(husk);

    printSystemLog("Program closing \"safely\".");
    return 0;
}