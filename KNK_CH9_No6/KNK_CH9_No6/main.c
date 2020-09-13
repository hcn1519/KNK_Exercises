//
//  main.c
//  KNK_CH9_No6
//
//  Created by 홍창남 on 2020/09/14.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

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
    return 0;
}
