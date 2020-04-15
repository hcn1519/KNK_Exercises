//
//  main.c
//  KNK_CH4_No3
//
//  Created by 홍창남 on 2020/04/16.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

int inputLength(int input) {
    int inputLength = 0;
    while (input > 0) {
        inputLength++;
        input /= 10;
    }
    return inputLength;
}

int decimal(int inputLength) {
    int result = 1;
    while (inputLength > 1) {
        result *= 10;
        inputLength--;
    }
    return result;
}

int main(int argc, const char * argv[]) {

    int input;

    printf("Enter a number: ");
    scanf("%d", &input);

    int length = inputLength(input);
    int decimalValue = decimal(length);
    int reversal = 0;

    while (length > 0) {
        int current = input % 10;
        reversal += (current * decimalValue);
        length--;
        decimalValue = decimal(length);
        input /= 10;
    }

    printf("The reversal is: %d\n", reversal);

    return 0;
}
