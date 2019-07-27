//William Archbold
//Chapter 13.6 Program Assignment
//July 28 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

/*"Write a program that defines and uses macro MINIMUM2 to determine the smallest of two numeric values. Input the values from keyboard."*/

#include <stdio.h> //allows for standard input/output

#define MINIMUM2(x,y) (x < y ? x : y) //macro that takes x and y as parameters and asks if x is less than why. if yes return x if no return y


int main(int argc, char *argv[]) { //main function begins here that takes an int number of arguments stored in string array argv

	int One, Two; //initilize two vairables
	printf("%s", "Please input two integers with a space in between: "); //prompt user for input
	scanf("%d%d", &One, &Two); //assign users input to the two variables
	puts("\n"); //place space 

	printf("%s %d\n\n",  "The minimum of the two numbers inputted was:", MINIMUM2(One, Two)); //Decide which of two numbers is lower using macro 


	system("pause");//press any key to exit
}