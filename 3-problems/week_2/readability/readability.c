#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

string get_excerpt(void);
int count_words(string excerpt);
int count_letters(string excerpt);
int count_sentences(string excerpt);
int calculate_grade(float letters, float sentences);

int main(void) {
    string excerpt = get_excerpt();
    int words = count_words(excerpt);
    int letters = count_letters(excerpt);
    float letters_per = letters * (100.0/words);
    int sentences = count_sentences(excerpt);
    float sentences_per = sentences * (100.0/words);
    int grade = calculate_grade(letters_per, sentences_per);
    if (grade < 1) {
        printf("Before Grade 1\n");
    }
    else if(grade > 0 && grade < 16) {
        printf("Grade %i\n", grade);
    }
    else if (grade > 15) {
        printf("Grade 16+\n");
    } 
}

string get_excerpt(void) {
    string excerpt = get_string("Text: ");
    return excerpt;
}

int count_words(string excerpt) {
    int words = 1;
    for (int i = 0; i < strlen(excerpt); i++) {
        if (excerpt[i] == 32) {
            words++;
        }
    }
    return words;
}

int count_letters(string excerpt) {
    int letters = 0;
    for (int i = 0; i < strlen(excerpt); i++) {
        int index = (int)tolower(excerpt[i]);
        if (index > 96 && index < 123) {
            letters++;
        }
    }
    return letters;
}

int count_sentences(string excerpt) {
    int sentences = 0;
    for (int i = 0; i < strlen(excerpt); i++) {
        if (excerpt[i] == 46 || excerpt[i] == 33 || excerpt[i] == 63) {
            sentences++;
        }
    }
    return sentences;
}

int calculate_grade(float letters, float sentences) {
    int grade = round((0.0588 * letters) - (0.296 * sentences) - 15.8);
    return grade;
}
