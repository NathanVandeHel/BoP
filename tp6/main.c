#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct Date {
    int year, month, day;
} Date;

typedef struct Competitor {
    char name[31];
    Date birth;
    int rank;
} Competitor;

typedef struct Point {
    double x, y;
} Point;

typedef struct VelocityVector {
    double vx, vy;
} VelocityVector;

void Date_print(Date d);
void Competitor_print(Competitor c);
int compoundDataType();
int vowel(char);
double dist(Point, Point);
int samePosition(Point, Point);
Point getPointFromUser();
double vectorLength(VelocityVector);
VelocityVector vectorSum(VelocityVector, VelocityVector);

int main()
{
    //functionTheBasics();
    //stammering();
    //compoundDataType();
    //menuControlledProgram();
    //fence();
    vectors();
    return 0;
}

void functionTheBasics()
{
    int a;
    scanf("%d", &a);
    printf("%d^3 = %d \n|%d| = %d", a, cube(a), a, absolute(a));
}

int cube(int a)
{
    return a*a*a;
}

int absolute(int a)
{
    if(a>=0) return a;
    return -a;
}

void stammering()
{
    char c;
    while (scanf("%c", &c) == 1)
    {
        if (vowel(tolower(c)))
            printf("%ch%c", c, tolower(c));
        else
            printf("%c", c);
    }
}

int vowel(char c)
{
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
    return 0;
}

int compoundDataType()
{
    Competitor competitors[5] = {
        { "Am, Erica", {1984, 5, 6}, 1 },
        { "Abnorm, Al", {1982, 9, 30}, 3 },
        { "Pri, Mary", {1988, 8, 25}, 2 },
        { "Duck, Ling", {1979, 6, 10}, 5 },
        { "Mac, Donald", {1992, 4, 5}, 4 },
    };

    int i;

    /* name of competitor 0 - printf %s */
    printf("competitor 0 : %s \n", competitors[0].name);
    /* rank of competitor 2 */
    printf("rank of competitor 2 : %d \n", competitors[2].rank);
    /* birth date of competitor 4, use the given function */
    printf("birth date of competitor 4 : ");
    Date_print(competitors[4].birth);
    printf("\n");
    /* the first letter of the name of competitor 1 (a string is an array of characters) */
    printf("first letter of the name of competitor 1 : %c \n", competitors[1].name[0]);
    /* is competitor 1 among the best three? yes/no, may use ?: operator */
    printf("is competitor 1 among the best three? : %s \n", competitors[1].rank <= 3 ? "yes" : "no");
    /* is competitor 4 faster than competitor 3? */
    printf("is competitor 4 faster than competitor 3? : %s \n", competitors[4].rank < competitors[3].rank ? "yes" : "no");
    /* was competitor 1 born in the same year as competitor 2? */
    printf("was competitor 1 born in the same year as competitor 2? : %s \n", competitors[1].birth.year == competitors[2].birth.year ? "yes" : "no");
    /* complete the Competitor_print() function,
     * then print all data of competitor 1 */
    /* at last print all data of all competitors. */
    printf("--- data of competitor 1 --- \n");
    Competitor_print(competitors[1]);
    printf("--- data of all competitors --- \n");
    for(i=0; i<5; ++i)
    {
        printf("** Competitor %d ** \n", i);
        Competitor_print(competitors[i]);
        printf("\n");
    }

    return 0;
}

void Date_print(Date d)
{
    printf("%d.%d.%d.\n", d.year, d.month, d.day);
}

void Competitor_print(Competitor c)
{
    printf(" - name : %s \n - date birth : ", c.name);
    Date_print(c.birth);
    printf(" - rank : %d \n", c.rank);
}

void menuControlledProgram()
{
    int menuRun = 1;
    int n = 1;
    int choice;

    while(menuRun)
    {
        printf("----- n = %d ----- \n", n);
        printf("0. Restore the initial value (n = 1)\n"
            "1. Add 1\n"
            "2. Negate the number (+/-)\n"
            "3. Multiple by 2\n"
            "9. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 0:
            n = nInit(n);
            break;
        case 1:
            n = nAdd(n);
            break;
        case 2:
            n = nNegate(n);
            break;
        case 3:
            n = nMultiple(n);
            break;
        case 9 :
            menuRun = 0;
        }
    }
}

int nInit(int n)
{
    return 1;
}

int nAdd(int n)
{
    return (n+1);
}

int nNegate(int n)
{
    return -n;
}

int nMultiple(int n)
{
    return (2*n);
}

void fence()
{
    /*Point a = {3.3, 15.6};
    Point b = {0, 48.5};
    printf("%lf \n", dist(a, b));
    printf("%s \n", samePosition(a, b) ? "oui" : "non");*/

    double length = 0;
    int fenceOpen = 1;
    Point firstPole, p1, p2;

    printf("Position Of the first pole : \n");
    firstPole = getPointFromUser();
    p1 = firstPole;

    while(fenceOpen)
    {
        printf("Position of the next pole : \n");
        p2 = getPointFromUser();
        if(samePosition(p2, firstPole)) fenceOpen = 0;
        else
        {
            length += dist(p1, p2);
            p1 = p2;
        }
    }
    printf("Length of the fence : %lf m", length);
}

double dist(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int samePosition(Point a, Point b)
{
    if(dist(a, b)) return 0;
    return 1;
}

Point getPointFromUser()
{
    Point p;
    printf("x = ");
    scanf("%lf", &p.x);
    printf("y = ");
    scanf("%lf", &p.y);
    return p;
}

void vectors()
{
    VelocityVector v1 = {1, 2};
    VelocityVector v2 = {-0.5, 3};

    VelocityVector vs = vectorSum(v1, v2);
    printf("sum : vx = %lf, vy = %lf \n", vs.vx, vs.vy);
    printf("length = %lf", vectorLength(vs));

}

double vectorLength(VelocityVector v)
{
    return sqrt(pow(v.vx, 2) + pow(v.vy, 2));
}

VelocityVector vectorSum(VelocityVector v1, VelocityVector v2)
{
    VelocityVector vr={v1.vx + v2.vx, v1.vy + v2.vy};
    return vr;
}
