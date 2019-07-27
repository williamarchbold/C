//William Archbold
//Question 11.13 Program Assignment
// July 16 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016. 

/* "Write a program that, given a seven-digit number, writes to a file every possible seven-letter word
	corresponding to that number. There are 2187 (3 to the seventh power) such words. Avoid phone numbers
	that start with digits 0 and 1."*/

#include <stdio.h> //standard input/outpu
#include <string.h> //allows for strings

#define SEVENDIGITS 7 //size of the phone number

void RecursiveDigits(char Word[7], int PhoneNumber[], int Depth, const char * DigitToLetter[10]); //prototype for recursion

void WriteToFile(char Word[]); //prototype to write to file

int main(void)
{

	FILE * OutputFile = fopen("output.txt", "w"); //Wipe the file contents before program begins if already exists
	fclose(OutputFile); //close the file just wiped

	const char * DigitToLetter[10] = { "","", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY" }; // array of pointers to the possible letters for each digit

	int PhoneNunumberArray[SEVENDIGITS]; //initiate the phone number

	int i = 0; //used for counter
	int c; //will be assigend current character input from user

	printf("%s", "This program will write all possible phone pad words from a 7 digit phone number using digits 2-9.\n");
	printf("%s", "Please enter a phone number (no spaces or dashes or 0 or 1): ");
	while ((i < SEVENDIGITS) && (c = getchar()) != '\n') //while counter is less than 7 and it's still possible to get a character...
	{
		PhoneNunumberArray[i++] = c - 48; //index for phone number becomes character - 48 to convert to int value 
	}

	char WordBuffer[SEVENDIGITS]; //this will store the possible words fromt eh number


	RecursiveDigits(WordBuffer, PhoneNunumberArray, 0, DigitToLetter); //call function to crunch all possible numbers 


	system("pause");
}

void RecursiveDigits(char Word[7], int PhoneNumber[], int Depth, const char * DigitToLetter[10]) { //function recursivedigis takes the 4 arguments

	if (Depth >= 7) //do this when iterated through all possible digits
	{
		WriteToFile(Word); //Write Word[] to a file
		return;
	}

	const char * PossibleLetters = DigitToLetter[PhoneNumber[Depth]]; //String Pointer from Array of String Pointers... used depth as index value of phone number as index of which letter to look at

	for (unsigned int CharIndex = 0; CharIndex < strlen(PossibleLetters); ++CharIndex) //this should iterate 3 times. once for each letter in the current pointer
	{
		Word[Depth] = PossibleLetters[CharIndex]; //character at word index of value Depth becomes the character index of the 3 possible letters array
		RecursiveDigits(Word, PhoneNumber, Depth + 1, DigitToLetter); //recursive call but add 1 to depth 
	}
}


void WriteToFile(char Word[]) { //function WriteToFile that takes the word array as parameter

	FILE * OutputFile = fopen("output.txt", "a"); //open using append as not to over-wite the last line written

	for (size_t i = 0; i < SEVENDIGITS; i++) //iterate through all indices of Word
	{
		fputc(Word[i], OutputFile);
	}

	fputc('\r', OutputFile); //Windows carrage return/newline combo is easier to view output in notepad
	fputc('\n', OutputFile);

	fclose(OutputFile); //close file
}