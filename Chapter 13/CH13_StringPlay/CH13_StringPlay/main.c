//
//  main.c
//  CH13_StringPlay
//
//  Created by changnam hong on 2020/12/28.
//

#include <stdio.h>
#include <string.h>

void arrayAndPointer() {
    char date1[] = "June 14";
    char *date2 = "June 14";

    date1[0] = 'P';

    printf("%s\n", date1);
    printf("%s\n", date2);
    puts(date1);
}


void readString() {

    char str[80+1];
//    scanf("%s", str);
//    gets(str);
    const int bufferSize = (sizeof(str) / sizeof(str[0]));
    fgets(str, bufferSize, stdin);
    printf("%s\n", str);
}

int main(int argc, const char * argv[]) {

    arrayAndPointer();
    readString();
    return 0;
}
