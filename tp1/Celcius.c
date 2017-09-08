#include <stdio.h>
#include <stdlib.h>

int celcius()
{
    double CelciusDeg, FahrenheitDeg;

    printf("Temperature in Celcius ?");
    scanf("%lf", &CelciusDeg);

    FahrenheitDeg = 1.8*CelciusDeg + 32;

    printf("Corresponding temperature in Fahrenheit : %f", FahrenheitDeg);

    return 0;
}
