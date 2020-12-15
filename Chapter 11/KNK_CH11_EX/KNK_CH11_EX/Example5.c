//
//  Example5.c
//  KNK_CH11_EX
//
//  Created by 홍창남 on 2020/09/26.
//

#include "Example5.h"

void split_time(long total_sec, int *hr, int *min, int *sec) {

    long left_sec = total_sec;

    *hr = (int)(total_sec / 3600);
    left_sec -= (*hr * 3600);

    *min = (int)(left_sec / 60);
    left_sec -= (*min * 60);

    *sec = (int)left_sec;
}
