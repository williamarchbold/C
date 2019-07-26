#include<stdio.h>

//William Archbold
//June 2018

//Q 4.9 from C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016. 

/*(Sum a Sequence of Integers) Write a program that sums a sequence of integers.
Assume that the first integer read with scanf specifies the number of values remaining to be entered.
Your program should read only one value each time scanf is executed.
A typical input sequence might be 5 100 200 300 400 500*/


int main() {
	
	int numbers = 0;
	int total = 0;
	int input = 0;
	
	printf("%s", "Enter a series of integers that you want summed.\n The first number should be the number of numbers you want summed.\n");
	scanf("%d", &numbers);

	for (int i = 1; i <= numbers; ++i)
	{
		scanf("%d", &input);
		total += input;
	}

	printf("The Sum of the Integers are: %d \n", total);

	system("pause");
}