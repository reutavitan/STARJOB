#include <stdio.h>
#include <time.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
#define SIZE2 500
typedef enum { employer = 0, candidate = 1 }Gender;
typedef enum { FALSE = 0, TRUE = 1 }Bool;
typedef struct {
	int day, month, year;
}Date;
typedef struct {
	char id[SIZE];
	char password[SIZE];
	char fullName[SIZE];
	char email[SIZE];
	char phoneNumber[SIZE];
	char education[SIZE];
	char workExperience[SIZE];
	//����� ���� 
	Date birthDate;
	Gender gender;
}Candidate;
typedef struct {
	char id[SIZE];
	char password[SIZE];
	char fullName[SIZE];
	char email[SIZE];
	char phoneNumber[SIZE];
	char companyMame[SIZE];
	char description[SIZE];
	Date birthDate;
	Gender gender;
}Employer;
typedef enum { Fulltime = 1, Parttime = 2, Temporaryjob = 3, Motherjob = 4 }Scope;
typedef enum { North = 1, South = 2, Central = 3, Jerusalem = 4 }Area;
typedef enum { Sales = 1, AccountingAndFinance = 2, Logistics = 3, EducationandTraining = 4, HiTech = 5, Securing = 6, Restaurants = 7 }Profession;
typedef struct {
	char id[SIZE];
	char companyName[SIZE];
	char name[SIZE];
	Bool status;
	Scope  scope;
	Area  area;
	Profession profession;
	char description[SIZE];
	char requirements[SIZE];
}Job;



void viewAllJobOfEmployer(Employer* employer, Job** job, int size)
{
	int choise;
	do
	{
		for (int i = 0; i < size; ++i)
		{
			if (job[i]->id == employer->id && job[i]->status == TRUE)
				printJob(job[i]);

		}

		printf("Enter a job ID number to edit a job / delete a job / view job applicants\nPress 0 to return to the main menu\n");
		scanf("%d", &choise);
		if (choise == 0)
			return;
		menuJob(job[choise]);


	} while (choise != 0);


}
int menuJob(Job* job)
{
	int choice;
	do
	{
		printf("1) Option to edit a job\n2) Option to delete a job\n3) List of candidates for the position\n0)back to the job list published by the employer.\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			editJob(job);

			break;
		case 2:
			deleteJob(job);
			break;
		case 3:
			viewListOfCandidatesForThePosition();//����� ��� ����� ������ ����� ������� ������� �������
			break;
		case 0:
			return 0;

		default:
			printf("Error,try again.\n");
			break;
		}

	} while (choice != 0);

}
void viewListOfCandidatesForThePosition()
{

}
void editJob(Job* job)
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

		//����� ���� ����� �� �� �.� ...
		printf("1. Job name\n 2. Company name\n 3.Scope\n 4.position area\n5.General description of position\n6.Job requirements\n7.Profession\n8.Back to the previous menu\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter job name:\n");
			getchar();
			gets_s(jobName, N);
			//����� ������ ���
			strcpy(job->name, jobName);

			break;
		case 2:
			printf("Enter Company name:\n");
			getchar();
			gets_s(companyName, N);
			//����� ������ ���
			strcpy(job->companyName, companyName);


			break;
		case 3:
			//	Scope-����� �������� ����� ����� �� ���� ����
			break;
		case 4:
			//Area 

			break;
		case 5:
			printf("Enter a description of job :\n");
			getchar();
			gets_s(jobDescription, M);
			//����� ������ ���
			strcpy(job->description, jobDescription);
			break;
		case 6:
			printf("Enter the job requirements :\n");
			getchar();
			gets_s(requirements, M);
			//����� ������ ���
			strcpy(job->requirements, requirements);
			break;

		case 7:
			//����, �����
			break;
		case 8:
			return;

		default:
			printf("Error,try again.\n");
			break;

		}


	} while (choice != 8);

}
void deleteJob(Job* job)
{
	if (job->status)
	{
		job->status = FALSE;
		printf("The job was deleted.\n");
	}
}
void printJob(Job* job)
{
	//����� �� ����� �������??
	printf("The name of job:\n%s\nCompany Name:\n%s\nDescription of the company:\n%s\nRequirements:\n%s\nArea:\n%", job->name, job->companyName, job->description, job->requirements, job->area, job->profession, job->scope, job->id);
}
int main() {
	Candidate** candidateDataBase = (Candidate**)malloc(sizeof(Candidate*) * SIZE);
	Employer** employerDataBase = (Employer**)malloc(sizeof(Employer*) * SIZE);
	Job** jobDataBase = (Job**)malloc(sizeof(Job*) * SIZE);
	Bool fillDefaultCandidateDataBase(Candidate * *candidateDataBase); {

	};
};