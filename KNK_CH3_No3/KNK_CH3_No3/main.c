//
//  main.c
//  KNK_CH3_No3
//
//  Created by 홍창남 on 2020/01/12.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int gs1Prefix;
    int groupIdentifier;
    int publisherCode;
    int itemNumber;
    int checkDigit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1Prefix, &groupIdentifier, &publisherCode, &itemNumber, &checkDigit);

    printf("GS1 Prefix: %d\n", gs1Prefix);
    printf("Group Identifier: %d\n", groupIdentifier);
    printf("Publisher Code: %d\n", publisherCode);
    printf("Ttem Number: %d\n", itemNumber);
    printf("Check digit: %d\n", checkDigit);
    return 0;
}
