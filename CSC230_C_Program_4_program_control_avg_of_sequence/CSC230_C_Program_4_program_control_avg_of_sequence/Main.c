//William Archbold
//June 14th 2018
//Chapter 4 Assignment Q 4.10 from
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

//"Write a program that calculates and prints the average of several integers. Assume the last
//value read with scanf is the sentinel 9999."


#include <stdio.h>

int main(void) {

	//create a variable to keep track of the number of inputted numbers
	unsigned int Counter = 0;
	//create a variable to add all inputted numbers to
	int Sum = 0; 
	//create a variable for the user to assign input to
	int Input = 0;

	//prompt the user for input
	puts("Enter a series of integers that you would like to be averaged.");
	puts("Press the Enter key after each inputted value and input 9999 when you're done inputting values.");

	//read first inputted value
	scanf("%d", &Input);

	//use while loop to begin receiving uncertain number of inputs if initial input isn't 9999
	while (Input != 9999) {

		//increment the Counter
		++Counter;
		
		//Sum becomes Sum plus Input
		Sum += Input;

		//Receive the next integer
		scanf("%d", &Input);

	}
	
	//prompt the user for the upcoming average
	printf("%s", "The average is ");

	//Display result if the first input was 9999
	if (Counter == 0) {


		printf("%u\n", Counter);

	}
	//else display Sum divided by Counter
	else {

		printf("%d\n", Sum / Counter);
	}

	//prompt user to enter any key to exit program 
	system("pause");

}