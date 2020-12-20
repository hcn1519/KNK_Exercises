//
//  main.c
//  KNK_CH8_ArrayPlay
//
//  Created by 홍창남 on 2020/08/28.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define SIZE (int) (sizeof(c) / sizeof(c[0]))

double nextRate(double current, double rate) {
    return current + (current * rate / 100);
}

void printInterest(int rate, int years) {
    double rates[5];

    for(int x = 0; x < years; x++) {
        for(int i = 0; i < 5; i++) {

            double currentRate;
            if (x == 0) {
                currentRate = 100;
            } else {
                currentRate = rates[i];
            }
            rates[i] = nextRate(currentRate, (double)(rate + i));
        }
        printf("%d %3.2f %3.2f %3.2f %3.2f %3.2f\n", x + 1, rates[0], rates[1], rates[2], rates[3], rates[4]);
    }
}

void oneDimensionalArray() {
    int a[] = {1, 2, 3, 4, 5};
    int b[30] = {0};
    int c[] = { [5] = 3, [23] = 4, [11] = 5};

    for(int i = 0; i < 100; i++) {
        printf("%d %d\n", i, b[i]);
    }
    printf("%lu\n", sizeof(a));

    for(int i = 0; i < SIZE; i++) {
        printf("%d %d\n", i, c[i]);
    }
}

void twoDimensionalArray() {
    const int arr[3][4] = {[0][0] = 10, [0][2] = 45, [2][3] = 24};

    int row = sizeof(arr) / sizeof(arr[0]);
    int column = sizeof(arr[0]) / sizeof(arr[0][0]);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("[%d, %d] - %d\n", i, j, arr[i][j]);
        }
    }
}

void dealingAHandOfCards(int numberOfCard) {
    const char suit_code[] = { 'c', 'h', 'd', 's'};
    const char rank_code[] = { '2', '3', '4', '5', '6', '7', '8', '9','t', 'j', 'q', 'k', 'a' };

    const int number_of_suits = sizeof(suit_code);
    const int number_of_ranks = sizeof(rank_code);

    bool in_hand[number_of_suits][number_of_ranks] = { false };

    // prevent picking same cards
    srand((unsigned)time(NULL));

    while(numberOfCard > 0) {
        int suit = rand() % number_of_suits;
        int rank = rand() % number_of_ranks;

        if (!in_hand[suit][rank]) {
            numberOfCard--;
            in_hand[suit][rank] = true;
            printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");
}

void copyArray() {
    const char suit_code[] = { 'c', 'h', 'd', 's'};
    char copied[4];

    memcpy(copied, suit_code, sizeof(suit_code));

    for(int i = 0; i < sizeof(suit_code); i++) {
        printf(" %c", copied[i]);
    }
    printf("\n");
}

void threeDimentionalArray() {

    int a[3][4][5] = {
        {
            { 1, 2, 3, 4, 49 },
            { 5, 6, 7, 8, 50 },
            { 9, 10, 11, 12, 51 },
            { 13, 14, 15, 16, 52 },
        },
        {
            { 17, 18, 19, 20, 53 },
            { 21, 22, 23, 24, 54 },
            { 25, 26, 27, 28, 55 },
            { 29, 30, 31, 32, 56 },
        },
        {
            { 33, 34, 35, 36, 57 },
            { 37, 38, 39, 40, 58 },
            { 41, 42, 43, 44, 59 },
            { 45, 46, 47, 48, 60 },
        }

    };

    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 4; y++) {
            for(int z = 0; z < 5; z++) {
                printf("%d ", a[x][y][z]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {

    oneDimensionalArray();
    printInterest(6, 5);
    twoDimensionalArray();
    dealingAHandOfCards(5);
    copyArray();
    threeDimentionalArray();
    return 0;
}
