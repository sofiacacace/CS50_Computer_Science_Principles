#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string ans = get_string("Cuál es tu nombre?\n");
    printf("hola, %s\n", ans);
}
