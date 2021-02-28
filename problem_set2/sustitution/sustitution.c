#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string text_key(string m, string k);

int main(void)
{
    int n;
    string key;

    do
    {
        key = get_string("key: ");
        n = 0;

        if(strlen(key) <= 24)
            {
                printf("Error, try again!\n");
            }
        else
        {
            for(int i=0; i < strlen(key); i++){
                 if((key[i] >= 'a' &&  key[i] <= 'z') || (key[i] >= 'A' &&  key[i] <= 'Z'))
                 {
                       n++;
                 }

            }

            if(n < 26)
            {
                 printf("Error, try again!\n");
            }
        }
    }
    while(n < 26);

    string message = get_string("plaintext: ");
    printf("ciphertext: %s", text_key(message, key));
    printf("\n");
}

string text_key(string m, string k)
{
    string alph1= "abcdefghijklmnopqrstuvwxyz";
    string alph2= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string copyk= m;

    for(int j1=0; j1 < strlen(m); j1++)
    {
        for(int j2=0; j2 < strlen(alph1); j2++)
        {
             if(m[j1] == alph1[j2])
             {
                 copyk[j1] = tolower(k[j2]);
                 j2 = 100;
             }
             else if(m[j1] == alph2[j2])
             {
                 copyk[j1] = toupper(k[j2]);
                 j2 = 100;
             }

        }
    }

    return (string)copyk;
}
