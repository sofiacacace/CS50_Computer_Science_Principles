#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float index_readability(string txt);

int main(void){

    string t = get_string("Text:\n");

    float grade = index_readability(t);

    if (grade > 16){
        printf("Grade 16+");
    }
    else if (grade < 1){
        printf("Before Grade 1");
    }
    else{
        printf("Grade %.f\n", round(grade));
    }
     printf("\n");
}

float index_readability(string txt){

    float lp = 0;
    float sp = 0;
    float l = 0;
    float s = 0;
    float w = 1;

    for(int i=0; i<strlen(txt); i++){

        if (txt[i] == ' '){     // words counter
            w++;
        }
        else if (txt[i] == '!' || txt[i] == '.' || txt[i] == '?'){   // sentences counter
            s++;
        }
        else if (txt[i] >= 'a' && txt[i] <= 'z'){     // letters counter
            l++;
        }
        else if (txt[i] >= 'A' && txt[i] <= 'Z'){
            l++;
        }

    }

    lp = (l/w)*100;
    sp = (s/w)*100;
    float result = ((0.0588*lp)-(0.296*sp)-15.8);

    return (float)result;

}
