#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float price = get_float("Cuál es el precio del producto?\n");
    float many = get_float("Cuánto dinero paga?\n");
    float change = many - price;
    printf("Su vuelvo es: %.2f\n", change);
    float n=0;
    int k=change;
    do
    {
        n = n - 0.25;
        k++;
    }
    while((n-0.25) >= 0.25);
    do
    {
        n = n - 0.1;
        k++;
    }
    while((n-0.1) >= 0.1);
    do
    {
        n = n - 0.05;
        k++;
    }
    while((n-0.05) >= 0.05);
    do
    {
        n = n - 0.01;
        k++;
    }
    while((n-0.01) >= 0.01);

    printf("Cantidad de monedas devueltas: %i\n", k);
}
