#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void EmployerMenu()

{
	int choice;
	do {
		printf("-- - Menu-- - \n 1) Option to go to his profile window\n2) View jobs he posted\n3) Option to advertise a new job\n");
		printf("4) Option to go to the window of deleted jobs history\n5) Filtering option\n6) Sorting option\n");
		printf("000) Option to log out from the system\n");
		scanf("%d", choice)
			switch (choice)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 000:
				break;

			default:
				printf("Error,try again.\n")
				break;
			}
	} while (choice != 000);
}

int main()
{
	EmployerMenu()
}