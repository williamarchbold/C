//William Archbold
//June 18 2018
//Chapter 5 Programming Assignment 5.11 from 
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

/*"Function floor may be used to round a number to a specific decimal place. Write a program that defines
	four functions to round a number x in various ways:
	a) roundToInteger(number)
	b) roundToTenths(number)
	c) roundToHundredths(number)
	d) roundToThousandths(number)"*/


#include <stdio.h> //used for standard input output
#include <stdlib.h> //used for standard library
#include <math.h> //used for floor function


int roundToInteger(float x); //function prototype
float roundToTenths(float x); //function prototype
float roundToHundreths(float x); //function prototype
float roundToThousandths(float x); //function prototype


//main function begins here
int main(void) {

	float Input = 0; //Declare float Input and set to zero

	
	printf("%s", "Input a number: "); //prompt user to input a number 
	scanf("%f", &Input); //assign value to Input

	
	printf("%s %f\n", "The inputted number was ", Input);//print the inputted number
	printf("%s %d\n", "Rounded to nearest integer is ", roundToInteger(Input));//print to nearest integer
	printf("%s %.1f\n", "Rounded to nearest tenths is ", roundToTenths(Input));//print to nearest tenths
	printf("%s %.2f\n", "Rounded to nearest hundreths is ", roundToHundreths(Input));//print to nearest hundreths
	printf("%s %.3f\n", "Rounded to nearest thousandths is ", roundToThousandths(Input));//print to nearest thousandths


	system("pause");//user presses any key to exit program
}


//definition of roundToInteger function
int roundToInteger(float x) {

	int y = 0; //declare integer value that will be returned

	y = floor(x + .5);

	return y; //return integer to function main
}


//definition of roundToTenths function
float roundToTenths(float x) {

	float y = 0; //declare float value that will be returned

	y = floor(x * 10 + .5) / 10; //float y becomes the value of floor function divided by 10

	return y; //return float to function main
}


//definition of roundToHundreths function
float roundToHundreths(float x) {

	float y = 0; //declare float value that will be returned

	y = floor(x * 100 + .5) / 100; //float y becomes the value of floor function divided by 100

	return y; //return float to function main
}


//definition of roundToThousandths function
float roundToThousandths(float x) {

	float y = 0; //declare float value that will be returned

	y = floor(x * 1000 + .5) / 1000; //float y becomes the value of floor function divided by 1000

	return y; //return float to function main
}
