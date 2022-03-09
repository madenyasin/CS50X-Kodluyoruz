#include <stdio.h>
#include <cs50.h>
#include <math.h>

int getCoins(int);

int main(void){
    float change;
    int cents;
    do{
       change = get_float("Change owed: ");
    }while (change <= 0);

    cents = round(change * 100);

    printf("%i\n", getCoins(cents));
}

int getCoins(int cents)
{
    int coins = 0;  
    while (cents != 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            coins++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            coins++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            coins++;
        }
        else
        {
            cents--;
            coins++;
        }
    }

    return coins;
}
