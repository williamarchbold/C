//William Archbold
//Chapter 6 Programming Assignment 6.21
//June 22 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016. 

/*"A small airline purchased a computer for its new reservation system. Write a program to assign seats on each flight 
	of the airline's only plance (capacity: 10 seats). Use a one-dimensional array to represent the seating chart of the plane. When the
	first class section is full, your program should ask the person if it's acceptable to be placed in the economy section."*/




#include <stdio.h> //allow for standard input output

int main(void) { //main function begins here

	int seats[10] = { 0,0,0,0,0,0,0,0,0,0 }; // initialize array to simulate seats on plane. Set all seats to value 0

	unsigned int selection = 0; //initialize variable that will be used as user's seat selection input

	unsigned int seatsOccupied = 0; //initialize variable to keep track of if the plane is full or not

	unsigned int firstOccupied = 0; //keep track of number of first class seats occupied

	unsigned int economyOccupied = 5; //keep track of number economy class seats occupied

	
	while (seatsOccupied <= 9) { //while loop to keep repeating asking the customer if they want a ticket until plane is full

		printf("%s", "Greetings. This plane has a capacity of 10 seats.\n"); //tell user plane capacity
		printf("%s", "Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\n"); //prompt user for input
		scanf("%u", &selection); //assing input to variable selection

		if (selection == 1 && firstOccupied <= 4) { //if statement that will give user a 1st class ticket if not fully occupied

			seats[firstOccupied] = 1;
			firstOccupied++;
			seatsOccupied++;
			printf("%s %u %s", "Boarding Pass: Seat", firstOccupied, "in First Class\n\n");
		}

		if (selection == 2 && economyOccupied <= 9) { //if statement that will give user economy ticket if not fully occupied

			seats[economyOccupied] = 1;
			economyOccupied++;
			seatsOccupied++;
			printf("%s %u %s", "Boarding Pass: Seat", economyOccupied, "in Economy Class\n\n");

		}

		if (selection == 1 && firstOccupied == 5 && economyOccupied <= 9) { //if statement to ask user if they want an economy seat if 1st class full
			//and if there are available economy seats

			printf("%s", "First Class is full. Would you like an Economy seat?\nType 1 for yes. 2 for no.\n");
			scanf("%u", &selection);

			if (selection == 1) { //if selection is yes, give user economy ticket
				
				seats[economyOccupied] = 1;
				economyOccupied++;
				seatsOccupied++;
				printf("%s %u %s", "Boarding Pass: Seat", economyOccupied, "in Economy Class\n\n");
			}

			if (selection == 2) { //if selection is no, tell them next flight in 3 hours

				printf("%s", "Next flight leaves in 3 hours.\n\n");
			}
		}

		if (selection == 2 && economyOccupied == 10 && firstOccupied <= 4) {//if economy is full and 1st class available, ask user if they want 1st class

			printf("%s", "Economy Class is full. Would you like a First Class seat?\nType 1 for yes. 2 for no.\n");
			scanf("%u", &selection);
			
			if (selection == 1) {//if selection is yes, give user 1st class ticket

				seats[firstOccupied] = 1;
				firstOccupied++;
				seatsOccupied++;
				printf("%s %u %s", "Boarding Pass: Seat", firstOccupied, "in First Class\n\n");
			}

			if (selection == 2) { //if selection is no, tell them next flight in 3 hours

				printf("%s", "Next flight leaves in 3 hours.\n\n");
			}

		}

	}

	printf("%s", "This plane is full. Next flight leaves in 3 hours!\n\n");//tell the user that the plane is full so no more seats available

	system("pause");//allow user opportunity to exit program
}