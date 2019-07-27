//William Archbold
//Chapter 10 Program Assignment 10.12
//July 12 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016. 

/*"Write a program that inputs four characters from the keyboard and passes them to function 
	packCharacters. The program should output the characters in their bit format before and after
	they're packed into the unsigned int to prove that the characters are in fact packed correctly
	in the unsigned int variable."*/

#include <stdio.h>

void packCharacters(const char input[]);
void printBitwise(unsigned int value);

int main(void) {

	char string[5];

	printf("%s", "Please input four characters to be converted to bitwise: ");
	scanf_s("%4s", string, 5);

	packCharacters(string);

	system("pause");
}


void packCharacters(const char input[]) {

	unsigned int Value = 0;

	for (size_t i = 0; i < 4; i++)
	{
		unsigned int x = input[i];

		printf("Character \'%c\' in ASCII is ", input[i]);

		printBitwise(x);

		Value <<= 8;

		Value = Value | x;
	}

	printf("After bitwise OR and shifting every character the result is ");
	printBitwise(Value);
}


void printBitwise(unsigned int value) {

	unsigned int displayMask = 1 << 31;

	printf("%10u = ", value);

	for (unsigned int c = 1; c <= 32; ++c) {

		putchar(value & displayMask ? '1' : '0');
		value <<= 1;

		if (c % 8 == 0) {

			putchar(' ');

		}
	}

	puts("\n");
}