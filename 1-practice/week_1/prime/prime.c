#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    //Ask for minimum
    int min;
    do {
        min = get_int("What is the minimum you would like? ");
    }
    while (min < 2);

    //Ask for maximum
    int max;
    do {
        max = get_int("What is the maximum you would like? ");
    }
    while (max < min);
    
    //Count through values between min and max and send to prime function
    int number;
    for (int i = min; i < (max + 1); i++) {
        if (prime(i) == true) {
            printf("%i\n", i);
        } 
    } 
}

//Find prime numbers between min and max
bool prime(int number) {
    int count = 0;
    for (int j = 2; j < number; j++) {
        int result = number % j;
        if (result == 0) {
            count = count + 1;
        }
    }
    if (count > 0) {
        return false;
    } else {
        return true;
    }
}
