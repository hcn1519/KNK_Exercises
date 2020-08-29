//
//  main.c
//  KNK_CH8_No14
//
//  Created by 홍창남 on 2020/08/30.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#define SIZE 1000

bool isWhiteSpace(char value) {
    return value == ' ';
}

bool isEndOfSentence(char value) {
    const char delimiter[] = { '.', '\n', '?'};
    for(int i = 0; i < 3; i++) {
        if (delimiter[i] == value) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // input: you can cage a swallow can't you?
    // output: you can't swallow a cage can you?
    char sentence[SIZE] = { '\0' };
    printf("Enter a sentence: ");
    fgets(sentence, SIZE, stdin);

    char words[1000][1000] = { '\0' };

    int i = 0;
    int j = 0;
    int k = 0;
    int wordCount = 0;
    char end = '\n';
    while(i < SIZE) {
        if (isWhiteSpace(sentence[i])) {
            j++;
            k = 0;
            wordCount++;
        } else if (isEndOfSentence(sentence[i])) {
            wordCount++;
            end = sentence[i];
            break;
        } else {
            words[j][k] = sentence[i];
            k++;
        }
        i++;
    }

    for(int i = wordCount - 1; i >= 0; i--) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c", words[i][j]);
        }
        if (i != 0) {
            printf(" ");
        }
    }
    printf("%c\n", end);
    return 0;
}
