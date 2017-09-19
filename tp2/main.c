#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //errorsInTheProgramm();
    //lengthOfALine();
    //parabolicEquation();
    //loopsPrintingNumbers();
    //loopsPrintingNumbers2();
    //lineOfAGivenLength();
    //squareOfAGivenLength();
    squareProblem();
    return 0;
}

int errorsInTheProgramm()
{
    int x;

    printf("Dear user!");
    printf("Enter a number, I will print its square!");
    scanf("%d", &x);
    x = x*x;
    printf("x square is : %d", x);

    return 0;
}

int lengthOfALine()
{
    double xA, yA, xB, yB, length;

    printf("x coordinate of point A ? ");
    scanf("%lf", &xA);
    printf("\ny coordinate of point A ? ");
    scanf("%lf", &yA);
    printf("\nx coordinate of point B ? ");
    scanf("%lf", &xB);
    printf("\ny coordinate of point B ? ");
    scanf("%lf", &yB);

    length = sqrt(pow(xA-xB,2) + pow(yA-yB,2));

    printf("\nLength of the line : %lf", length);

    return 0;
}

int parabolicEquation()
{
    double a, b, c, x1, x2, delta;

    printf("Enter the parameters of the parabolic equation in the order ax2+bx+c=0: \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if(a == 0)
    {
        if(b ==0)
        {
            printf("\nNo solutions in R");
        }

        else
        {
            x1 = -c/b;
            printf("\n1st order equation, x = %lf", x1);
        }

    }

    else
    {
        delta = pow(b,2)-4*a*c;

        if(delta < 0)
        {
            printf("\nNo solution in R");
        }

        else if(delta == 0)
        {
            x1 = -b/(2*a);
            printf("\nOnly one solution : %lf", x1);
        }
        else
        {
            x1 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
            x2 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
            printf("\nx1 = %lf    x2 = %lf", x1, x2);
        }

    }

    return 0;
}

int loopsPrintingNumbers()
{
    int n = 1;
    while(n <= 20)
    {
        printf("%d \n", n++);
        //++n;
    }
}

int loopsPrintingNumbers2()
{
    int a, b, from, to;

    printf("Enter the two bounds you want \n");
    scanf("%d %d", &a, &b);

    if(a > b)
    {
        from = b;
        to = a;
    }
    else
    {
        from = a;
        to = b;
    }

    for(from; from <= to; ++from)
    {
        printf("%d \n", from);
    }

    return 0;
}

int lineOfAGivenLength()
{
    int n, i;

    printf("Length of the line ? ");
    scanf("%d", &n);

    printf("\n+");
    for(i = 1; i <= n; ++i)
    {
        printf("-");
    }
    printf("+");
}

int squareOfAGivenLength()
{
    int m, n, i, j, k, l;

    printf("Size of the square ? \n");
    scanf("%d %d", &m, &n);

    printf("\n+");
    for(i = 1; i <= n; ++i)
    {
        printf("-");
    }
    printf("+");

    for(j = 1; j <= m; ++j)
    {
        printf("\n|");
        for(k = 1; k <= n; ++k)
        {
            printf(".");
        }
        printf("|");
    }

    printf("\n+");
    for(l = 1; l <= n; ++l)
    {
        printf("-");
    }
    printf("+");
}

int squareProblem()
{
    int n, i, s;

    printf("Print the first ? square numbers ");
    scanf("%d", &n);
    for(i=1; i <= n; ++i)
    {
        s = i^2;
        printf("\n%d", s);
    }
}
