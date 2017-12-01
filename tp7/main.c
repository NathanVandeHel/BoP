#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int * findN(int *, int, int);

int main()
{
    //cube();
    //arrayAndFunction();
    //vertically();
    //trimmer();
    atLeastTwice();


    return 0;
}

void cube()
{
    double length = 2.7;
    double volume, surfaceArea;

    cubeCalc(length, &volume, &surfaceArea);

    printf("length = %lf - volume = %lf - surface area = %lf \n", length, volume, surfaceArea);
}

void cubeCalc(double l, double * vol, double * surf)
{
    *vol = l*l*l;
    *surf = l*l*6;
}

void arrayAndFunction()
{
    const int aLength = 15;
    int a[15] = {1, 5, -5, -9, 8, 12, -8, 63, -7, 8, -8, -5, 2, 3, 9};
    int n;
    int * adress;

    scanf("%d", &n);

    adress = findN(a, aLength, n);

    printArray(a, aLength);

    printf(adress != NULL ? "First index of %d : %d" : "Index no found", n, adress - a);
}

int * findN(int * a, int aL, int n)
{
    /*int i;

    for(i=0; i < aL; ++i)
    {
        if(n == a[i])
        {
            printf("i = %d \n", i);
            return &a[i];
        }
    }

    return NULL;*/

    int * p;

    for(p=a; p != a+aL; ++p)
    {
        if(n == *p)
        {
            return p;
        }
    }

    return NULL;
}

void printArray(int * a, int aL)
{
    int i;
    for(i=0; i<aL; ++i)
    {
        printf("Index : %d - Value : %d \n", i, a[i]);
    }

}

void vertically()
{
    char word[10] = {"Hello"};

    printfVertically(word);
}

void printfVertically(char * s)
{
    int i;

    for(i = 0; s[i] != '\0'; ++i)
    {
        printf("%c \n", s[i]);
    }

}

void trimmer()
{
    char sourceArray[50] = {"  salot fez  "};
    char destinationArray[50];

    trim(destinationArray, sourceArray);

    printf(">%s< \n", destinationArray);
}

void trim(char * d, char * s)
{
    int i = 0, j = 0;

    while(s[i++] == ' ' && s[i] != '\0'); --i;
    printf("1>%s< \n", d);
    while((d[j++] = s[i++]) != '\0'); --j;
    printf("2>%s< \n", d);
    while(d[--j] == ' ' && j >= 0) d[j] = '\0';
    printf("3>%s< \n", d);
}

void atLeastTwice(char * s)
{

}
