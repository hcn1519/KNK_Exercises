//
//  main.c
//  KNK_CH2_No8
//
//  Created by 홍창남 on 2020/01/05.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    float loan, interestRate, monthPayment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthPayment);

    float montlyInterestRate = (interestRate / 100.0) / 12.0;

    float balance1 = loan - monthPayment  + (montlyInterestRate * loan);
    float balance2 = balance1 - monthPayment + (montlyInterestRate * balance1);
    float balance3 = balance2 - monthPayment + (montlyInterestRate * balance2);

    printf("Balance remaining after first payment: $%.2f\n", balance1);
    printf("Balance remaining after second payment: $%.2f\n", balance2);
    printf("Balance remaining after third payment: $%.2f\n", balance3);

    return 0;
}
