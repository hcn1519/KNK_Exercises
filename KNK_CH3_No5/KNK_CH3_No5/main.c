//
//  main.c
//  KNK_CH3_No5
//
//  Created by 홍창남 on 2020/01/12.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16;
    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
          &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11, &a12, &a13, &a14, &a15, &a16);

    printf("%2d%3d %2d %2d\n", a1, a2, a3, a4);
    printf("%2d%3d %2d %2d\n", a5, a6, a7, a8);
    printf("%2d%3d %2d %2d\n", a9, a10, a11, a12);
    printf("%2d%3d %2d %2d\n", a13, a14, a15, a16);

    int rowSum1 = a1 + a2 + a3 + a4;
    int rowSum2 = a5 + a6 + a7 + a8;
    int rowSum3 = a9 + a10 + a11 + a12;
    int rowSum4 = a13 + a14 + a15 + a16;

    int colSum1 = a1 + a5 + a9 + a13;
    int colSum2 = a2 + a6 + a10 + a14;
    int colSum3 = a3 + a7 + a11 + a15;
    int colSum4 = a4 + a8 + a12 + a16;

    printf("Row sums: %d %d %d %d\n", rowSum1, rowSum2, rowSum3, rowSum4);
    printf("Col sums: %d %d %d %d\n", colSum1, colSum2, colSum3, colSum4);

    return 0;
}
