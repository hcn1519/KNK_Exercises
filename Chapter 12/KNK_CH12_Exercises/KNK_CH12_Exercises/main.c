//
//  main.c
//  KNK_CH12_Exercises
//
//  Created by changnam hong on 2020/12/22.
//

#include <stdio.h>
#include <stdbool.h>

void validateExercises1() {
    printf("validateExercises1\n");
    int a[] = { 5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];

    printf("Expectation - 14 Result - %d\n", *(p + 3));
    printf("Expectation - 34 Result - %d\n", *(q - 3));
    printf("Expectation - 4 Result - %ld\n", q - p);
    printf("Expectation - 1 Result - %d\n", p < q);
    printf("Expectation - 0 Result - %d\n", *p < *q);
}

void validateExercises2() {
    printf("validateExercises2\n");

    /*
     int *low, *middle, *high;
     middle = (low + high) / 2;

     low + high is not valid expression, since type of low + high is int not int*. And Result is the distance of two pointers.
     If you want to get valid result, calculate middleIndex using two pointers. And use that middleIndex to point elemnt of Array.(&a[middleIndex])
     */
    int a[] = { 5, 15, 34, 54, 14, 2, 52, 72};
    int *low, *middle, *high;

    low = &a[1];
    high = &a[7];

    long middleIndex = high - low;
    middle = &a[middleIndex];
    printf("middleIndex - %ld\n", middleIndex);
    printf("middle - %d\n", *middle);
}

void validateExercises5() {
    printf("validateExercises5\n");
    int a[] = { 5, 15, 34, 54, 14, 2, 52, 72};
    int *p = a;

    printf("Expectation - 0 Result - %d\n", p == a[0]);
    printf("Expectation - 1 Result - %d\n", p == &a[0]);
    printf("Expectation - 1 Result - %d\n", *p == a[0]);
    printf("Expectation - 1 Result - %d\n", p[0] == a[0]);
}

int sum_array(const int *a, int n) {
    printf("validateExercises6\n");
    int sum = 0;

    for(int *ptr = a; ptr < &a[n]; ptr ++) {
        sum += *ptr;
    }
    return sum;
}

bool search(const int a[], int n, int key) {
    printf("validateExercises7\n");

    for(int *ptr = a; ptr < &a[n]; ptr ++) {
        if (key == *ptr) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    validateExercises1();
    validateExercises2();
    validateExercises5();

    int a[] = { 5, 15, 34, 54, 14, 2, 52, 72};
    int result = sum_array(a, 8);
    printf("Result %d\n", result);

    bool shouldTrue = search(a, 8, 54);
    bool sholudFalse = search(a, 8, 11);

    printf("Expectation 1 Result %d\n", shouldTrue);
    printf("Expectation 0 Result %d\n", sholudFalse);
    return 0;
}
