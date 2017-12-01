#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //fibonacci();
    //arrayFandB();
    //quickPower();
    //numeralSystem();
    prettyPrintNumbers();

    return 0;
}

void fibonacci()
{
    int n;
    n = fib(10);
    printf("result : %d", n);
}

int fib(int n)
{
    printf("%d \n", n);
    if(n < 2) return 1;
    return (fib(n-1) + fib(n-2));
}

void arrayFandB()
{
    int a1[5] = {1, 2, 3, 4, 5};
    int a2[10] = {1,2,3,4,5,6,7,8,9,10};

    printForward(a1, 5);
    printf("----- \n");
    printBackward(a1, 5);
    printf("##### \n");
    printForward(a2, 10);
    printf("----- \n");
    printBackward(a2, 10);
}

void printForward(int* a, int size)
{
    if(size > 0)
    {
        printf("%d \n", *a);
        printForward(a+1, size-1);
    }
}

void printBackward(int* a, int size)
{
    if(size > 0)
    {
        printf("%d \n", *(a + size - 1));
        printBackward(a, size-1);
    }
}

void quickPower()
{
    int i;
    for(i=1; i<=16; ++i) printf("2^%d = %d \n", i, power(2, i));
}

int power(int a, int n)
{
    if(n == 1) return a;

    if(n%2 == 0) return power(a*a, n/2);
    if(n%2 != 0) return a*power(a, n-1);
}

void numeralSystem()
{
    int a = 64, base = 10 ;

    printNumSyst(a, base);
}

void printNumSyst(int n, int b)
{
    if(!n) return;
    printNumSyst(n/b, b);
    printf("%d", n%b);
    return;
}

void prettyPrintNumbers()
{
    printPretty(1580);
}

void printPretty(int n)
{
    if(!(n/1000))
    {
        printf("%d ", n);
        return;
    }
    printPretty(n/1000);
    printf("%03d ", n%1000);
    return;
}
