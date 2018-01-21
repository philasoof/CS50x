#include<stdio.h>
#include<cs50.h>

int main(void)
{
    
    printf("Height:");
    int lim = get_int(); //take the height of the pyramid
    while(lim < 0 || lim >23)  // checks for invalid input
        {
            printf("Height:");
            lim = get_int();
        }
    int sign = 1;   //as at the start number of #'s is 2
    for(int x = 0; x < lim; x++) //caters for the height of the pyramid
    {
        for(int y=0; y < lim - sign; y++) //prints the spaces
        {
            printf(" ");
        }
        for(int z = sign; z > 0; z-- ) //prints the #'s
        {
            printf("#");
        }
        printf("  ");
        for(int z = sign; z > 0; z-- ) //prints the #'s
        {
            printf("#");
        }
        printf("\n"); //take the printer to next line
        sign++; //to increase number of #'s in next line
    }
        
}