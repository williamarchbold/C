//William Archbold
//Q 10.10
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

/*"Write a program that right shifts an integer variable 4 bits. The program should print the
	integer in bits before and after the shift operation.Does your program place 0s or 1s in 
	the vacated bits?*/
	


#include <stdio.h>//allows for standard input and ouput

//function prototypes
void printBitwise(unsigned int value);

int main(void) {//main function begins here

	int input; //Declare an int

	printf("%s", "Please input an integer: "); //Prompt the user to enter an int
	scanf("%d", &input); //assing input to int variable

	printBitwise(input); //call packCharacters function

	printBitwise(input >> 4);

	system("pause"); //give user time to review
}

void printBitwise(int value) { //build function here that prints int in binary

	unsigned int displayMask = 1 << 31; //create a display mask that's 10000000 00000000 00000000 00000000

	printf("%10u = ", value); //print the ASCII value of the current character for user to view

	for (unsigned int c = 1; c <= 32; ++c) { //while iterating through each bit in the 32 bit int

		putchar(value & displayMask ? '1' : '0');
		value <<= 1;

		if (c % 8 == 0) { //print a space every 8 bits
			putchar(' ');

		}
	}

}
