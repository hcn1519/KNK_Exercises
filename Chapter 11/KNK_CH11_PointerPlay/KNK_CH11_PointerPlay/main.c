//
//  main.c
//  KNK_CH11_PointerPlay
//
//  Created by 홍창남 on 2020/09/20.
//

#include <stdio.h>

#define N 10

void decompose(double x, long *int_part, double *frac_part);
void scanfEx(void);
void testMaxMin(void);
void max_min(int a[], int n, int *max, int *min);
void testConstPointer(const int *p);
void testPointerAssignment(void);

int main(int argc, const char * argv[]) {

    long i;
    double d;
    long *p = &i;
    double *q = &d;
    decompose(3.141592, &i, &d);
    decompose(3.141592, p, q);
    printf("i: %ld d: %f, *p: %ld, *q: %f\n", i, d, *p, *q);

    scanfEx();
    testMaxMin();
    int constP = 30;
    testConstPointer(&constP);

    testPointerAssignment();
    return 0;
}

void scanfEx() {
    char str [80];
    int i;

    printf("Enter your family name: ");
    scanf("%79s", str);
    printf("Enter your age: ");
    scanf("%d", &i);
    printf("Mr. %s , %d years old.\n", str, i);
    printf("Enter a hexadecimal number: ");
    scanf("%x", &i);
    printf("You have entered %#x (%d).\n", i, i);
}

void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long)x;
    *frac_part = x - *int_part;
}

void testMaxMin() {
    int b[N], max, min;

    printf("Enter %d Numbers: ", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }

    max_min(b, N, &max, &min);

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

}
void max_min(int a[], int n, int *max, int *min) {

    *max = a[0];
    *min = a[0];
    for(int i = 1; i < n; i++) {
        if (a[i] > *max) {
            *max = a[i];
        } else if (a[i] < *min) {
            *min = a[i];
        }
    }
}

// const keyword makes the value immutable, which p points to.
void testConstPointer(const int *p) {
    printf("Before %d\n", *p);
    int newP = *p;
    newP = 20;
    printf("After %d\n", newP);
}

void testPointerAssignment() {
    int i, j, *p, *q;

    i = 1;
    j = 2;
    p = &i;
    q = &j;

    printf("i: %d j %d, *p: %d, *q: %d\n", i, j, *p, *q);

    *q = *p; // j becomes 1, *q becomes 1

    printf("i: %d j %d, *p: %d, *q: %d\n", i, j, *p, *q);
}
