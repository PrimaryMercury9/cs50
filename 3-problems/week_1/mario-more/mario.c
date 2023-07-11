#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    //Get integer between 1 & 8 from the user
    int size;
    do {
        size = get_int("Enter the size (between 1 and 8) ");
    }
    while (size < 0 || size > 8);

    //Draw the right aligned triangle of hash marks
    for (int i = 0; i < size; i++) {
        for (int k = size - i; k > 0 +1; k--){
            printf(" ");
        }
            for (int j = 0; j < i + 1; j++) {
                printf("#");
            }
        printf("  ");
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }

            printf("\n");
    }
}
