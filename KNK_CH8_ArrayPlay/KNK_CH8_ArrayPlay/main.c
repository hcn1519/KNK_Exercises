//
//  main.c
//  KNK_CH8_ArrayPlay
//
//  Created by 홍창남 on 2020/08/28.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

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
    int arr[3][4] = {[0][0] = 10, [0][2] = 45, [2][3] = 24};

    int row = sizeof(arr) / sizeof(arr[0]);
    int column = sizeof(arr[0]) / sizeof(arr[0][0]);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("[%d, %d] - %d\n", i, j, arr[i][j]);
        }
    }
}
int main(int argc, const char * argv[]) {

    oneDimensionalArray();
    printInterest(6, 5);
    twoDimensionalArray();
    return 0;
}
