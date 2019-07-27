//William Archbold
//Chapter 8 Programming Assignment Q 8.9
//July 2 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

/*"Write a program that uses function strcmp to compare two strings input by the user. The program
	should state whether the first string is less than, equal to or greater than the second string."*/

#include <stdio.h> //allows for std input output
#include <string.h> //allows for string use

#define SIZE 100 //assume largest string size is 100 char's

int main(void) { //main function begins here

	char string1[SIZE]; //create char array string1
	char string2[SIZE]; //create cahr array string2

	//int play = 1;
	
	//while (play != 2) {
		

		printf("%s", "This program compares the size of two strings that each must be less than 100 characters.\n Please input your first string: "); //prompt user for input
		fgets(string1, SIZE, stdin); //read std input into string1 array that's size SIZE
		puts(""); //newline
		printf("%s", "Please input the second string: "); //prompt user for second string
		fgets(string2, SIZE, stdin); //read std input into string2 array that's size SIZE

		int answer = strcmp(string1, string2); //int answer becomes value of the return of function strcmp with parameters string1 and string2

		switch (answer) { //begin switch to determine result

		case 0:
			printf("%s", "String 1 is the same ASCII size as String 2");
			break;
		case -1:
			printf("%s", "String 1 is less in ASCII size than String 2"); 
			break;
		case 1:
			printf("%s", "String 1 is greater in ASCII size than String 2");
			break;
		default:
			break;
		}

		/*puts("\n");
		printf("%s", "Would you like to compare 2 strings again? Type 1 for yes. 2 for no \n");
		scanf("%d", &play);
		puts("\n");
		*/
	//}


		puts("\n"); //2 linebreak
		system("pause"); //allow user to exit program
}

