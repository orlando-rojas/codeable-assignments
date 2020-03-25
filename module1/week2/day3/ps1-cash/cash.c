#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    int result = 0;
    float change;
    do {
        change = get_float("Change owed: ");
    } while (change<=0);

    int ci = round(change*100);
    
    while(ci>0){
        if(ci>=quarter){
            ci = ci-quarter;
            result++;
        }else if (ci>=dime){
            ci = ci-dime;
            result ++;
        }else if (ci>=nickel){
            ci = ci-nickel;
            result ++;
        }else if (ci>=penny){
            ci = ci-penny;
            result ++;
        }
    }
    printf("%i\n", result);
}