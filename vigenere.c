#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key; //for storing argv, to perform operations
    int key_len; 
    if (argc == 2) 
    {
        key = argv[1];
        key_len = strlen(key);
    }
    else
    {
        return 1;
    }
    int k[key_len]; //integer array to store coverted key string characters
    for (int i = 0; i < key_len; i++) //running till the length of key string
    {
        if (isalpha(key[i]))
        {
            if (islower(key[i]))
            {
                int c = key[i];
                c = c % 97;
                k[i] = c; // converts string ascii to alphabetical index and store in integer array 'k'
            }
            else
            {
                int c = key[i];
                c = c % 65;
                k[i] = c;
            }
        }
        else
        {
            return 1;
        }
    }
    printf("plaintext:  ");
    string plain = get_string();
    int plain_len = strlen(plain);
    printf("ciphertext: ");
    int alp_num, cip_num, key_num, c = 0; //introducing c here to run as a separate counter for the key array
    for (int i = 0; i < plain_len; i++)
    {
        if (isalpha(plain[i])) //checking if the character from plaintext is an alphabet
        {
            if (isupper(plain[i])) //checking if alphabet is upper letter
            {
                alp_num = plain[i] % 65; // as ascii for upper letters are 65-90 so %65 would yield a value from 0-25
                key_num = c % key_len;
                cip_num = (alp_num + k[key_num]) % 26; //addition of alphabetical index and the key from the user and taking %26 yields [0-25]
                printf("%c", (cip_num + 65)); // adding number [0-25] of cip_num yields the ascii value for that alphabetical index
                c++; // adds to c only when the plaintext character is an alphabet otherwise c is stopped
            }
            else // i.e if alphabet is lower letter
            {
                alp_num = plain[i] % 97;
                key_num = c % key_len;
                cip_num = (alp_num + k[key_num]) % 26;
                printf("%c", (cip_num + 97));
                c++;
            }
        }
        else // if character from plaintext is other than a alphabet print it as is.
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
