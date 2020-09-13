//
//  main.c
//  KNK_CH9_No13
//
//  Created by 홍창남 on 2020/09/14.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdio.h>

int evaluate_position(char board[8][8]) {

    int white = 0;
    int black = 0;

    const char whiteLetters[6] = { 'K', 'Q', 'R', 'B', 'N', 'P'};
    const char blackLetters[6] = { 'k', 'q', 'r', 'b', 'n', 'p'};
    int scores[6] = { 11, 9, 5, 3, 3, 1};

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {

            char value = board[i][j];
            for(int k = 0; k < 6; k++) {
                if (value == whiteLetters[k]) {
                    white += scores[k];
                }
            }

            for(int k = 0; k < 6; k++) {
                if (value == blackLetters[k]) {
                    black += scores[k];
                }
            }
        }
    }

    return white - black;
}

int main(int argc, const char * argv[]) {

    char board[8][8] = { [0][0] = 'K',
        [0][1] = 'k',
        [0][2] = 'Q',
        [0][3] = 'R',
        [0][4] = 'B',
        [0][5] = 'N',
        [6][0] = 'r',
        [6][1] = 'b',
        [6][2] = 'n',
    };

    int result = evaluate_position(board);

    printf("%d\n", result);
    return 0;
}
