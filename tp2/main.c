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
    //squareProblem();
    //squareProblem2();
    //spheres();
    //divisors();
    //allNumbers();
    //power();
    //NthElement();
    cubicRoot();

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

    return 0;
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

    return 0;
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

    return 0;
}

int squareProblem()
{
    int n, i, s;

    printf("Print the first ? square numbers ");
    scanf("%d", &n);
    for(i=1; i <= n; ++i)
    {
        s = i*i;
        printf("\n%d", s);
    }

    return 0;
}

int squareProblem2 ()
{
    int n, i, s;
    s = 0;

    printf("Print all square numbers inferior to ?");
    scanf("%d", &n);

    for(i=1; s <= n; ++i)
    {
        printf("\n%d", s);
        s=i*i;
    }

    return 0;
}

int spheres ()
{
    double r, v, r_cm, v_m3;
    r = 100;
    v = (4/3)*3.14*pow(r, 3);

    while (v <= 1000000000)
    {
        r_cm = r/10;
        v_m3 = v/1000000000;
        printf("\nr = %g cm, v = %g m3", r_cm, v_m3);
        v = (4/3)*3.14*pow(r, 3);
        r+=100;
    }

    return 0;
}

int divisors ()
{
    int n, i;

    printf("Enter an interger : ");
    scanf("%d", &n);

    for(i=1; i<=n; ++i)
    {
        if(!(n%i))
           {
               printf("\n%d", i);
           }
    }

    return 0;
}

int allNumbers ()
{
    int i, j, k, l;

    for(i=3; i<=5; ++i)for(j=3; j<=5; ++j)for(k=3; k<=5; ++k)for(l=3; l<=5; ++l)printf("\n%d%d%d%d", i, j, k, l);

    return 0;
}

int power ()
{
    double a, r;
    int n;

    printf("a^n \nValue of a (real) ? ");
    scanf("%lf", &a);
    printf("\nValue of r (integer) ? ");
    scanf("%d", &n);

    r = pow(a, n);
    printf("\n%g^%d = %lf", a, n, r);

    return 0;
}

int NthElement ()
{
    int n, c, i, x;
    x = 2;

    printf("Series : x0=2, xi=2*x(i-1)+5 \n");
    printf("Nth element ? ");
    scanf("%d", &n);
    printf("Do you want : \n    1. print the Nth element only \n    2. print the first Nth elements \n");
    scanf("%d", &c);


    for (i=0; i<=n; ++i)
    {
        if(c == 2) printf("\nx%d = %d", i, x);
        if (i < n) x=2*x+5;
    }
    if(c == 1) printf("\nx%d = %d", n, x);

    return 0;
}

int cubicRoot ()
{
    double n, r;
    int i, c;

    printf("Calculate the cubic root of : ");
    scanf("%lf", &n);
    printf("\nGive an approximation of this cubic root : ");
    scanf("%lf", &r);
    printf("\nNumber of calcul iterations : ");
    scanf("%d", &c);

    for(i=1; i<=c; ++i) r = ((n/pow(r, 2))+2*r)/3;

    printf("\nAn approximation of the cubic root of %lf is : %lf (with %d iterations of the Newton's method)", n, r, c);
}
