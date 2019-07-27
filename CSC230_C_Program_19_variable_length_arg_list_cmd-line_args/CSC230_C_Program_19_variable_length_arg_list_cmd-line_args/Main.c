//William Archbold
//Chapter 14.4 Program Assignment
//Aug 4 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016. 

/*"Write a program that sorts an arrray of integers into ascending or descending order. Use command-line
	arguments to pass either argument -a for ascending order or -d for descending order."*/

#include <stdio.h> //standard input output allowance

//function prototypes
void sort(char * direction, int elements, int * ptr);
void printArray(int elements, int * ptr);


int main(int argc, char * argv[]) { //main function begins here that takes an int number of parameters from command line and stores them in string array argv

	int n, *p; //initilize the int pointer and number of elements to be inputted

	printf("%s", "Enter the number of integers you want to sort: ");
	scanf("%d", &n); //asign user input to int n
	p = (int*)calloc(n, sizeof(int)); //pointer p becomes n indexes each of size int

	puts("\n");

	if (*p = NULL) { //this is if not enough memory could be allocated

		printf("%s", "Memory cannot be allocated.");
	}

	printf("%s", "Enter the non-negative integers you want to be sorted with spaces inbetween and press enter when complete: ");
	for (size_t i = 0; i < n; i++) { //iterate through the user input and assign to the array

		scanf("%d", p + i); //assign input at index i 
	}


	sort(argv[argc-1], n, p); //call sort function


	system("pause"); //prompt user to push any key to exit program
}


void sort(char * direction, int elements, int * ptr) { //sort function takes the command line letter, quantity of numbers to be sorted, and the array of numbers as parameters

	int temp = 0; //temp int to store swapped number

	if (* direction == 'a') { //if sorting direction is ascending

		for (size_t i = 0; i < elements; i++) //this will be the left index to compare following indexed integers with
		{
			for (size_t j = 0; j < elements; j++) //this will be the right index to compare for size
			{
				if (*(ptr + j) > *(ptr + i)) { //if left indexed number is greater than right indexed number

					temp = *(ptr + i); //put right number in temp
					*(ptr + i) = *(ptr + j); //left indexed number becomes smaller number
					*(ptr + j) = temp; //right indexed number becomes larger number
				}
			}
		}
	}
	
	if (* direction == 'd') { //if sorting direction is descending

		for (size_t i = 0; i < elements; i++) //this will be the left indexed number to compare following indexed integers with
		{
			for (size_t j = 0; j < elements; j++) //this will be the right index to compare for size
			{
				if (*(ptr + j) < *(ptr + i)) { //if left indexed number is less than right indexed number

					temp = *(ptr + i); //put right number in temp
					*(ptr + i) = *(ptr + j); //left indexed number becomes larger number
					*(ptr + j) = temp; //right indexed number becomes smaller number
				}
			}
		}
	}

	printArray(elements, ptr); //call print
}


void printArray(int elements, int * ptr) { //print array that takes the number of elements in array and the string array

	printf("%s", "The sorted array is: "); //print to screen

	for (size_t i = 0; i < elements; i++) //while iterating through each index, print index's value to screen
	{

		printf(" %d", *(ptr + i)); //print value
	}

	puts(" \n"); //spaces
}