#include <iostream>
using namespace std;

void CalculateCircle(double r, double *s);// Function for pointer passing
void CalculateCircle(double r, double &s);// Function for reference passing

int main()
{
    double radius = 10.;
    //double surface = 0.;
    double *surface;
    *surface = 0.;

    //CalculateCircle(radius, surface);
    CalculateCircle(radius, *surface);

    printf("s = %lf\n", *surface);

    return 0;
}

void CalculateCircle(double r, double *s)
{// Pointer passing
    double Pi = 3.14;
    *s = Pi*(r*r);
    printf("(P)Area of circle with r = %3.2lf: %3.2lf\n", r, *s);
    return;
}

void CalculateCircle(double r, double &s)
{// Reference passing
    double Pi = 3.14;
    s = Pi*(r*r);
    printf("(R)Area of circle with r = %3.2lf: %3.2lf\n", r, s);
    return;
}