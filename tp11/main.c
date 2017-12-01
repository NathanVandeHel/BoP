#include <stdlib.h>

char * dynamicstrdup(char* strArray);
char * dynamicstrcat(char* x, char* y);
char * dynamicsubstring(char * str, int init, int end);
char * dynamicstrins(char * x, char * y, int position);

int main()
{
    //dynamic duplicate of a string
    char* str = dynamicstrdup("salut cest cool!");
    printf("%s \n", str);

    //dynamic append
    str = dynamicstrcat(str, " tg");
    printf("%s \n", str);

    //substring
    char* substr = dynamicsubstring(str, 7, 11);
    printf("%s \n", substr);

    char * strins = dynamicstrins("ceci test", "est un ", 5);
    printf("%s \n", strins);

    free(str);
    free(substr);

    return 0;
}

char * dynamicstrdup(char* strArray)
{
    int ct = 0, i;

    while(strArray[ct++] != '\0');   //count the size of the string including '\0'

    char * dynamicString = (char*)malloc(ct * sizeof(char*));

    for(i = 0; i < ct; ++i)
    {
        dynamicString[i] = strArray[i];
    }

    return dynamicString;
}

char * dynamicstrcat(char* x, char* y)
{
    int ctx =0, cty = 0, i;
    while(x[ctx++] != '\0'); ctx--; //count the size of the string x excluding '\0'
    while(y[cty++] != '\0'); //count the size of the string y including '\0'

    char * dynamicAppend = (char*)malloc((ctx + cty) * sizeof(char*));

    for(i = 0; i < ctx; ++i) dynamicAppend[i] = x[i];
    for(i; i < ctx + cty; ++i) dynamicAppend[i] = y[i - ctx];

    free(x);

    return dynamicAppend;
}

char * dynamicsubstring(char * str, int init, int end)
{
    int ct = 0, i;

    while(str[ct++] != '\0'); //count the size of the string x including '\0'

    if(init > end)
    {
        int tmp = init;
        init = end;
        end = tmp;
    }
    if(init < 0) init = 0;
    if(end < 0) end = 0;
    if(end > ct) end = ct;
    if(init > ct) init = ct;
    if(init == end)
    {
        if(init == ct) init = end - 1;
        else end = init + 1;
    }

    char* subString = (char*)malloc((end - init + 1) * sizeof(char*));

    for(i = init; i < end; ++i)
    {
        subString[i - init] = str[i];
    }
    subString[end - init] = '\0';

    return subString;
}

char * dynamicstrins(char * x, char * y, int position)
{
    char * xinit = dynamicsubstring(x, 0, position);
    char * xend = dynamicsubstring(x, position, 1000);
    char * result = dynamicstrcat(xinit, y);
    result = dynamicstrcat(result, xend);
    return result;
}
