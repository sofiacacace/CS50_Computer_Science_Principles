#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    int n1;
    int num;
    do
    {
       num = get_int("Altura de torres: ");
    }
    while (num<1 || num>8);

    for(int i=1; i<=num; i++)
    {
        n = i;
        n1 = num - i;

        for(int s=0; s<n1; s++)
        {
            printf(" ");
        }

        for(int j=0; j<n; j++)
        {
            printf("#");
        }

        printf("  ");

        for(int k=0; k<n; k++)
        {
            printf("#");
        }

         for(int t=0; t<n1; t++)
        {
            printf(" ");
        }

        printf("\n");
    }
}
