/*
 * File contains enums and things for clarity in programs.
 */

#ifndef _BLACKJACK_H
#define _BLACKJACK_H

#include <stdint.h>

typedef enum {
	CARD_SUIT_CLUBS = 0x00,
	CARD_SUIT_DIAMONDS = 0x01,
	CARD_SUIT_HEARTS = 0x02,
	CARD_SUIT_SPADES = 0x03
} CARD_SUIT;

typedef enum {
	CARD_NUM_ACE = 0x00,
	CARD_NUM_TWO = 0x01,
	CARD_NUM_THREE = 0x02,
	CARD_NUM_FOUR = 0x03,
	CARD_NUM_FIVE = 0x04,
	CARD_NUM_SIX = 0x05,
	CARD_NUM_SEVEN = 0x06,
	CARD_NUM_EIGHT = 0x07,
	CARD_NUM_NINE = 0x08,
	CARD_NUM_TEN = 0x09,
	CARD_NUM_JACK = 0x0A,
	CARD_NUM_QUEEN = 0x0B,
	CARD_NUM_KING = 0x0C
} CARD_NUM;

typedef struct {
	CARD_NUM num;
	CARD_SUIT suit;
} CARD;

typedef struct {
	uint8_t deck_loc;

} GAME_STATE;

#endif //BLACKJACK_H
