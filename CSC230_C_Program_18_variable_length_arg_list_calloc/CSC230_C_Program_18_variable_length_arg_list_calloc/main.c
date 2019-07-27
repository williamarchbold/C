//William Archbold
//Q 14.2
//29 Jul 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016. 

/*"Write a program taht calculates the product of a series of integers that are passed to function product
	using a variable-length argument list."*/


#include <stdio.h> //for standard input output
#include <stdlib.h> //for calloc and realloc

void product(int * ptr, int elements); //function prototype that will take the int array and number of elements

int main(void) {

	int n, *p; //initilize the int pointer and number of elements to be inputted

	printf("%s", "Enter the number of integers you want to find the product of: ");
	scanf("%d", &n); //asign user input to int n
	p = (int*) calloc(n, sizeof(int)); //pointer p becomes n indexes each of size int

	puts("\n");
	
	if (*p = NULL) { //this is if not enough memory could be allocated

		printf("%s", "Memory cannot be allocated.");
	}

	printf("%s", "Enter the integers you want the product of with spaces inbetween and press enter when complete: ");
	for (size_t i = 0; i < n; i++) { //iterate through the user input and assign to the array

		scanf("%d", p + i); //assign input at index i 
	}

	product(p, n); //call function with parameters array and number of elements in array

	puts("\n");

	int play = 1;

	while (play == 1) { //while user wants to play

		printf("%s", "Would you like to find the product of other numbers? Enter 1 for yes. 2 for no: ");
		scanf("%d", &play);
		
		if (play == 2) {

			break; //leave the while loop 
		}

		printf("%s", "Enter the number of integers you want to find the product of: ");
		scanf("%d", &n); //reasign value to n
		p = realloc(p, n); //reallocated space and # of elements in array based on new n value

		puts("");

		printf("%s", "Enter the integers you want the product of with spaces inbetween and press enter when complete: ");
		for (size_t i = 0; i < n; i++) {

			scanf("%d", p + i);
		}

		puts("");
		product(p, n);
		puts("\n");


	}

	system("pause");
}

void product(int * ptr, int elements) //function that takes parameters int pointer and the number of indexes with that int pointer
{
	int product = 1;
	
	for (size_t i = 0; i < elements; i++) {

		product *= *(ptr + i); //product becomes itself times the value at array index i
	}

	printf("%s %d", "The product of those numbers is ", product);
}
