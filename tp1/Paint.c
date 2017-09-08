#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265

int paint()
{
    double d, h, a, n;
    printf("Paint the container \n");
    printf("Height ? ");
    scanf("%lf", &h);
    printf("Diameter ? ");
    scanf("%lf", &d);
    a = 2*PI*pow(d/2,2) + PI*d*h;
    n = a/2;
    printf("%.1f can(s) of paint needed", n);

    return 0;
}
