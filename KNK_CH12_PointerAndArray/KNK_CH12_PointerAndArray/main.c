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
void pointer2DArray(void);
void access2DArrayRows(int row);

int main(int argc, const char * argv[]) {
    arrayProcessingUsingPointer();
    combineAsteriskPlus();
    reverseUsingPointer();
    pointerAsAArrayName();
    pointer2DArray();
    access2DArrayRows(0);
    access2DArrayRows(1);
    access2DArrayRows(2);
    return 0;
}

void arrayProcessingUsingPointer() {
    int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = 0, *p;

    for(p = &a[0]; p < &a[N]; p++) {
        sum += *p;
    }
    printf("Sum %d\n", sum);
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

void access2DArrayRows(int row) {
    int a[NUM_ROW][NUM_COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int *p;

    for(p = a[row]; p < a[row] + NUM_COL; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}
