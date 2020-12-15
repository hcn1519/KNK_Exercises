//
//  main.c
//  KNK_CH9_No6
//
//  Created by 홍창남 on 2020/09/14.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

int gcd(int a, int b) {
    int tmp;
    if (b > a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    int mod = a % b;

    if (mod == 0) {
        return b;
    } else {
        return gcd(a % b, b);
    }
}

int digit(int n, int k) {
    if (k == 1) {
        return n % 10;
    }
    return digit(n / 10, k - 1);
}

int main(int argc, const char * argv[]) {

    int result1 = digit(829, 3); // 8
    int result2 = digit(829, 2); // 2
    int result3 = digit(829, 1); // 9
    int result4 = digit(829, 4); // 0

    printf("Result1 - %d\n", result1);
    printf("Result2 - %d\n", result2);
    printf("Result3 - %d\n", result3);
    printf("Result4 - %d\n", result4);

    int gcd1 = gcd(12 , 4);
    int gcd2 = gcd(40 , 22);
    int gcd3 = gcd(888 , 220);
    int gcd4 = gcd(121 , 33);

    printf("GCD1 - %d\n", gcd1);
    printf("GCD2 - %d\n", gcd2);
    printf("GCD3 - %d\n", gcd3);
    printf("GCD4 - %d\n", gcd4);
    return 0;
}
