#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    //floatingPointNumbers();
    //fractionOfHighComplexity();
    //infiniteLoop();
    //powerOfTwo();
    //powerOfTwo2();
    //bitsOfANumber();
    //theSecretOfTheBits();
    drawing();

    return 0;
}

int floatingPointNumbers ()
{
    double dvar=1e20/1e-20;
    float fvar=1e20f/1e-20f;
    printf("1. %g\n", dvar);
    printf("2. %g\n", fvar);
    printf("3. %g\n", 1e60);
    printf("4. %f\n", 1e60);
    printf("5. %s\n", 1e3+1 == 1e3 ? "yes" : "no");
    printf("6. %s\n", 1e30+1 == 1e30 ? "yes" : "no");

    return 0;
}

int fractionOfHighComplexity ()
{
    float a = (4+2-(3-(6+(4.f/5.f))))/(3*(2-7));
    printf("%lf", a);

    return 0;
}

int infiniteLoop ()
{
    int i = 1;
    while (i > 0) {
        ++i;
        printf("%d\n", i);
    }
    printf("%d\n", i);

    return 0;
}

int powerOfTwo ()
{
    unsigned int a = 1;
    int i = 0;

    while(a>0 && i<=100)
    {
        printf("2^%d = %u \n", i, a);
        a <<= 1; // a = a << 1
        ++i;
    }

    return 0;
}

int powerOfTwo2 ()
{
    /*
    printf arguments :
    int -> %d
    unsigned int -> %u
    unsigned long int -> %lu
    unsigned long long int -> %llu
    */

    unsigned int a = 1;
    unsigned short int b = 1;
    unsigned long int c = 1;
    unsigned char d = 1;
    unsigned long long int e = 1;

    int cta = 0;
    int ctb = 0;
    int ctc = 0;
    int ctd = 0;
    int cte = 0;

    while(a>0)
    {
        printf("%u \n", a);
        a <<= 1;
        ++cta;
    }
    printf("--- unsigned int  : %u bits --- \n", cta);

    while(b>0)
    {
        printf("%u \n", b);
        b <<= 1;
        ++ctb;
    }
    printf("--- unsigned short int  : %d bits --- \n", ctb);

    while(c>0)
    {
        printf("%lu \n", c);
        c <<= 1;
        ++ctc;
    }
    printf("--- unsigned long int  : %d bits --- \n", ctc);

    while(d>0)
    {
        printf("%u \n", d);
        d <<= 1;
        ++ctd;
    }
    printf("--- unsigned char  : %d bits --- \n", ctd);

    while(e>0)
    {
        printf("%llu \n", e);
        e <<= 1;
        ++cte;
    }
    printf("--- unsigned long long int  : %d bits --- \n", cte);

    return 0;
}

int bitsOfANumber ()
{
    unsigned long int a;
    scanf("%lu", &a);

    unsigned long int temp;
    int i;

    for(i=31; i>=0; --i)
    {
        temp = a >> i;
        temp &= 1;
        printf("%lu", temp);
    }

    return 0;
}

int theSecretOfTheBits ()
{
    unsigned long values[8] = {0U, 2436482610U, 2862950730U, 2762287426U, 2436483290U, 2317437256U, 2216764978U, 0U};
    unsigned long int temp;
    int i, j;

    for(j=0; j<8; ++j)
    {
        values[j] ^= 65535;
    }

    for(j=0; j<8; ++j)
    {
        for(i=31; i>=0; --i)
        {
            temp = values[j] >> i;
            temp &= 1;
            printf("%c", temp == 1 ? '#' : ' ');
        }
        printf("\n");
    }


    return 0;
}

int drawing ()
{
    const int MAX_LINE = 24;
    unsigned long int values[MAX_LINE];
    memset(values, 0, sizeof(unsigned long int)*MAX_LINE);
    unsigned long int temp;
    int i, j, choice;
    int x, y;

    while(1)
    {
        printf("draw : 1 \nreset : 0 \n");
        scanf("%d", &choice);

        if(choice)
        {
            printf("x y : ");
            scanf("%d %d", &x ,&y);

            if(x > 32 || x <= 0 || y > MAX_LINE || y <= 0)
            {
                printf("Coord overflow \n");
            }else
            {
                values[MAX_LINE-y] |= (1 << (32-x));
            }

        }else
        {
            memset(values, 0, sizeof(unsigned long int)*MAX_LINE);
        }

        for(j=0; j<MAX_LINE; ++j)
        {
            for(i=31; i>=0; --i)
            {
                temp = values[j] >> i;
                temp &= 1;
                printf("%c", temp == 1 ? '#' : '.');
            }
            printf("\n");
        }
    }

    return 0;
}
