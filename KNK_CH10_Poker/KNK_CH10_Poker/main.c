//
//  main.c
//  KNK_CH10_Poker
//
//  Created by 홍창남 on 2020/09/19.
//  Copyright © 2020 hcn1519. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool royalFlush = false;
bool flush = false;
bool straight = false;
bool four = false;
bool three = false;
int pairs = 0;

void read_cards(int hand[5][2]);
void analyze_hand(int hand[5][2]);
void print_result(void);

/*
 Test Case

 Enter a Card: 2s
 Enter a Card: 5s
 Enter a Card: 4s
 Enter a Card: 3s
 Enter a Card: 6s
 Straight Flush

 Enter a Card: 8c
 Enter a Card: as
 Enter a Card: 8c
 Duplicate card; Ignored.
 Enter a Card: 7c
 Enter a Card: ad
 Enter a Card: 3h
 Pair

 Enter a Card: 6s
 Enter a Card: d2
 Bad Card; Ignored.
 Enter a Card: 2d
 Enter a Card: 9c
 Enter a Card: 4h
 Enter a Card: ts
 High Card

 Enter a Card: 2s
 Enter a Card: 2d
 Enter a Card: 2h
 Enter a Card: 2s
 Duplicate card; Ignored.
 Enter a Card: 2c
 Enter a Card: 3d
 Four of a kind
 */
int main(int argc, const char * argv[]) {
    int hand[NUM_CARDS][2] = { 0 };

    read_cards(hand);
    analyze_hand(hand);
    print_result();
    return 0;
}

void read_cards(int hand[NUM_CARDS][2]) {

    int card_read = 0;
    bool bad_card = false;
    char rank_ch, suit_ch;
    int rank = 0;
    int suit = 0;
    while (card_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a Card: ");
        rank_ch = getchar();
        switch (rank_ch) {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default: bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default: bad_card = true;
        }

        char ch = getchar();
        while(ch != '\n') {
            if (ch != ' ')
                bad_card = true;
        }

        if (bad_card) {
            printf("Bad Card; Ignored.\n");
            continue;
        }
        bool isDuplicate = false;
        for(int i = 0; i < card_read; i++) {
            if (hand[i][0] == rank && hand[i][1] == suit) {
                printf("Duplicate card; Ignored.\n");
                isDuplicate = true;
                break;
            }
        }

        if (bad_card == false && isDuplicate == false) {
            hand[card_read][0] = rank;
            hand[card_read][1] = suit;
            card_read++;
        }
    }
//    debug log
//    for(int i = 0; i < NUM_CARDS; i++) {
//        printf("Hand %d %d\n", hand[i][0], hand[i][1]);
//    }
}

void analyze_hand(int hand[NUM_CARDS][2]) {

    int firstSuit = hand[0][1];
    flush = true;
    for(int i = 1; i < NUM_CARDS; i++) {
        if (hand[i][1] != firstSuit) {
            flush = false;
        }
    }

    if (flush) {
        bool royals[5] = { false };
        for(int i = 0; i < NUM_CARDS; i++) {
            int rank = hand[i][0];
            switch (rank) {
                case 8:
                    royals[0] = true;
                    break;
                case 9:
                    royals[1] = true;
                    break;
                case 10:
                    royals[2] = true;
                    break;
                case 11:
                    royals[3] = true;
                    break;
                case 12:
                    royals[4] = true;
                    break;
                default:
                    break;
            }
        }
        int royalCount = 0;
        for(int i = 0; i < NUM_CARDS; i++) {
            if (royals[i] == true) {
                royalCount++;
            }
        }
        royalFlush = royalCount == NUM_CARDS ? true : false;
    }

    int num_in_rank[NUM_RANKS] = { 0 };
    for(int i = 0; i < NUM_CARDS; i++) {
        int v = hand[i][0];
        num_in_rank[v]++;
    }
    int maxStraight = 0;
    int currentStraight = 0;
    for(int i = 0; i < NUM_RANKS; i++) {
        if (num_in_rank[i] != 0) {
            currentStraight++;
        } else {
            if (currentStraight > maxStraight) {
                maxStraight = currentStraight;
            }
            currentStraight = 0;
        }
    }

    if (currentStraight > maxStraight) {
        maxStraight = currentStraight;
    }

    if (maxStraight == NUM_CARDS) {
        straight = true;
    }

    for(int i = 0; i < NUM_RANKS; i++) {
        if (num_in_rank[i] == 4) {
            four = true;
        } else if (num_in_rank[i] == 3) {
            three = true;
        } else if (num_in_rank[i] == 2) {
            pairs++;
        }
    }
}

void print_result() {
    if (straight && royalFlush) {
        printf("Royal Flush");
    } else if (straight && flush) {
        printf("Straight Flush");
    } else if (four) {
        printf("Four of a kind");
    }  else if (three && pairs == 1) {
        printf("Full house");
    } else if (flush) {
        printf("Flush");
    } else if (straight) {
        printf("Straight");
    } else if (three) {
        printf("Three of a kind");
    } else if (pairs == 2) {
        printf("Two Pairs");
    } else if (pairs == 1) {
        printf("Pair");
    } else {
        printf("High Card");
    }
    printf("\n");
}
