#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
#define SIZE2 500 //for free text
sizeEmployer = 0;
sizeCandidate = 0;
sizeJob = 0;
//typedef enum { employer = 0, candidate = 1 }Gender;
typedef enum { FALSE = 0, TRUE = 1 }Bool;
typedef struct {
	int day, month, year;
}Date;
typedef struct {
	char id[SIZE2];
	char password[SIZE2];
	char fullName[SIZE2];
	char phoneNumber[SIZE2];
	char education[SIZE2];
	char workExperience[SIZE2];
	char gender[SIZE2];
	char CV[SIZE2];//קורות חיים
}Candidate;
typedef struct {
	char id[SIZE2];
	char password[SIZE2];
	char fullName[SIZE2];
	char phoneNumber[SIZE2];
	char companyName[SIZE2];
	char description[SIZE2];
	char gender[SIZE2];
}Employer;
typedef enum { Fulltime = 1, Parttime = 2, Temporaryjob = 3, Motherjob = 4 }Scope;
typedef enum { North = 1, South = 2, Central = 3, Jerusalem = 4 }Area;
typedef enum { Sales = 1, AccountingAndFinance = 2, Logistics = 3, EducationandTraining = 4, HiTech = 5, Securing = 6, Restaurants = 7 }Profession;
typedef struct {
	char id[SIZE];
	char companyName[SIZE];
	char name[SIZE];
	Scope  scope;//קליטה של מספר לקובץ
	Area  area;
	Profession profession;
	char description[SIZE];
	char requirements[SIZE];
	Bool status;//0-avalabe 1- ananabala
	char candidate1[SIZE2];
	char candidate2[SIZE2];
	char candidate3[SIZE2];
}Job;
void jobPosting(Job** job, int size)
{
	int i,index;

	for ( i = 0; i < size; i++)
	{
		if (job[i] == NULL)
		{
			index = i;
			break;
		}

	}
	job[index]->id = index;
	job[index]->candidate1 = '-';
	job[index]->candidate2 = '-';
	job[index]->candidate3 = '-';
	job[index]->status=TRUE;
	editJob(job[index]);

	
}
void editJob(Job * job)
{
	int choice;
	char jobName[SIZE];
	char companyName[SIZE];
	enum scope scope;
	enum positionArea area;
	char jobDescription[SIZE2];
	char requirements[SIZE2];
	enum profession profession;
	do
	{

		//הדפסת פרטי משתמש של שם ת.ז ...
		printf("1. Job name\n 2. Company name\n 3.Scope\n 4.position area\n5.General description of position\n6.Job requirements\n7.Profession\n8.Back to the previous menu\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter job name:\n");
			getchar();
			gets_s(jobName, SIZE);
			//בדיקת תקינות קלט
			strcpy(job->name, jobName);

			break;
		case 2:
			printf("Enter Company name:\n");
			getchar();
			gets_s(companyName, SIZE);
			//בדיקת תקינות קלט
			strcpy(job->companyName, companyName);


			break;
		case 3:
			
			break;
		case 4:
			filterbyrea_5_2_2(job);

			break;
		case 5:
			printf("Enter a description of job :\n");
			getchar();
			gets_s(jobDescription, SIZE2);
			//בדיקת תקינות קלט
			strcpy(job->description, jobDescription);
			break;
		case 6:
			printf("Enter the job requirements :\n");
			getchar();
			gets_s(requirements, SIZE2);
			//בדיקת תקינות קלט
			strcpy(job->requirements, requirements);
			break;

		case 7:
			filterjobsbyprofession_5_2_3(job);
			break;
		case 8:
			return;

		default:
			printf("Error,try again.\n");
			break;

		}


	} while (choice != 8);

}
void filterbyrea_5_2_2(Job* job) //סינון לפי אזור
{
	int choice;
	printf("pls select one of 4 optionals area:\n 1. North\n 2. South\n 3.Central\n 4.Jerusalem\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		job->area = North;
		
		break;
	case 2:
		job->area = South;
		break;
	case 3:
		job->area = Central;
		break;
	case 4:
		job->area = Jerusalem;
		break;
	default:
		printf("invalid choice , try again!");
	}
}


void filterjobsbyprofession_5_2_3(Job* job)
{
	int choice;
	printf("pls select one of 7 optionals proffesion:\n 1. Sales \n 2.Accounting and Finance \n 3.Logistics \n 4.Education and training \n 5.HiTech \n 6.Securing \n7. Restaurants\n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		job->profession = Sales;
		break;
	case 2:
		job->profession = AccountingAndFinance;
		break;
	case 3:
		job->profession = Logistics;
		break;
	case 4:
		job->profession = EducationandTraining;
		break;
	case 5:
		job->profession = HiTech;
		break;
	case 6:
		job->profession = Securing;
		break;
	case 7:
		job->profession = Restaurants;
		break;
	default:
		printf("invalid choice , try again!");
	}
}
