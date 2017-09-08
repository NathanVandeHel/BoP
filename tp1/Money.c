#include <stdio.h>
#include <stdlib.h>

int money()
{
    int FiftyCoin, OneHundredCoin, TwoHundredCoin, Total;
    printf("How many 50 Ft coins do you have ?");
    scanf("%d", &FiftyCoin);
    printf("How many 100 Ft coins do you have ?");
    scanf("%d", &OneHundredCoin);
    printf("How many 200Ft coins do you have ?");
    scanf("%d", &TwoHundredCoin);

    Total = 50*FiftyCoin + 100*OneHundredCoin + 200*TwoHundredCoin;

    printf("In total, you have %d Ft", Total);

    return 0;
}
