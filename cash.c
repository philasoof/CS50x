#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    printf("Change owed: ");
    float change = get_float();
    while(change<0)
    {
        printf("Change owed: ");
        change = get_float();
    }
    change = change * 100;
    change = roundf(change);
    int changecent = change;
    printf("changecent is: %i\n", changecent);
    int count = 0;
    while(changecent/25 >=1)
    {
        count++;
        changecent= changecent-25;
    }
    while(changecent/10 >=1)
    {
        count++;
        changecent= changecent-10;
    }
    while(changecent/5 >=1)
    {
        count++;
        changecent= changecent-5;
    }
    while(changecent/1 >=1)
    {
        count++;
        changecent= changecent-1;
    }
    printf("%i\n",count);
}