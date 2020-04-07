#include <stdio.h>
#include <string.h>
#include <time.h>

#define PRINT_PROCESS printf("Hello, world!");// Define macro

int main(int argc, char *argv[])
{
    int ntrials = 1000000;// Number of trials
    int nevents = 100;// Number of events per trial
    double event_time = 0;// Process time of nevents
    clock_t event_start = 0;
    clock_t event_end = 0;

    FILE *result = fopen("result_macro.dat", "w");
    //printf("CLOCKS_PER_SEC = %ld", CLOCKS_PER_SEC);

    for(int i=0; i<ntrials; i++)
    {
        event_start = clock();
        for(int j=0; j<nevents; j++)
        {
            PRINT_PROCESS;
        }
        event_end = clock();
        event_time = (double)((double)(event_end - event_start)/(nevents));// Normalize process time by an event
        fprintf(result, "%lf\n", event_time);// Save result in us(Unix case)
    }

    fclose(result);
    return 0;
}