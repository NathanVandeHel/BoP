#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    //productOfNumbers();
    //sumOfDivisors();
    //characterCode();
    //indexingOfBounds();
    //least();
    //shiftingAnArray();
    //prettyPrintingOfAnArray();
    //monotonity();
    //averageOfTheLastFiveValues();
    //river();
    //lessOrGreater();
    //product();
    //highwayI();
    highwayII();
    //statisticsOnLetters();
}

int productOfNumbers ()
{
    int product = 1;
    int n = 10;

    while(n >= 2)
    {
        printf("%d . %d \n", n, product);
        product *= n;
        n -= 1;
    }

    return 0;
}

int sumOfDivisors ()
{
    int n, sum, i;
    sum = 0;

    scanf("%d", &n);

    for(i=1; i<n; ++i)
    {
        if(!(n%i))
        {
            sum += i;
            printf("%d, ", i);
        }
    }

    printf("\nsum = %d", sum);

    if(sum == n)
    {
        printf("\n%d is a perfect number", n);
    }
    return 0;
}

int characterCode ()
{
    char letter;

    while(scanf("%c", &letter) == 1)
    {
        printf("letter = '%c', letter = %d \n", letter, letter);
    }

    return 0;
}

int indexingOfBounds ()
{
    double t[10];
    int a = 1, b = 2, c = 3;

    printf("a=%d\nb=%d\nc=%d\n", a, b, c);

    t[-1] = 0.2;
    t[10] = 0.3;
    printf("\n");

    printf("a=%d\nb=%d\nc=%d\n", a, b, c);

    return 0;
}

int least ()
{
    int t[10], i, j, min;

    t[0] = 378;
    t[1] = 69;
    t[2] = 54;
    t[3] = 8;
    t[4] = 77;
    t[5] = 6;
    t[6] = 29;
    t[7] = 10;
    t[8] = 89;
    t[9] = -5;

    min = t[0];
    j = 0;
    for(i=1; i<10; ++i)
    {
        if(t[i] < min)
        {
            min = t[i];
            j = i;
        }
    }
    printf("The least : %d \n", min);

    printf("Array : ");
    for(i=0; i<10; ++i)
    {
        if(i == j) printf("[%d]=%d(MIN) ",i,  t[i]);
        else printf("[%d]=%d ",i,  t[i]);
    }

    return 0;
}

int shiftingAnArray ()
{
    int t[10], temp, i, j, k;

    t[0] = 38;
    t[1] = 69;
    t[2] = 54;
    t[3] = 8;
    t[4] = 71;
    t[5] = 6;
    t[6] = 29;
    t[7] = 10;
    t[8] = 5;
    t[9] = 55;

    for(i=1; i<=10; ++i)
    {
        for(j=0; j<10; ++j)
        {
            if(t[j]<10) printf(" %d ", t[j]);
            else printf("%d ", t[j]);
        }
        printf("\n");

        temp = t[0];
        for(k=1; k<10; ++k) t[k-1] = t[k];
        t[9] = temp;
    }

    return 0;
}

int prettyPrintingOfAnArray ()
{
    int t[10], i;

    t[0] = 378;
    t[1] = 69;
    t[2] = 54;
    t[3] = 8;
    t[4] = 77;
    t[5] = 6;
    t[6] = 29;
    t[7] = 10;
    t[8] = 89;
    t[9] = -5;

    printf("[ %d", t[0]);
    for(i=1; i<10; ++i)
    {
        printf(", %d", t[i]);
    }
    printf(" ]");

    return 0;
}

int monotonity ()
{
    int t[10], i, j, initialStep, currentStep, go;
    go = 1;
    j = 2;

    for(i=0; i<10; ++i) scanf("%d", &t[i]);

    initialStep = t[1] - t[0];

    while (go && j<10)
    {
        currentStep = t[j] - t[j-1];
        if(currentStep != initialStep)
        {
            printf("Not a monotonous serie");
            go = 0;
        }
        ++j;
    }

    if(go == 1)
    {
        if(initialStep >= 0) printf("It's a monotonously increasing serie");
        else printf("It's a monotonously decreasing serie");
    }

    return 0;
}

int averageOfTheLastFiveValues ()
{
    int i;
    double valueReaded, average, t[5];
    valueReaded = 1;

    while(valueReaded)
    {
        printf("Enter a number : ");
        scanf("%lf", &valueReaded);

        if(valueReaded)
        {
            for(i=1; i<5; ++i) t[i-1] = t[i];
            t[4] = valueReaded;
        }
    }

    average = (t[0]+t[1]+t[2]+t[3]+t[4])/5;
    printf("%lf", average);

    return 0;
}

