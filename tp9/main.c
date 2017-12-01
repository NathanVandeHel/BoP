#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //valuesBackwards();
    //valuesBackwardsAgain();
    //readingInALongLine();
    //stammering2();
    //trimmer2();
    separateOddAndEven();

    return 0;
}

void valuesBackwards()
{
    int n, i;
    int * a = NULL;

    printf("Number of real values ? ");
    scanf("%d", &n);

    a = (int*)malloc(n*sizeof(int));

    for(i=0; i<n; ++i)
    {
        printf("Value num.%d ? ", i);
        scanf("%d", &a[i]);
    }

    for(i=n-1; i>=0; --i)
    {
        printf("value num.%d = %d \n", i, a[i]);
    }

    free(a);
}

void valuesBackwardsAgain()
{
    int numberOFValues = 0, i, n = 0;
    int * a = NULL;

    printf("Positive value to add ? ");
    scanf("%d", &n);

    while(n >= 0)
    {
        ++numberOFValues;
        int * temp = (int*)malloc(numberOFValues*sizeof(int));
        for(i=0; i<numberOFValues-1; ++i)
        {
            temp[i] = a[i];
        }
        free(a);
        temp[numberOFValues-1] = n;
        a = temp;

        printf("Positive value to add ? ");
        scanf("%d", &n);
    }

    printf("--- array backward--- \n");
    for(i=numberOFValues-1; i>=0; --i)
    {
        printf("%d \n", a[i]);
    }

    free(a);
}

void readingInALongLine()
{
    int numberOfChar = 0, i;
    char c = ' ';
    char * a = NULL;

    printf("Line of char ? \n");

    while(c != '\n')
    {
        scanf("%c", &c);

        ++numberOfChar;
        char * temp = (char*)malloc(numberOfChar*sizeof(char));
        for(i=0; i<numberOfChar-1; ++i)
        {
            temp[i] = a[i];
        }
        free(a);
        if(c != '\n') temp[numberOfChar-1] = c;
        else temp[numberOfChar-1] = '\0';
        a = temp;
    }

    printf("---string--- \n");
    printf("%s", a);

    free(a);
}

char * stam(char * s)
{
    int ctVowel = 0, ctConsonant = 0;
    int i, j = 0;

    for(i=0; s[i] != '\0'; ++i)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ctVowel++;
        else ctConsonant++;
    }

    char * st = (char *)malloc((2*ctVowel + ctConsonant + 1)*sizeof(char));

    for(i=0; s[i] != '\0'; ++i)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            st[j] = s[i];
            st[j+1] = s[i];
            j += 2;
        }else
        {
            st[j] = s[i];
            j += 1;
        }
    }
    st[j+1] = '\0';

    return st;
}

void stammering2 ()
{
    char a[50] = {"salut c'est cool"};
    char * stammed = stam(a);
    printf("%s", stammed);
    free(stammed);
}

char * trim(char * s)
{
    int i = 0, j = 0, k;

    while(s[i++] == ' '); --i;
    while(s[(j++)] != '\0'); --j;
    while(s[--j] == ' ');

    char * st = (char *)malloc((j-i+2)*sizeof(char));
    for(k = 0; k <= j-i; ++k)
    {
        st[k] = s[i+k];
    }
    st[k+1] = '\0';

    return st;
}

void trimmer2 ()
{
    char a[50] = {"    salut fdp    "};
    char * trimmed = trim(a);
    printf("|%s|", trimmed);
    free(trimmed);
}

void sepOnE(int * a, int n, int ** odd, int * nbOdd, int ** even, int * nbEven)
{
    int i, iOdd = 0, iEven =0;
    int ctOdd = 0, ctEven = 0;

    for(i=0; i<n; ++i)
    {
        if(a[i]%2) ctEven++;
        else ctOdd++;
    }

    int * aOdd = (int *)malloc(ctOdd*sizeof(int));
    int * aEven = (int *)malloc(ctEven*sizeof(int));

    for(i=0; i<n; ++i)
    {
        if(a[i]%2) aEven[iEven++] = a[i];
        else aOdd[iOdd++] = a[i];
    }

    *odd = aOdd;
    *even = aEven;
    *nbOdd = ctOdd;
    *nbEven = ctEven;
}

void separateOddAndEven()
{
    int a[40] ={1,5,9,4,3,1,98,12,45,6,1,9,21,2,1,9,2,4,292,89,8,5,14,9,6,25,48,3,4,8,9,26,5,92,23,45,89,34,5,20};
    int * odd, * even;
    int nbOdd, nbEven;
    int i;

    sepOnE(a, 40, &odd, &nbOdd, &even, &nbEven);

    printf("o %d, e %d \n", nbOdd, nbEven);

    for(i=0; i<nbOdd; ++i) printf("%d, ", odd[i]);
    printf("\n");
    for(i=0; i<nbEven; ++i) printf("%d, ", even[i]);
}
