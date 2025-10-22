#include <sys/time.h>

// timeval is imported. You do NOT have to create it
double elapsed_time(struct timeval* start_time, struct timeval* end_time){
    //TODO: return the difference between end_time and start_time.
    // Avoid any floating point bs
    long seconds = end_time->tv_sec - start_time->tv_sec;
    long microseconds = end_time->tv_usec - start_time->tv_usec;

    // microseconds could be negative
    if(microseconds < 0){
        seconds -= 1;  // Seconds will never be negative, use your head
        microseconds += 1000000;
    }


    return seconds + microseconds / 1000000.0;
}