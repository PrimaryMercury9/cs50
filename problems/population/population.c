#include <cs50.h>
#include <stdio.h>

int main(void) {

    // Get the inital herd size
    int start = get_int("Initial herd size: ");
    printf("%d\n", start);
    while (start < 9) {
        start = get_int("Initial herd size: ");
    }

    // Get the target herd size
    int goal = get_int("Goal herd size: ");
    while (goal < 9 || goal <= start) {
        goal = get_int("Goal herd size: ");
    }

    // Calculate how long it will take to reach goal size
    int years = 0;
    int herd = start;
    while (herd < goal) {
        years +=1;
        herd = herd + (herd / 3) - (herd / 4);
    }

    // Print result
    printf("It will take %i years for your llama population to reach %i\n", years, herd);
}
