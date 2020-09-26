//
//  main.c
//  KNK_CH11_EX
//
//  Created by 홍창남 on 2020/09/26.
//

#include <stdio.h>
#include "Example4.h"
#include "Example5.h"
#include "Example6.h"

void example4(void);
void example5(void);
void example6(void);

int main(int argc, const char * argv[]) {

    example4();
    example5();
    example6();
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

void example6() {

//    int sample[] = { 3, 1, 5, 4 };
//    int sample2[] = { 1, 2, 3, 4, 5, 6 };
//    int sample3[] = { 6, 5, 4, 3, 2, 1 };
    int sample4[] = { 1, 1, 1, 4, 3, 5, 4, 5 };

    int largest;
    int second_largest;

    find_two_largest(sample4, 8, &largest, &second_largest);
    printf("Largest - %d, Second Largest - %d\n", largest, second_largest);
}
