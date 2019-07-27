//William Archbold
//Program Assignment 12.12
//20 July 2018
//C How to Program Eighth Edition by Paul and Harvey Deitel, Pearson Publishing: Hoboken, NJ. 2016. 


#include <stdio.h>
#include <stdlib.h>

struct stackNode { //structure to store letter and pointer to next node
	char letter;
	struct stacknode *nextPtr;
};


typedef struct stackNode StackNode; //synonym for struct stackNode
typedef StackNode *StackNodePtr; //define type for stacknodeptr

								 //prototypes
void push(StackNodePtr *topPtr, char info);
char pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);


int main(void) { //main function begins here

	StackNodePtr stackPtr = NULL; //points to stack top
	char c[256]; //store the string in this



	printf("%s", "Please enter a sentence that the program will print backwards for you): "); //prompt user for input 
	scanf("%256[^\n]s", c);

	int bufferlen = strlen(c,'\n');

	for (int i = 0; i < bufferlen; i++) { //iterate through each character index to put into the stack 
		//if (c[i] == '\n') break;
		push(&stackPtr, c[i]);
	}



	puts("\n");

	printf("%s", "The sentenced reversed is: ");

	while (!isEmpty(stackPtr))
	{
		printf("%c", pop(&stackPtr)); //print the popped character
	}

	puts("\n");
	system("pause");
}

void push(StackNodePtr * topPtr, char info)
{
	StackNodePtr newPtr = malloc(sizeof(StackNode)); //allocate memory the size of Stack Node

	if (newPtr != NULL) {
		newPtr->letter = info; //put the character info into the new node's letter
		newPtr->nextPtr = *topPtr; //point what the new pointer's next pointer points to in same direction as previous top pointer
		*topPtr = newPtr; //point topptr to newptr
	}
	else {
		printf("%c not inserted. No memory available.\n", info); //print this if can't push block
	}
}

char pop(StackNodePtr * topPtr) { //pop a block off of stack



	StackNodePtr tempPtr = *topPtr; //create a temporray pointer to track the top item
	char popCharacter = (*topPtr)->letter; //assign the top block's char to variable popCharacter
	*topPtr = (*topPtr)->nextPtr; //move the top pointer down to next item in stack
	free(tempPtr); //free the previous top item

	return popCharacter; //return the character
}

int isEmpty(StackNodePtr topPtr) { //determines if stack is full

	return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr) { //function prints the stack

	if (isEmpty(currentPtr)) { //print empty if empty
		puts("The sentence is empty. \n");
	}
	else {
		printf("%s", "The sentence was: "); //print if sentence has charcters

		while (currentPtr != NULL) {

			printf("%c --> ", currentPtr->letter); //while moving the current pointer down each block, print each blocks character variable
			currentPtr = currentPtr->nextPtr;
		}

		puts("NULL \n");
	}
}