int river ()
{
    double t[18] = {0.1, 1, 1.5, 1.7, 2, 2.3, 2.8, 4.5, 9.8, 12, 14.1, 13, 11.9, 8.7, 6.1, 3.5, 1, 0.5};
    double slope, steepest = 0;
    int i, a, b;

    for(i=1; i<18; ++i)
    {
        slope = t[i] - t[i-1];
        if(slope < 0) slope = -slope;

        if(slope > steepest)
        {
            steepest = slope;
            a = (i-1)*2;
            b = i*2;
        }
    }

    printf("The steepest bottom is between %d m and %d m, The difference of height between theses two points is : %lf m", a, b, steepest);

    return 0;
}

int lessOrGreater ()
{
    int n, i, less = 0, greater = 0;
    double limit;

    printf("Size of the array : ");
    scanf("%d", &n);

    double t[n];
    for(i=0; i<n; ++i) t[i]=rand();

    printf("Enter the limit : ");
    scanf("%lf", &limit);

    for(i=0; i<n; ++i)
    {
        if(t[i] >= limit) greater++;
        else less++;
    }

    if(greater > less) printf("There are more elements greater than the limit : %d (less : %d)", greater, less);
    else if(greater < less) printf("There are more elements less than the limit : %d (greater : %d)",less, greater);
    else printf("There are as many elements greater than the limit that elements less than the limit (%d)", greater);

    return 0;
}

int product ()
{
    int n, m, i, j;

    printf("Size of the array : ");
    scanf("%d", &m);

    int t[m];
    for(i=0; i<m; ++i) t[i]=rand()%11;

    for(i=0; i<m; ++i) printf("%d ", t[i]);
    printf("\n");

    printf("value : ");
    scanf("%d", &n);

    for(i=0; i<m; ++i)
    {
        for(j=i+1; j<m; ++j)
            if(t[i]*t[j] == n) printf("t[%d]*t[%d] = %d*%d = %d \n",i, j, t[i], t[j], n);
    }

    return 0;
}

int highwayI ()
{
    int j, MAX_DATA = 300;
    int data[MAX_DATA];
    for(j=0; j<MAX_DATA; j+=3)
    {
        data[j] = rand()%25;
        data[j+1] = rand()%61;
        data[j+2] = rand ()%200 + 1;
    }
    data[MAX_DATA-3] = data [MAX_DATA-2] = data[MAX_DATA-1] = 0;
    //for(j=0; j<MAX_DATA; j+=1) printf("%d ", data[j]);
    //printf("\n");

    int SPEED_LIMIT = 130, speed = 1, i;
    int speedSave[24];
    for(i=0; i<24; ++i) speedSave[i] = 0;

    while(speed)
    {
        if(data[i+2] > SPEED_LIMIT && data[i+2] > speedSave[data[i]]) speedSave[data[i]] = data[i+2];

        speed = data[i+2];
        i += 3;
    }

    for(i=0; i<24; ++i)
    {
        if(speedSave[i] != 0) printf("%d:00-%d:59 -> %d km/h \n", i, i, speedSave[i]);
    }

    return 0;
}

int highwayII ()
{
    int j, MAX_DATA = 300;
    int data[MAX_DATA];
    for(j=0; j<MAX_DATA; j+=3)
    {
        data[j] = rand()%25;
        data[j+1] = rand()%61;
        data[j+2] = rand ()%200 + 1;
    }
    data[MAX_DATA-3] = data [MAX_DATA-2] = data[MAX_DATA-1] = 0;
    //for(j=0; j<MAX_DATA; j+=1) printf("%d ", data[j]);
    //printf("\n");

    int FIRST_SPEED_LIMIT = 140, SECOND_SPEED_LIMIT = 180, speed = 1, i;
    int fineSave[24];
    for(i=0; i<24; ++i) fineSave[i] = 0;

    while(speed)
    {
        if(data[i+2] > FIRST_SPEED_LIMIT) fineSave[data[i]] += 50;
        else if(data[i+2] > SECOND_SPEED_LIMIT) fineSave[data[i]] += 150;

        speed = data[i+2];
        i += 3;
    }

    for(i=0; i<24; ++i) printf("%d:00-%d:59, %d EUR \n", i, i, fineSave[i]);

    return 0;
}

int statisticsOnLetters ()
{


    return 0;
}
