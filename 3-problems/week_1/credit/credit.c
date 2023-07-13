#include <cs50.h>
#include <stdio.h>
#include <string.h>

unsigned long long get_card_number(void) {
    unsigned long long number = get_long_long("Enter your credit card number: ");
    return number;
}

char * get_card_provider(unsigned long long number) {
    unsigned long long first;
    first = number;
    char provider[] = "";
    while(first >= 10)
    {
        first = first / 10;
    }
    if (first == 4) {
        return "VISA";
    } else {
        first = number;
        while(first >= 100)
        {
            first = first / 10;
        }
        if (first == 34 || first == 37) {
            return "AMEX";
        } else if (first == 51 || first == 52 || first == 53 || first == 54 || first == 55) {
            return "MASTERCARD";
        } else {
            return "INVALID";
        }
    }
}

char * check_card_valid(unsigned long long number, char * provider) {
    //Count the number of digits in the card number
    int count = 1;
    while (number > 10)
    {
        number = number / 10;
        count = count + 1;
    }

    //Confirm number of digits is correct as per speicifcation
    if (strcmp(provider,"VISA") == 0) {
        if (count == 13 || count == 16) {
            return "Valid";
        }
    }
    if (strcmp(provider,"AMEX") == 0) {
        if (count == 15) {
            return "Valid";
        }
    }
    if (strcmp(provider, "MASTERCARD") == 0) {
        if (count == 16) {
            return "Valid";
        }
    } else {
        return "INVALID";
    }
        return "INVALID";
}

int check_card_number(unsigned long long number) {
    int mod = 0;
    int sum = 0;
    while (number > 0) {
        mod = number % 10;
        number = number / 10;
        mod = number % 10;
        number = number / 10;
        if ((mod * 2) > 9){
            sum = sum + ((mod * 2) % 10) + ((mod * 2) / 10);
        } else {
            sum = sum + mod * 2;
        }
    }
    return sum;
}

int add_other_numbers(unsigned long long number) {
    int mod = 0;
    int sum = 0;
    while (number > 0) {
        mod = number % 10;
        number = number / 10;
        sum = sum + mod;
        mod = number % 10;
        number = number / 10;
        }
    return sum;
}

bool final_check(int sum) {

    int finalDig = sum % 10;
    if (finalDig == 0) {
        return true;
    } else {
        return false;
    }
}

int main(void) 
{
    unsigned long long number = get_card_number();   
    char * provider = get_card_provider(number);
    printf("Provider: %s\n", provider);
    char * valid = check_card_valid(number, provider);
    printf("Length: %s\n", valid);
    int num = check_card_number(number);
    int num2 = add_other_numbers(number);
    num = num + num2;
    bool validity = final_check(num);
    if (validity == true) {
        printf("Number: Valid\n");
    } else {
        printf("Number: Invalid\n");
    }
}
