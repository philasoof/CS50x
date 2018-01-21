#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Height: ");
    int lim = get_int();
    while (lim < 0 || lim > 23)
    {
        printf("Height: ");
        lim = get_int();
    }
//base refers to the total number of #´s in the base
    int base = lim + 1;
//start refers to the number of hashes in the first row, though constant it´s taken as a variable to add more #´s for next rows
    int start = 2;

    for (int x = 0; x < lim ; x++) //this loop caters for the height
    {
        for (int y = base - start; y > 0 ; y--) //this loop cater for number of spaces
        {
            printf(" ");
        }
        for (int z = start; z > 0 ; z--) // caters for the number of #'s
        {
            printf("#");
        }
        printf("\n"); //takes the loop to next row
        start++; // adds 1 to the 'start' variable because going into next row number of #'s increase by 1
    }
}