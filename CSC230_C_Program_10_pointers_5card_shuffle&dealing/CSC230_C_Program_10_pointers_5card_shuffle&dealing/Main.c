//William Archbold
// Chapter 7 Programming Assignment 7.12
//June 28 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

/*"Write a program to deal a five-card poker hand. Then determine whether the hand contains a pair, two pairs, 
	three of a kind, four of a kind, a flush, and a straight." */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//prototypes
void shuffle(unsigned int wDeck[][FACES]); //shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[], int hand[5]); //dealing doesn't modify the arrays
int getFace(int card); // get face value of current card
int getSuit(int card); // get suit value of current card
bool hasPair(int hand[5]); //determine if hand has at least one pair of cards
bool hasTwoPairs(int hand[5]); //determine if hand has at least two pairs of cards
bool hasThreeOfAKind(int hand[5]); //determine if hand has three of a kind
bool hasFourOfAKind(int hand[5]); //determine if hand has 4 of a kind
bool hasFlush(int hand[5]); //determine if hand has all cards of same suit
bool hasStraight(int hand[5]); //determine if hand has 5 cards with faces in immediate order



//main function begins here
int main(void) {

	//initialize deck array
	unsigned int deck[SUITS][FACES] = { 0 };
	srand(time(NULL)); //seed random-number generator
	shuffle(deck); //shuffle the deck

	//initialize suit array
	const char *suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	//initialize face array
	const char *face[FACES] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Quenn", "King" };

	//initialize hand array
	int hand[5];


	deal(deck, face, suit, hand); //deal the deck
	printf(hasPair(hand) ? "Has pair\n" : "Doesn't have a pair\n"); //print whether hand has at least one pair
	printf(hasTwoPairs(hand) ? "Has two pair\n" : "Doesn't have two pair\n"); //print whether hand has two pairs
	printf(hasThreeOfAKind(hand) ? "Has three of a kind\n" : "Doesn't have three of a kind\n"); //print whether hand has three of a kind
	printf(hasFourOfAKind(hand) ? "Has four of a kind\n" : "Doesn't have four of a kind\n"); //print whether hand has four of a kind
	printf(hasFlush(hand) ? "Has a flush\n" : "Doesn't have a flush\n"); //print whether hand has a flush
	printf(hasStraight(hand) ? "Has a straight\n" : "Doesn't have a straight\n"); //print whether hand has a straight

	puts("\n");
	system("pause");
}

//shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES]) {

	//for each of the cards, choose slot of deck randomly

	for (size_t card = 1; card <= CARDS; ++card) {
		size_t row; // row number
		size_t column; // column number

		//choose new random location until unoccupied slot found
		do {
			row = rand() % SUITS;
			column = rand() % FACES;
		} while (wDeck[row][column] != 0);
	
		wDeck[row][column] = card; //place card number in chosen slot of deck
		//printf("%d ", card); //this was to ensure we had 52 cards
	}
	printf("\n");
}

//deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[], int hand[5]) {


	/*
	0 1 2    (0,0) (0,1) (0,2)
	3 4 5    (1,0) (1,1) (1,2)
	6 7 8    (2,0) (2,1) (2,2)

	n / 3 = 0, 0, 0, 1, 1, 1, 2, 2, 2
	n % 3 = 0, 1, 2, 0, 1, 2, 0, 1, 2
	*/


	//deal 5 cards from shuffled deck
	for (size_t i = 0; i < 5; ++i) {
		int card = wDeck[i / FACES][i % FACES];
		int suit = (card - 1) / FACES; // divide by faces to get suit row
		int face = (card - 1) % FACES; // remainder when divided by faces to get face column
		hand[i] = card; //hand at index i becomes card value

		printf("%5s of %-8s%c", wFace[face], wSuit[suit], i % 2 == 0 ? '\n' : '\t'); // 2-column format
	}
}


//define function getFace
int getFace(int card) {
	int face = (card - 1) % FACES; // remainder when divided by faces to get face column
	return face;
}

int getSuit(int card) {
	int suit = (card - 1) / FACES; // divide by faces to get suit row
	return suit;
}

