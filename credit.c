#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long long num = get_long_long("Number: "); //takes the credit card number from the user
    long long num_check; // to duplicate the credit card number in order to perform any kind of operations
    int length = 0; // to store length of the credit card
    int sum1 = 0; // to store the sum of the last element and everyother from last element
    int sum2 = 0; // to store the sum of the second to last element and everyother from second last element
    int p1, p2, id;
    num_check = num;
    while (num_check > 0) //checking if credit card number is =ive
    {
        num_check = num_check / 10; // dividing num_check by 10 and store it in num_check reduces num_check one digit at a time 
        length++; //num_check/10 acting as a counter so the end result of length++ give the length of the credit card
    }
    num_check = num; //in above while loop num_check was changed to puting credit card number in it again
    int num_array[length], ind_num; //storing cc numb in array makes it easier to access individial numbers at dif. positions
    for (int i = length -1; i >= 0; i--) //starts from length-1 coz array include 0th element as well, len 15 would be num_array[15]
    {
        ind_num = num_check % 10; // gets last digit of credit card
        num_array[i] = ind_num;
        num_check = num_check / 10; // removes last digit of credit card
    }
    for(int j = length - 1; j >= 0; j = j - 2) // length -1 means starting from last elemet of num_array
    {
        sum1 = sum1 + num_array[j]; //gets sum of last element and everyother ofter that
    }
    for(int j = length - 2; j >= 0; j = j - 2) // length -2 means starting from second to last element in num_array
    {
        if((2*num_array[j]<10)) 
        {
            sum2 = sum2 + (2 * num_array[j]);
        }
        else
        {
            p1 = (num_array[j] * 2) % 10; // if >10 stores last digit in p1 and next in p2
            p2 = ((num_array[j] * 2) / 10) % 10;
            sum2 = sum2 + p1 + p2; // adds first and last digit of num_array[j]*2 separately to sum2
        }
    }
    id = sum1 + sum2;
    if (id % 10 == 0) //checks for luhn's algorithm result ie a 0 at the end 
    {
        if (length == 15 && num_array[0] == 3)
        {
            if (num_array[1] == 4 || num_array[1] == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 16 && num_array[0] == 5)
        {
            if(num_array[1] == 1 || num_array[1] == 2 || num_array[1] == 3 || num_array[1] == 4 || num_array[1] == 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 13 && num_array[0] == 4)
        {
            printf("VISA\n");
        }
        else if (length == 16 && num_array[0] == 4)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
