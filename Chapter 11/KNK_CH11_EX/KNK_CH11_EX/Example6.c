//
//  Example6.c
//  KNK_CH11_EX
//
//  Created by 홍창남 on 2020/09/26.
//

#include "Example6.h"

void find_two_largest(int a[], int n, int *largest, int *second_largest) {

    if (a[0] > a[1]) {
        *largest = a[0];
        *second_largest = a[1];
    } else {
        *largest = a[1];
        *second_largest = a[0];
    }

    for(int i = 2; i< n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        } else {
            if (a[i] > *second_largest) {
                *second_largest = a[i];
            }
        }
    }
}