bool hasPair(int hand[5]) { //define function hasPair
	/*
	1 : 2, 3, 4, 5
	2 : 3, 4, 5
	3 : 4, 5
	4 : 5
	*/

	for (int a = 0; a < 4; ++a) { //iterate through first 4 cards to compare with next card
		for (int b = a + 1; b < 5; ++b) { //iterate through 4 cards to compare
			int faceA = getFace(hand[a]); //retrieve value of card a
			int faceB = getFace(hand[b]); //retrieve value of card b

			if (faceA == faceB) //if card a equals card b return true
				return true;
		}
	}

	return false; //else return false
}

bool hasTwoPairs(int hand[5]) { //define function hasTwoPairs
	int firstPairA = -1, firstPairB = -1;

	for (int a = 0; a < 4; ++a) { //iterate through to find first pair
		for (int b = a + 1; b < 5; ++b) {
			int faceA = getFace(hand[a]);
			int faceB = getFace(hand[b]);

			
			if (faceA == faceB) { // Found a potential pair
				if (firstPairA == -1) { // First pair found - just store
					firstPairA = a;
					firstPairB = b;
				}
				else { // Second pair found; make sure there's no overlap
					if (a != firstPairA && a != firstPairB
						&& b != firstPairA && b != firstPairB) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool hasThreeOfAKind(int hand[5]) { //define function hasThreeOfAKind
	for (int a = 0; a < 3; ++a) { //iterate first card in 3 card comparison. a can only be first 3 cards in hand
		for (int b = a + 1; b < 4; ++b) { //iterate second card in 3 card comparison. b can only be cards 2-4 in hand
			for (int c = b + 1; c < 5; ++c) { //iterate final card in 3 card comparison. c can only be cards 3-5
				int faceA = getFace(hand[a]);
				int faceB = getFace(hand[b]);
				int faceC = getFace(hand[c]);

				if (faceA == faceB && faceB == faceC) //if all 3 faces are same return true
					return true;
			}
		}
	}
	return false;
}

bool hasFourOfAKind(int hand[5]) { //define function hasFourOfAKind
	for (int a = 0; a < 2; ++a) { //iterate first card in 4 card comparison. a can only be first 2 cards in hand
		for (int b = a + 1; b < 3; ++b) { //iterate second card in 4 card comparison. b can only be card 2 or 3 in hand. 
			for (int c = b + 1; c < 4; ++c) { //iterate third card in 4 card comparison. c can only be card 3 or 4 in hand. 
				for (int d = c + 1; d < 5; ++d) { //iterate fourth card in 4 card comparison. d can only be card 4 or 5 in hand. 
					int faceA = getFace(hand[a]);
					int faceB = getFace(hand[b]);
					int faceC = getFace(hand[c]);
					int faceD = getFace(hand[d]);

					if (faceA == faceB && faceB == faceC && faceC == faceD) //if all 4 faces are same return true
						return true;
				}
			}
		}
	}
	return false;
}

bool hasFlush(int hand[5]) { //define function hasFlush
	int suit = getSuit(hand[0]); //get suit of first card
	for (int i = 1; i < 5; ++i) { //iterate through remaining cards
		if (getSuit(hand[i]) != suit) //find first card with different suit. return false if found else return true
			return false;
	}
	return true;
}

bool hasStraight(int hand[5]) { //define function hasStraight
	int current = -1;  //initialize current card
	for (int n = 0; n < 5; ++n) {  //this loop will iterate after the lowest facevalue card in hand is found
		int lowest = 99; //initialize lowest face value variable to 99 to ensure a lower value is found
		for (int i = 0; i < 5; ++i) {   //loop through cards to find lowest face value
			int face = getFace(hand[i]);

			if (current == -1) { // looking for the first, lowest one
				if (face < lowest)
					lowest = face;
			}
			
			else { // checking next cards
				if (face < lowest && face > current)
					lowest = face;
			}
		}

		//compare current lowest card with the current card. 
		//if the facevalue difference is greater than zero than return false
		if (lowest - current > 1 && current != -1) { 
			return false;
		}

		current = lowest;
	}

	return true;
}