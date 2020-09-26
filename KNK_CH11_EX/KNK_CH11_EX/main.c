//
//  main.c
//  KNK_CH11_EX
//
//  Created by 홍창남 on 2020/09/26.
//

#include <stdio.h>
#include "Example4.h"
#include "Example5.h"

void example4(void);
void example5(void);

int main(int argc, const char * argv[]) {

    example4();
    example5();
    return 0;
}

void example4() {
    int i = 3, j = 4;

    printf("Before Swap i - %d, j - %d\n", i, j);
    swap(&i, &j);
    printf("After Swap i - %d, j - %d\n", i, j);
}

void example5() {
    int expectedH = 3;
    int expectedM = 45;
    int expectedS = 32;
    long total_sec = (3600 * expectedH) + (60 * expectedM) + (expectedS);
    int hour, minute, second;

    split_time(total_sec, &hour, &minute, &second);

    printf("Hour - %d, Minute - %d, Second - %d\n", hour, minute, second);

    if (expectedH == hour && expectedM == minute && expectedS == second) {
        printf("Correct Answer\n");
    }
}
