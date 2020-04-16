#include <iostream>
#include "EventGenerator.h"

EventGenerator::EventGenerator(int lower_limit, int upper_limit, int number_of_elements)
{
    min = lower_limit;
    max = upper_limit;
    nelements = number_of_elements;
    range = max - min;

    if(nelements <= MAX_NELEMENTS)
    {
        mt.seed(rnd()); // Make MT random generator
    }
    else
    {
        std::cout << "WARNING! Over flowing nelements has been detected!" << std::endl;
        std::cout << "Maximum nelemnts = " << MAX_NELEMENTS << std::endl;
    }
}

EventGenerator::~EventGenerator()
{}

void EventGenerator::GenerateElements(int container[])
{
    tstart = clock();
    for(int i=0; i<nelements; i++)
    {
        int r = (mt() % (range+1)) + min;
        container[i] = r;
    }
    tfinish = clock();
    return;
}

void EventGenerator::GetElements(int *container)
{// No longer used
    for(int i=0; i<nelements; i++)
    {
        container[i] = elements[i];
    }
    return;
}

double EventGenerator::GetTime()
{
    tleng = (double)(tfinish - tstart);
    return tleng;
}

void EventGenerator::SetNelements(int number_of_elements)
{
    nelements = number_of_elements;
    return;
}

void EventGenerator::SetRange(int lower_limit, int upper_limit)
{
    min = lower_limit;
    max = upper_limit;
    range = max - min;
    return;
}

void EventGenerator::ShowElements()
{
    for(int i=0; i<nelements; i++)
    {
        std::cout << elements[i] << std::endl;
    }
    return;
}