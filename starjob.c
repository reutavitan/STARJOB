#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
// Shirel Ghanah , ID : 206645103 //
{
	char letter;
	printf("please enter a latinic letter. \n");
	scanf("%c", &letter);

	if ((letter >= 'A') && (letter <= 'Z')) // checking the first term //  
		letter = letter + 32;
	else if ((letter >= 'a') && (letter <= 'z')) // checking the second term // 
		letter = letter - 32;
	else
		letter = letter;

	printf("The n : %c . \n ", letter); // printing //

	return 0;
}

