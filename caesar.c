#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //int k = get_int("Input key: ");
    int key = 0;
    int cip_num = 0; //for storing cipher number (0-25)
    int alp_num = 0; //for storing ascii converted to aplhabetical index [0-25]
    if (argc == 2) // checking if we have 2 arguments i.e ./caesar and a number
    {
        key = atoi(
                  argv[1]); // converting the argument by user (i.e a string representing a number) to an actual integer
    }
    else // if there are more or less than 2 arguments program prompts error msg and suspends
    {
        printf("Wrong Argument\n");
        return 1;
    }
    string s = get_string("plaintext:  ");
    int len = strlen(
                    s);    //gets the length of the plain text string so that limit for the for loop can be determined
    printf("ciphertext: ");
    for (int i = 0; i < len; i++)
    {
        if (isalpha(s[i])) //checking if the character from plaintext is an alphabet
        {
            if (isupper(s[i])) //checking if alphabet is upper letter
            {
                alp_num = s[i] % 65; // as ascii for upper letters are 65-90 so %65 would yield a value from 0-25
                cip_num = (alp_num + key) %
                           26; //addition of alphabetical index and the key from the user and taking %26 yields [0-25]
                printf("%c", (cip_num +
                              65)); // adding number [0-25] of cip_num yields the ascii value for that alphabetical index
            }
            else // i.e if alphabet is lower letter
            {
                alp_num = s[i] % 97;
                cip_num = (alp_num + key) % 26;
                printf("%c", (cip_num + 97));
            }
        }
        else // if character from plaintext is other than a alphabet print it as is.
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}