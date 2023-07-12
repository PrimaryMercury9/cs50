#include <cs50.h>
#include <stdio.h>

/*
report (via printf) whether it is a valid American Express, MasterCard, or Visa
card number, per the definitions of each’s format herein. 
Catch inputs that are not credit card numbers (e.g., a phone number)
Last line of output to be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n
*/

/* Test numbers
AMEX       378282246310005
AMEX       371449635398431
AMEX       378734493671000
Diners     30569309025904
Discover   6011111111111117
Discover   6011000990139424
JCB	       3530111333300000
JCB	       3566002020360505
Mastercard 2221000000000009
Mastercard 2223000048400011
Mastercard 2223016768739313
Mastercard 5555555555554444
Mastercard 5105105105105100
Visa       4111111111111111
Visa       4012888888881881
Visa       4222222222222
*/

int get_card_number(void) {
    unsigned long long number = get_long_long("Enter your credit card number: ");
    return number;
}

char get_card_provider(unsigned long long number) {
    printf("%lld\n", number);
    unsigned long long first;
    first = number;
    while(first >= 10)
    {
        first = first / 10;
    }
    if (first == 4) {
        printf("VISA");
    else {
        first = number;
        while(first >= 10)
        {
            first = first / 10;
        }
        if (first == 34 || first == 37) {
            printf("AMEX");
        else if (first == 
    }

    printf("The first number is: %llu\n", first);

}
/*
American Express numbers start with 34 or 37
American Express uses 15-digit numbers

MasterCard numbers start with 51, 52, 53, 54, or 55
MasterCard uses 16-digit numbers

Visa numbers start with 4
Visa uses 13- and 16-digit numbers
*/
int main(void) 
{
    unsigned long long number = get_card_number();   
    char provider = get_card_provider(number);
}
