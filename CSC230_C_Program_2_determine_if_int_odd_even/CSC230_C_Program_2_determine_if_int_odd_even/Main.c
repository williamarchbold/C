//Chapter 2 Programming Assignment Question 2.24 from
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016
//"Write a program that reads an integer and determines and prints whether it's odd or even." 
//William Archbold
//6 June 2018

//include standard input/output functions library
#include <stdio.h>
//this allows for the "press any key to continue.." at end of executable
#include <stdlib.h>


//this begins the main function
int main(void) 
{
	
	//declare the variable as an int that the user will asign a value to
	int integer1;

	//prompt the user to enter a value and inform the user what the program will do
	printf("Please enter a whole number and I will determine if it's even or odd for you: ");
	//this function takes the user's input and assigns it to integer1
	scanf("%d", &integer1);


	//this calculates if the input is even and tells the user so
	if (integer1 % 2 == 0 && integer1 > 0 )
	{
		printf("%d is even!\n", integer1);
	}

	//this calculates if the input is odd and tells the user so
	if (integer1 % 2 == 1 && integer1 > 0 ) 
	{
		printf("%d is odd!\n", integer1);
	}
	

	//this if statement will handle input that is less than 0
	if (integer1 < 0)
	{
		//finding the remainder of a negative value divided by 2 doesn't work so created a temp positive value
		int posinteger = integer1 * (-1);
		if (posinteger % 2 == 0)
		{
			printf("%d is even!\n", integer1);
		}
		if (posinteger % 2 == 1)
		{
			printf("%d is odd!\n", integer1);
		}
	}


	//this if statement handles input = to 0 because finding the remainder when dividing by zero doesn't work. 
	if (integer1 == 0)
	{
		printf("%d is even!\n", integer1);
	}


	//allow user ability to exit program
	//system("pause");
}