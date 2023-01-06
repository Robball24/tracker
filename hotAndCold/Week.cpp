#include "Week.h"
#include <ctime>
bool Week::newWeek() {
    time_t current_time;
    time(&current_time);
    int newWeek = current_time / week;
    if (newWeek % 7 == 0) {
        return true;
    }
    else return false;
}


