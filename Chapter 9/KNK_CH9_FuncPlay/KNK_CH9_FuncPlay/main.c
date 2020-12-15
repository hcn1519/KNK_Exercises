//
//  main.c
//  KNK_CH9_FuncPlay
//
//  Created by 홍창남 on 2020/09/06.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int sum_array(int len, int a[len]);
int partition_array(int len, int arr[len], int low, int high);
void print_arr(int len, int arr[len]);
void testPartition(int len, int arr[len]);
double median(double x, double y, double z);

void quickSort(int len, int arr[len], int low, int high) {
    if (low >= high) {
        return;
    }
    int paritition = partition_array(len, arr, low, high);
    /* debug log
    print_arr(len, arr);
    printf("partition - %d\n", paritition);
     */
    quickSort(len, arr, low, paritition - 1);
    quickSort(len, arr, paritition + 1, high);

}

int main(int argc, const char * argv[]) {

    int arr[7] = { 12, 3, 6, 18, 7, 15, 10 };
    int sum = sum_array(7, arr);
    printf("Sum - %d\n", sum);

    testPartition(7, arr);
    int arr2[3] = { 1, 2, 3 };
    testPartition(3, arr2);

    quickSort(7, arr, 0, 6);
    print_arr(7, arr);

    double medianNumber = median(20, 5, 7);
    printf("Median - %f\n", medianNumber);

    return EXIT_SUCCESS;
}

int sum_array(int n, int a[n]) {

    int sum = 0;
    for(int i = 0 ; i<n; i++) {
        sum += a[i];
    }
    return sum;
}

int partition_array(int n, int arr[n], int low, int high) {
    if (n < 1) {
        return 0;
    }

    int partitionElement = arr[low];
    int currentTurn = high;

    while(low != high) {
        if (arr[currentTurn] < partitionElement) {
            arr[low] = arr[currentTurn];
            low++;
            currentTurn = low;
        } else {
            arr[high] = arr[currentTurn];
            high--;
            currentTurn = high;
        }
    }
    arr[low] = partitionElement;
    return low;
}

void print_arr(int n, int arr[n]) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void testPartition(int n, int arr[n]) {
    int low = 0;
    int high = n-1;
    int partitionIndex = partition_array(n, arr, low, high);
    print_arr(n, arr);
    printf("Partitioning Element: %d\nIndex: %d\n", arr[partitionIndex], partitionIndex);

    bool isSuccess = true;
    for(int i=0; i<n; i++) {
        if (i < partitionIndex) {
            if (arr[i] > arr[partitionIndex]) {
                printf("Fail To Test Partition\n");
                isSuccess = false;
                break;
            }
        } else {
            if (arr[i] < arr[partitionIndex]) {
                printf("Fail To Test Partition\n");
                isSuccess = false;
                break;
            }
        }
    }

    if (isSuccess) {
        printf("Success\n");
    }
}

double median(double x, double y, double z) {
    bool xIsGreaterThanY = x >= y;
    bool xIsGreaterThanZ = x >= z;
    bool yIsGreaterThanZ = y >= z;

    double result;
    if (xIsGreaterThanY) {
        if (yIsGreaterThanZ) {
            result = y;
        } else {
            result = z;
        }
    } else {
        if (xIsGreaterThanZ) {
            result = x;
        } else {
            result = z;
        }
    }
    return result;
}
