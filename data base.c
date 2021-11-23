#include <stdio.h>
#include <time.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
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
	//קורות חיים 
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
	Scope  scope;
	Area  area;
	Profession profession;
	char description[SIZE];
	char requirements[SIZE];
}Job;
int main() {
	Candidate** candidateDataBase = (Candidate**)malloc(sizeof(Candidate*) * SIZE);
	Employer** employerDataBase = (Employer**)malloc(sizeof(Employer*) * SIZE);
	Job** jobDataBase = (Job**)malloc(sizeof(Job*) * SIZE);
	Bool fillDefaultCandidateDataBase(Candidate * *candidateDataBase); {

	};
};