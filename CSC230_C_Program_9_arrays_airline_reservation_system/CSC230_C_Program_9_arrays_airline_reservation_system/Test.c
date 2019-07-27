#include <stdio.h>

int main(void) {

	int a = 5; 

	int b = 6;

	const *aptr = &a;

	printf("%s %d", "aptr pointing to a = ", aptr);


	system("pause");
}