//
//  main.c
//  KNK_CH7_TypePlay
//
//  Created by 홍창남 on 2020/05/19.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {

    // Numeric Escape Sequence

    // oct
    char smallA = '\141';
    // hex
    char capitalA = '\x41';

    printf("%c\n", smallA);
    printf("%c\n", capitalA);

    char c = '\x0a';

    printf("abc \n def \n");
    printf("abc %c def %c\n", c, c);

    // upperCase, lowerCase
    char letterA = 'a';

    printf("%c\n", toupper(letterA));
    printf("%c\n", tolower(letterA));

    char myChar;

    myChar = 10000;
    return 0;
}
