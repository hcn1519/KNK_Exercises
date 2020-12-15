//
//  Example7.c
//  KNK_CH11_EX
//
//  Created by 홍창남 on 2020/09/27.
//

#include "Example7.h"

void split_date(int day_of_year, int year, int *month, int *day) {
    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int monthCount = 1;
    for(int i = 0; i < 12; i++) {
        if (day_of_year > months[i]) {
            monthCount++;
            day_of_year -= months[i];
        } else {
            *month = monthCount;
            *day = day_of_year;
            break;
        }
    }
}
