/*
 * File contains enums and things for clarity in programs.
 */

#ifndef _BLACKJACK_H
#define _BLACKJACK_H

// Includes
#include "main.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// Defines
#define DECK_SIZE 52
#define NUM_CARDS 13
#define NUM_SUITS 4
#define MAX_HAND_SIZE 12

#define PLAYER_X 24
#define DEALER_X 24
#define PLAYER_Y 30
#define DEALER_Y 8

// Data structures
typedef enum {
	BJACK_SEAT_PLAYER = 0x00,
	BJACK_SEAT_DEALER = 0x01,
	BJACK_SEAT_DONE = 0x02
} BJACK_SEAT;

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

typedef enum {
	NO_BLACKJACK = 0x00,
	PLAYER_BLACKJACK = 0x01,
	DEALER_BLACKJACK = 0x02,
	BOTH_BLACKJACK = 0x03
} BJACK_BLACKJACK;

typedef enum {
	PLAYER = 0x00,
	DEALER = 0x01,
	PUSH = 0x02
} BJACK_WINNER;

typedef enum {
	BLACKJACK = 0x00,
	BUST = 0x01,
	HIGH_COUNT = 0x02
} BJACK_HOW;

typedef struct {
	CARD_NUM num;
	CARD_SUIT suit;
} BJACK_CARD;

typedef struct {
	BJACK_CARD hand[MAX_HAND_SIZE];
	uint8_t count;
} BJACK_HAND;

typedef struct {
	BJACK_WINNER winner;
	BJACK_HOW how;
} BJACK_RESULT;

typedef struct {
	uint8_t deck_loc;
	BJACK_SEAT seat_turn;
	BJACK_RESULT result;
} BJACK_GAME_STATE;

// Function declarations
uint8_t bjack_count_card_worth(uint8_t cur, BJACK_CARD card);
void bjack_deal_new_hand(BJACK_HAND *player_hand, BJACK_HAND *dealer_hand);
uint8_t bjack_determine_worth(BJACK_HAND hand);
void bjack_game_update(BJACK_HAND *player_hand, BJACK_HAND *dealer_hand, uint8_t select);
void bjack_home(void);
void bjack_init(void);
void bjack_init_deck(void);
BJACK_BLACKJACK bjack_is_blackjack(BJACK_HAND *player_hand, BJACK_HAND *dealer_hand);
void bjack_options(void);
void bjack_rules(void);
void bjack_Screen_new_card(uint8_t x, uint8_t y, BJACK_CARD card);
void bjack_shuffle_deck(void);
void bjack_update_menu(uint8_t select);
void bjack_update_choice(uint8_t select);
void bjack_wait(uint8_t ticks);

// Vars
extern volatile uint8_t bpressed;

extern volatile bool frame_ready;

#endif //BLACKJACK_H
