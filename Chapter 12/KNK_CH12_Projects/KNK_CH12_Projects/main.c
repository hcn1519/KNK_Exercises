//
//  main.c
//  KNK_CH12_Projects
//
//  Created by changnam hong on 2020/12/27.
//

#include <stdio.h>
#include <stdbool.h>

int readInput(char *sentence);
void reverseInput(void);
bool isAlphabet(char c);
char lowercased(char input);
int trimLetters(char *rawSentence, char *trimmedSentence, int rawInputLength);
void reverseArray(char *original, char *reversed, int length);

int readInput(char *sentence) {
    char character;
    int i = 0;
    while (( character = getchar()) != '\n') {
        sentence[i++] = character;
    }
    return i;
}

void reverseInput() {
    printf("Reverse - Enter a Message: ");

    char sentence[10000];
    int length = readInput(sentence);

    printf("Reverse is: ");
    char reversed[10000];
    reverseArray(sentence, reversed, length);

    for(char *ptr = reversed; ptr < reversed + length; ptr++) {
        printf("%c", *ptr);
    }
    printf("\n");
}

bool isAlphabet(char c) {
    if (c >= 65 && c <= 90) {
        return true;
    } else if (c >= 97 && c <= 122) {
        return true;
    }
    return false;
}

char lowercased(char input) {
    if (!isAlphabet(input)) {
        return input;
    }
    if (input >= 65 && input <= 90) {
        return input + 32;
    }
    return input;
}

int trimLetters(char *rawSentence, char *trimmedSentence, int rawInputLength) {
    int k = 0;
    for(int i = 0; i < rawInputLength; i++) {
        if (isAlphabet(rawSentence[i])) {
            trimmedSentence[k] = lowercased(rawSentence[i]);
            k++;
        }
    }
    return k;
}

void reverseArray(char *original, char *reversed, int length) {
    for(int i = 0; i < length; i++) {
        reversed[i] = original[length - i - 1];
    }
}

bool isPalindrome() {
    printf("isPalindrome - Enter a Message: ");
    char rawSentence[10000];
    int rawInputLength = readInput(rawSentence);

    char trimmedSentence[10000];
    int trimmedLength = trimLetters(rawSentence, trimmedSentence, rawInputLength);

    char reversed[10000];
    reverseArray(trimmedSentence, reversed, trimmedLength);

    for(int i = 0; i < trimmedLength; i++) {
        if (trimmedSentence[i] != reversed[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {

    reverseInput();

    if (isPalindrome()) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    return 0;
}
