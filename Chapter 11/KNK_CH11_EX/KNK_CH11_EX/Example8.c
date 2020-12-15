//
//  Example8.c
//  KNK_CH11_EX
//
//  Created by 홍창남 on 2020/09/27.
//

#include "Example8.h"

int *find_largest(int n, int a[n]) {

    int *largest = &a[0];
    for(int i = 1; i < n; i++) {
        if (a[i] > *largest) {
            largest = &a[i];
        }
    }
    return largest;
}
