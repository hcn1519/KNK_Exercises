//
//  main.c
//  KNK_CH12_PointerAndArray
//
//  Created by 홍창남 on 2020/09/27.
//

#include <stdio.h>

#define N 10
#define NUM_ROW 3
#define NUM_COL 4

void arrayProcessingUsingPointer(void);
void combineAsteriskPlus(void);
void reverseUsingPointer(void);
void pointerAsAArrayName(void);
int findLargest(int a[], int n);
void pointer2DArray(void);
void pointer2DArray2(void);
void access2DArrayRows(int row);
void pass2DArrayRows(int a[], int n);
void accessColumn(void);
void pointerToMultipleElements(void);
void accessColumnWithPointer(void);
void testPointerAndArraySubscrption(void);

int main(int argc, const char * argv[]) {
//    arrayProcessingUsingPointer();
//    combineAsteriskPlus();
//    reverseUsingPointer();
//    pointerAsAArrayName();
//
//    int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int largest = findLargest(a, 10);
//    printf("Largest: %d\n", largest);
//
//    pointer2DArray();
//    pointer2DArray2();
//    access2DArrayRows(0);
//    access2DArrayRows(1);
//    access2DArrayRows(2);
//
//    int sample2D[NUM_ROW][NUM_COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//    pass2DArrayRows(sample2D[0], 4);
//    pass2DArrayRows(sample2D[1], 4);
//    pass2DArrayRows(sample2D[2], 4);
//    accessColumn();
//    pointerToMultipleElements();
    accessColumnWithPointer();
    testPointerAndArraySubscrption();
    return 0;
}

void arrayProcessingUsingPointer() {
    int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = 0, *p;

    for(p = &a[0]; p < &a[N]; p++) {
        sum += *p;
    }
    printf("Sum %d\n", sum);
    int *k = &a[0];
    int tmp = *(k + 10); // Undefined Behavior
    printf("%d\n", tmp);
}

void combineAsteriskPlus() {
    int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = 0, *p;

    p = a;
    while(p < a + N) {
        // Postfix version of ++ takes precedence over *.
        // same as sum += *(p++);
        sum += *p++;
    }
    printf("Sum %d\n", sum);
}

void reverseUsingPointer() {
    int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *p;

    for(p = a + N - 1; p >= a; p--) {
        printf("%d ", *p);
    }
    printf("\n");
}

void pointerAsAArrayName() {
    int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *p = a;
    int sum = 0;

    for(int i = 0; i < N; i++) {
        sum += p[i];
    }
    printf("Sum %d\n", sum);
}

int findLargest(int a[], int n) {
    int max;

    max = a[0];
    for(int i =0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void pointer2DArray() {
    int a[NUM_ROW][NUM_COL];
    int *p;

    for(p = &a[0][0]; p <= &a[NUM_ROW - 1][NUM_COL - 1]; p++) {
        *p = 0;
    }

    for(int i = 0; i < NUM_ROW; i++) {
        for(int j = 0; j < NUM_COL; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void pointer2DArray2() {
    printf("pointer2DArray2\n");

    int a[NUM_ROW][NUM_COL];
    int *p, i = 0;

    int callTime = 0;

    for(p = a[i]; p < a[i] + NUM_COL; p++) {
        *p = 0;
        callTime++;
    }
    printf("CallTime - %d\n", callTime);

    for(int i = 0; i < NUM_ROW; i++) {
        for(int j = 0; j < NUM_COL; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void access2DArrayRows(int row) {
    int a[NUM_ROW][NUM_COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int *p;

    for(p = a[row]; p < a[row] + NUM_COL; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

void pass2DArrayRows(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void accessColumn() {
    int a[NUM_ROW][NUM_COL] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    int (*p)[NUM_COL], k = 0;

    for(int x = 0; x < NUM_ROW; x++) {
        for(int y = 0; y < NUM_COL; y++) {
            printf("%d ", a[x][y]);
        }
        printf("\n");
    }

    for(p = &a[0]; p < &a[NUM_ROW]; p++) {

        for(int i = 0; i < NUM_COL; i++) {
            printf("%d ", *(*(p + k) + i));
        }
        k++;
        printf("\n");
    }
    printf("\n");
}

void pointerToMultipleElements() {
    int arr[] = { 1, 2, 3, 4, 5};
    int *p = arr;
    int (*ptr)[5] = &arr;

    printf("p = %p, ptr = %p\n", p, ptr); // Value of p and ptr are Same.
    printf("p = %d, ptr = %p\n", *p, *ptr);
    printf("sizeof(p) = %lu, sizeof(*p) = %lu\n", sizeof(p), sizeof(*p));
    printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n", sizeof(ptr), sizeof(*ptr));
}

void accessColumnWithPointer() {
    int a[NUM_ROW][NUM_COL] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    int (*ptr)[NUM_COL];

    // Column Based Iteration

    // Using Pointer
    for(int i = 0; i < NUM_COL; i++) {

        for(ptr = &a[0]; ptr < &a[0] + NUM_ROW; ptr++) {
            printf("%d ", *((*ptr) + i));
        }
        printf("\n");
    }

    // Using Subscrption
    for(int i = 0; i < NUM_COL; i++) {
        for(int j = 0; j < NUM_ROW; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }


}

void testPointerAndArraySubscrption() {
    int a[NUM_ROW][NUM_COL] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    int i = 0;
    int j = 2;

    if (a[i] == *(a + i)) {
        printf("true 1, a[i] = %p\n", a[i]);
    }
    if (a[i][j] == (*(a + i))[j]) {
        printf("true 2, a[%d][%d] = %d\n", i, j, a[i][j]);
    }
    if ((*(a + i))[j] == *(*(a + i) + j)) {
        printf("true 3, a[%d][%d] = %d\n", i, j, a[i][j]);
    }

    printf("%d %d", a[i][j], (*(a + i))[j]);
}
