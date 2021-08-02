#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double x3,y3,z3,x2,y2,z2;

int main()
{
        double pi = 0.000;
        pi = acos(-1);

        scanf("%lf %lf %lf",&x2,&y2,&z2);
        scanf("%lf %lf %lf",&x3,&y3,&z3);
        double r = 0.000; double v = 0.000;double x = 0.000;
        r = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) + (z2-z3)*(z2-z3));
        x = 4.000/3.000;
        v = x*pi*r*r*r;

        printf("%.3lf %.3lf",r,v);

}
