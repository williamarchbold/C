//William Archbold
//Chapter 9 Program Assignment
//Question 9.10
//July 6 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

/*"Write a program that converts integer Fahrenheit temperatures from 0 to 212 degrees to floating-
	point Celsius temperatures with 3 digits of precision. The output should be printed in two 
	right-justified columns of 10 characters each, and the Celsius temperatures should be 
	preceded by a sign for both positive and negative values."*/

#include <stdio.h>

int main(void) {

	unsigned int play = 1; //this variable will be used to allow users to make multiple entries
	int Fahrenheit = 0; //declare and set variable Fahrenheit to 0
	double Celsius = 0; //declare double Celsius and set to 0
	
	while (play != 2) {//allows for repeated entries
		

		printf_s("%s", "This program converts temperatures fromFahrenheit to Celsius.\n"); //prompt user for input
		printf_s("%s", "Please input a temperature in Fahrenheit between 0 and 212 degrees: "); //promput user for input
		scanf_s("%d", &Fahrenheit); //assign input to variable

		while (Fahrenheit < 0 || Fahrenheit > 212) { //catch if user inputted something outside of 0 and 212

			printf_s("%s", "Did not input value between 0 and 212.\n");
			printf_s("%s", "Please input a temperature in Fahrenheit between 0 and 212 degrees: ");
			scanf_s("%d", &Fahrenheit);
		}

		Celsius = 5.0 / 9.0 * (Fahrenheit - 32); //convert fahrenheit to celsius

		puts("\n1234567890123456789012345678901234567890\n"); //print the column numbers for eaasy reference of lower columns

		printf_s("%10s%10s\n", "Fahrenheit", "Celsius"); //declare which values go to which columns
		printf_s("%10d%+10.3f\n\n", Fahrenheit, Celsius); //print the fahrenheit and celsius values right justified 10 columns out

		printf_s("Would you like to convert another number?\n"); //prompt user to input another number
		printf_s("Type 1 for yes. 2 for no: ");
		scanf_s("%u", &play); //assign decision to varaible play
		puts("\n\n");

	}
	system("pause");
}