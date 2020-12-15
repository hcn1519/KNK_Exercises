//
//  main.c
//  KNK_CH2_No5
//
//  Created by 홍창남 on 2020/01/05.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

int power(int value, int n) {

    int result = 1;

    for (int i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

int main(int argc, const char * argv[]) {

    int x;
    printf("Input: ");
    scanf("%d", &x);

    int result = 3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2) + 7 * x - 6;
    int result2 = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("%d\n", result);
    printf("%d\n", result2);

    return 0;
}
