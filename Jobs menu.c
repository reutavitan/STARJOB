#include<stdlib.h>
#include<stdio.h>
void jobMenu() 
{
	do
	{
		int choice;
		//הדפסת פרטי משתמש של שם ת.ז ...
		printf("1. Full name\n 2. Email address\n 3.phone number\n 4. company name\n5. general description\n");
		scanf("%d", choice);
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
			break :


		default:
			printf("Error,try again.\n");
			break;
		}


	} while (choice);
}