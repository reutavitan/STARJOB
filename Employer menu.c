#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void EmployerProfile(Employer* employer)
{
	int choice;
	do
	{
		//printDate(employer.birthday);
		printf("%s\n%ld\n%ld\n%s\n%s\n%s\n", employer->name, employer->phoneNumber, employer->id, employer->email, employer->companyName, employer->companyDescription);//חסר הדפסת תאריך לידה
		printf("1. Edit Profile\n0. Back to the previous menu\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			EditProfile(employer);
			break;
		case 0:
			return;

		default:
			printf("Error,try again.\n");
			break;
		}

	} while (choice != 0);
}

void EditProfile(Employer* e)
{
	int choice;
	char name[N];
	//Date birthday;
	long id;
	char email[N];
	char companyName[N];
	char companyDescription[M];
	long phoneNumber;

	do
	{

		//הדפסת פרטי משתמש של שם ת.ז ...
		printf("1. Full name\n 2. Email address\n 3.phone number\n 4. company name\n5. general description\n6.Back to the previous menu");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter your name:\n");
			getchar();
			gets_s(name, N);
			//בדיקת תקינות קלט
			strcpy(e->name, name);

			break;
		case 2:


			break;
		case 3:
			printf("Enter your phone:\n");
			scanf("%ld", &phoneNumber);
			//בדיקת תקינות קלט
			e->phoneNumber = phoneNumber;
			break;
		case 4:
			printf("Enter your name company:\n");
			getchar();
			gets_s(companyName, N);
			//בדיקת תקינות קלט
			strcpy(e->companyName, companyName);
			break;
		case 5:
			printf("Enter a description of your company :\n");
			getchar();
			gets_s(companyDescription, M);
			//בדיקת תקינות קלט
			strcpy(e->companyDescription, companyDescription);
			break;
		case 6:
			return;
		default:
			printf("Error,try again.\n");
			break;
		}


	} while (choice != 6);
}

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