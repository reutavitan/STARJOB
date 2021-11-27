#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>
#include <time.h>
enum = { true = 0,false = 1 }flag;
flag phonenum_input_validity(int phonenum) 
{

}
flag education_input_validity(char* education)
{
	int len = strlen(education);
	if (len>500)
	{
		return 1;
    }
	return 0;
}
flag exeperience_input_validity(char* exeperience)
{
	int len = strlen(exeperience);
	if (len > 500)
	{
		return 1;
	}
	return 0;
}
void main_candidate_menu() 
{
	do
	{

		printf(" To  Profile press '1' \n To  Jobs History press '2' \n To  View jobs press '3' \n  To Loging out press '4' \n ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			candidate_profile(candidate);
			break;
		case 2:
			//היסטוריה
			break;
		case 3:
			//משרות
			break;
		case 4:
			//יציאה
			break;
		 default:
			printf("Error,try again.\n");
			break;
		}

	} while (choice != 0);
}
void candidate_profile(Candidate* candidate)
{
	int choice;
	do
	{
		 
		printf("%s\n%ld\n%ld\n%s\n%s\n%s\n", candidate->name,   candidate->id ,candidate->phoneNumber, candidate->email, candidate->education, candidate->workexperience);//חסר הדפסת תאריך לידה
		printf(" To Edit Profile press '1' \n  To Back to the previous menu press '2' \n ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			menu_edit_c_profile(candidate);
			break;
		case 2:
			return;

		default:
			printf("Error,try again.\n");
			break;
		}

	} while (choice != 0);
}

void menu_edit_c_profile(Candidate* c)
{
	int choice;
	char name[N];
	int id;
	char email[N];
	char education[M];
	char workexperience[M];
	int phoneNumber;
	enum = { true = 0,false = 1 }flag;

	do
	{

		 
		printf("The editable fields for a candidate are:\n'1' Full name\n'2' Email address\n'3' cell phone number\n'4' Education\n'5' Work experience\n'6' Resume\n ‘0’ - Back to the previous menu - the profile menu");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter your name:\n");
			getchar();
			gets_s(name, N);
			while (//תקינות שם =0)
			{
			   printf("Normal input contains only 3-20 letters\n");
			   printf("Enter your name\n");
			   getchar();
			   gets_s(name, N);
		    }
			printf("To update press '0' To not change press '1'\n");
			scanf("%s",  flag);
			if (flag == 0)
			{
		      strcpy(c->name, name);
			  printf("The name has been updated\n");
			  break;
			}
			if (flag == 1)
			{
				break;
			}
		case 2:
			printf("Enter your email address:\n");
			getchar();
			gets_s(email, N);
			while (//תקינות  איימיל =0)
				{
				   printf("The email address is incorrect\n");
				   printf("Enter your email address:\n");
				   getchar();
				   gets_s(email, N);
				}
			printf("To update press '0' To not change press '1'\n");
			scanf("%s", flag);
			if (flag == 0)
			{
				strcpy(c->email, email);
				printf("The email has been updated\n");
				break;
			}
			if (flag == 1)
			{
				break;
			}
		case 3:
			printf("Enter your phone number:\n");
			scanf("%ld", &phoneNumber);
			while (//תקינות פלאפון =0)
				{
				   printf("The phone number is incorrect\n");
				   printf("Enter your phone number:\n");
				   scanf("%ld", &phoneNumber);
				   
				}
			printf("To update press '0' To not change press '1'\n");
			scanf("%s", flag);
			if (flag == 0)
			{
				c->phoneNumber = phoneNumber;
				printf("The phone number has been updated\n");
				break;
			}
			if (flag == 1)
			{
				break;
			}
		case 4:
			printf("Enter your education:\n");
			getchar();
			gets_s(education, M);
			while (education_input_validity(education)==1)
				{
				   printf("Normal input contains only 0-500 letters\n");
				   printf("Enter your education\n");
				   getchar();
				   gets_s(education, M);
				}
			printf("To update press '0' To not change press '1'\n");
			scanf("%s", flag);
			if (flag == 0)
			{
				strcpy(c->education, education);
				printf("The education has been updated\n");
				break;
			}
			if (flag == 1)
			{
				break;
			}
		case 5:workexperience
			printf("Enter your work experience:\n");
			getchar();
			gets_s(workexperience, M);
			while (exeperience_input_validity(workexperience)==1)
				{
				   printf("Normal input contains only 0-500 letters\n");
				   printf("Enter your work experience\n");
				   getchar();
				   gets_s(workexperience, M);
				}
			printf("To update press '0' To not change press '1'\n");
			scanf("%s", flag);
			if (flag == 0)
			{
				strcpy(c->workexperience, workexperience);
				printf("The education has been updated\n");
				break;
			}
			if (flag == 1)
			{
				break;
			}
		case 6:
			//Resume
			return;
		default:
			printf("Error,try again.\n");
			break;
		}


	} while (choice != 6);
}
