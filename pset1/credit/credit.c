#include <stdio.h>
#include <cs50.h>

long deleteLastNumber(long);
int sumOfDigits(int);
void printCardType(long);
int getFirst2DigitNumber(long);
void printCardType(long);

int counterDigit = 0;

int main(void)
{
    long cardNumber = get_long("Number: ");
    
    long tmpNumber = cardNumber;
    int sum = 0, sum1 = 0, sum2 = 0;
    
    while(tmpNumber != 0)
    {
        counterDigit++;
        if (counterDigit % 2 == 1)
        {
            sum1 += tmpNumber % 10;
            tmpNumber = deleteLastNumber(tmpNumber);
            
        }
        else
        {
            sum2 += sumOfDigits((tmpNumber % 10) * 2);
            tmpNumber = deleteLastNumber(tmpNumber);
        }
    }
    sum = sum1 + sum2;
    if (counterDigit < 15 || counterDigit > 16)
        printf("INVALID\n");
    else if (sum % 10 == 0)
        printCardType(cardNumber);
    else
        printf("INVALID\n");
       

}

int getFirst2DigitNumber(long cardNumber)
{
    for(int i = 0; i < counterDigit - 2; i++)
        cardNumber = deleteLastNumber(cardNumber);
    return cardNumber;
}

void printCardType(long number)
{
    int control = getFirst2DigitNumber(number);
    
    if (control == 34 || control == 37)
        printf("AMEX\n");
    else if (control == 51 || control == 52 || control == 53 || control == 54 || control == 55)
        printf("MASTERCARD\n");
    else if (control / 10 == 4)
        printf("VISA\n");
    else
        printf("INVALID\n");
}
int sumOfDigits(int number){
    int sum = 0;
    while(number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

long deleteLastNumber(long number)
{
    number /= 10;
    return number;
}
