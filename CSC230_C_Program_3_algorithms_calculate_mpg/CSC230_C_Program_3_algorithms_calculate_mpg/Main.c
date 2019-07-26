//William Archbold
//9 June 2018

//Chapter 3 Programming Assignment 3.16 from
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016

//"Drivers are concerned with the mileage obtained by their automobiles. One drive has kept track 
//of several tankfuls of gasoline by recording miles driven and gallons used for each tankful. The
//program should calculate and display the miles per gallon obtained for each tankful. After processsing 
//all input information, the program should calculate and print the combined miles per gallon obtained 
//for all tankfuls."



#include <stdio.h>
#include <float.h>

//function main beings program execution
int main(void) {

	//Create and initialize variables to zero
	float Miles = 0;
	float totalMiles = 0;
	float Gallons = 0;
	float totalGallons = 0;
	int Trips = 0;


	//prompt for input and assign input to variable Gallons
	printf("%s", "Enter the gallons used (-1 to end): ");
	scanf("%f", &Gallons);

	
	//correct for 0 or <-1 gallons inputted
	while (Gallons == 0 || Gallons < -1)
	{
		printf("%s", "Cant enter 0 or less than negative one gallons. Enter the gallons used (-1 to end): ");
		scanf("%f", &Gallons);
	}


	//loop while sentinel value not yet read from user
	while (Gallons != -1) {

		//prompt for input and assign input to variable Miles
		printf("%s", "Enter the miles driven: ");
		scanf("%f", &Miles);

		
		//correct for 0 or negative miles entered
		while (Miles <=0) {
			printf("%s", "Can't enter 0 or negative miles. Enter the miles driven: ");
			scanf("%f", &Miles);
		}

		//add Miles to totalMiles and add Gallons to TotalGallons and increment Trips
		totalMiles += Miles;
		totalGallons += Gallons;
		Trips++;


		//calculate and display the mpg to the user for that tank
		printf("%s", "The miles/gallon for this tank was ");
		printf("%f \n \n", Miles / Gallons);

		//prompt for input and assign input to variable Gallons
		printf("%s", "Enter the gallons used (-1 to end): ");
		scanf("%f", &Gallons);

		//correct for 0 or <-1 gallons inputted
		while (Gallons == 0 || Gallons < -1)
		{
			printf("%s", "Cant enter 0 or less than negative one gallons. Enter the gallons used (-1 to end): ");
			scanf("%f", &Gallons);
		}
	}

	//if more than zero trips were taken 
	if (Trips != 0) {

		//Calculate and display the average mpg for all trips
		printf("%s", "The overall average miles/gallon was ");
		printf("%f \n \n", totalMiles / totalGallons);
	}

	//if zero trips were taken
	else {
		puts("No trips were taken \n \n");
	}

	//user press any key to escape
	system("pause");

}