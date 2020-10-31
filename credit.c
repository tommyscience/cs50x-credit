#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // calculate checksum

    long user;

    user = get_long("Number: ");

    long score = user;
    int product;
    int digit_sum = 0;
    while(score)
    {
        score /= 10;
        product = score % 10 * 2;
        while (product)
        {
            digit_sum += product % 10;
            product /= 10;
        }
        score /= 10;
    }

    int non_multi = 0;
    score = user;

    while(score)
    {
        non_multi += score % 10;
        score /= 100;
    }
    score = user;
    digit_sum += non_multi;
    // printf("digit-sum = %i\n", digit_sum);
    // check for card length and starting digits

    int count = 0;
    while(score)
        {
            score /= 10;
            count += 1;
        }
        // printf("count = %i\n", count);
        score = user;
        int iteration;
        iteration = count;
        while (iteration > 2)
        {
            score /= 10;
            iteration--;
        }

    // print out card type

    if((digit_sum % 10 == 0) && (count >= 13 && count <=16))
    {
        if(count == 13)
        {
            if (score / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if(count == 15)
        {

            if ((score == 34) || (score == 37))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if(count == 16)
        {
            if((score == 51) || (score == 52) || (score == 53) || (score == 54) || (score == 55))
            {
                printf("MASTERCARD\n");
            }
            else if(score / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
    }
    else if ((digit_sum % 10 != 0) || (count < 13) || (count > 16))
    {
        printf("INVALID\n");
    }

}
