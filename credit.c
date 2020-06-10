#include <cs50.h>
#include <stdio.h>

void verifyCard(long cardNum);

int main(void)
{
    long n;
    do
    {
        n = get_long("Enter Credit Card Number: ");
    }
    while (n < 1 || n > 9999999999999999);
    verifyCard(n);
}

//function to run Luhn's algorithm and validate credit card numbers
void verifyCard(long cardNum)
{
    long startNums = cardNum;
    int count = 2;
    //Get the cards first two nums by diving the long card numeber by 10 until there is two digits
    //collect count (number of digits)
    while(startNums > 100)
    {
        startNums = startNums / 10;
        count++;
    }

    long tempCardNum = cardNum;
    int sum = 0;
    bool valid;

    //store credit card num in temp variable, loop through number two digits at a time
    //multiply every other digit by two starting with second to last
    //add sum of multiple digts with the sum of remaining digits
    for (int i = 1; i <= count; i++)
    {
        int digit = tempCardNum % 10;
        if (i % 2 == 0)
        {
            if (digit * 2 > 9)
            {
                sum += (digit * 2) - 9;
            }
            else
            {
                sum += digit * 2;
            }
        }
        else
        {
            sum += digit;
        }
        //next two digits in loop
        tempCardNum /= 10;
    }

    //boolean expression, check if card is valid
    if (sum % 10 == 0)
    {
        valid = true;
    }
    else
    {
        valid = false;
    }

    //determine based on starting nums and card digit length the type of card
    if (count == 15 && (startNums == 34 || startNums == 37) && valid)
    {
        printf("AMEX\n");
    }
    else if (count == 16 && (startNums > 50 && startNums < 56) && valid)
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16 ) && startNums / 10 == 4 && valid)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

