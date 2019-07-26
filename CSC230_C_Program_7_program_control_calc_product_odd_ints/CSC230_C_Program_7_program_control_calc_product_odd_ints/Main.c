// Author: Charles Lineback
// Reviewed and Critiqued by William Archbold
// Date: 6/15/2018
// Programming Discussion Exercise 4.13 - (Calculating the Product of Odd Integers) Write a program that calculates and prints the product of the odd integers from 1 to 15.
// C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016. 

#include <stdio.h>

int main() {

	//declare and initialize variables

	int product = 1;

	//loop 15 times

	for (unsigned int counter = 1; counter <= 15; ++counter) {

		//if counter is odd, add counter to sum.

		if (counter % 2 != 0)

			product = product * counter;

	}


	printf_s("The product of the odd integers from 1 to 15 is %d\n", product);

	system("pause");

}