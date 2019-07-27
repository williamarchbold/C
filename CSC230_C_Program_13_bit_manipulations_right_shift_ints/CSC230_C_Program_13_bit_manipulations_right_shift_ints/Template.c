//William Archbold
//Chapter 10 Program Assignment 12.12
//July 12 2018

#include <stdio.h>//allows for standard input and ouput

//function prototypes
void packCharacters(const char input[]);
void printBitwise(unsigned int value);

int main(void) {//main function begins here

	char string[5]; //Declare a character string of size 5 called String

	printf("%s", "Please input four characters to be converted to bitwise: "); //Prompt the user to enter four characters
	scanf_s("%4s", string, 5); //assign those characters to String. Don't take more stdin than 4 char's

	packCharacters(string); //call packCharacters function

	system("pause"); //give user time to review
}


void packCharacters(const char input[]) {//build function here that takes string as paramater

	unsigned int Value = 0; //Declare an unsigned integer called Value and set it equal to zero to store the final result in

	for (size_t i = 0; i < 4; i++) //While iterating through each character
	{
		unsigned int x = input[i]; //Assign the character to an unsigned integer value called x to get the ASCII value

		printf("Character \'%c\' in ASCII is ", input[i]); //print character for user to view

		printBitwise(x); //call function to print in binary

		Value <<= 8; //Shift Value over 8 bits

		Value = Value | x; //Value becomes the Inclusive OR of Value and the current character
	}

	printf("After bitwise OR and shifting every character the result is ");
	printBitwise(Value); //Print the final Value in binary after all 4 iterations
}


void printBitwise(unsigned int value) { //build function here that prints character in binary

	unsigned int displayMask = 1 << 31; //create a display mask that's 10000000 00000000 00000000 00000000

	printf("%10u = ", value); //print the ASCII value of the current character for user to view

	for (unsigned int c = 1; c <= 32; ++c) { //while iterating through each bit in the 32 bit int

		putchar(value & displayMask ? '1' : '0'); //display character that results of Bitwise Inclusive OR'ing
		value <<= 1;

		if (c % 8 == 0) { //print a space every 8 bits

			putchar(' ');

		}
	}

	puts("\n");//2 new lines
}