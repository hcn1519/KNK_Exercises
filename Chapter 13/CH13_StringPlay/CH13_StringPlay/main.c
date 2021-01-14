//
//  main.c
//  CH13_StringPlay
//
//  Created by changnam hong on 2020/12/28.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
//    char *printee = "Hello, World!\n";

    char printee[] = "Hello, World!\n";
    printee[3] = 'q';
    printf(printee);
    return 0;
}
