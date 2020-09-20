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

int main(int argc, const char * argv[]) {

    long i;
    double d;

    decompose(3.141592, &i, &d);
    printf("i: %ld, d: %f\n", i, d);

    printf("pointer i: %p\n", &i);

    scanfEx();
    testMaxMin();
    int p = 30;
    testConstPointer(&p);
    return 0;
}

void scanfEx() {
    char str [80];
    int i;

    printf ("Enter your family name: ");
    scanf ("%79s", str);
    printf ("Enter your age: ");
    scanf ("%d", &i);
    printf ("Mr. %s , %d years old.\n", str, i);
    printf ("Enter a hexadecimal number: ");
    scanf ("%x", &i);
    printf ("You have entered %#x (%d).\n", i, i);
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

void testConstPointer(const int *p) {
    printf("Before %d\n", *p);
    int newP = *p;
    newP = 20;
    printf("After %d\n", newP);
}
