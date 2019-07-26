//William Archbold
//June 13 2018
//4.11 from C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

//"Write a program that finds the smallest of several integers. Assume that the first value read specifies the number of values remaining."


#include <stdio.h>

//this is the main function of the program
int main(void) {

	//create variable that the user will assign the number of numbers to
	unsigned int Counter = 0;

	//create variable that temporarily stores the next inputted value
	int Input = 0;

	//create a variable that stores the lowest number at that time
	int Lowest = 0;


	//Ask the user how many integers will be inputted
	puts("This program will find the smallest integer from a series of inputted integers.");
	puts("Please input integers one at a time. The first integer must represent the number of integers you plan to enter.");
	
	//assign the input to the variable Counter
	scanf("%u", &Counter);

	//if the number of following numbers to be inputted is not 0
	if (Counter != 0) {
		
		//input the next number
		scanf("%d", &Lowest);
		
		//iterate through every input so long as teh number of inputs is less than the Counter
		for (unsigned int i = 1; i < Counter; ++i) {

			//input the next number
			scanf("%d", &Input);

			
			//decide if next number is lower than the standing lowest number
			if (Input < Lowest) {
				
				//if true than lowest number becomes the last inputted value
				Lowest = Input;
			}

		}
		//print the lowest number
		printf("%s %d\n\n", "The lowest number was ", Lowest);

	}
	//print that no numbers were inputted
	else {
		printf("%s", "No numbers were inputted.\n\n");
	}



	//allow user to exit program
	system("pause");

}