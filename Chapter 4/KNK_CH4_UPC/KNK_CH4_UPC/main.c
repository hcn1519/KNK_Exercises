//
//  main.c
//  KNK_CH4_UPC
//
//  Created by 홍창남 on 2020/04/17.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

int64_t inputLength(int64_t input) {
    int64_t inputLength = 0;
    while (input > 0) {
        inputLength++;
        input /= 10;
    }
    return inputLength;
}

int64_t sumOfNumber(int64_t digit, int64_t sum) {
    if (digit < 10) {
        return sum + digit;
    }

    sum += (digit % 10);
    digit /= 100;

    return sumOfNumber(digit, sum);
}

int64_t upcCheckDigit(int64_t firstSum, int64_t secondSum) {
    int64_t tempSum = firstSum * 3 + secondSum;
    return tempSum %= 10;
}

int64_t eanCheckDigit(int64_t firstSum, int64_t secondSum) {
    int64_t tempSum = firstSum * 3 + secondSum;
    tempSum -= 1;
    tempSum %= 10;
    tempSum -= 9;
    return tempSum *= -1;
}

int main(int argc, const char * argv[]) {
    int64_t input;
    printf("Enter the digits of a UPC or EAN: ");
    scanf("%lld", &input);


    int64_t first = sumOfNumber(input, 0);
    int64_t secondInput = input / 10;
    int64_t second = sumOfNumber(secondInput, 0);

    printf("firstSum: %lld\n", first);
    printf("secondSum: %lld\n", second);

    if (inputLength(input) == 11) {
        printf("UPC check digit: %lld\n", upcCheckDigit(first, second));
    } else {
        printf("EAN check digit: %lld\n", eanCheckDigit(first, second));
    }

    return 0;
}
