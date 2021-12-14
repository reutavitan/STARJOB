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
typedef enum { With_experience = 1, Without_experience = 2 }Experience; //היה חסר אז הוספתי-שיראל
typedef struct {
	char id[SIZE];
	char companyName[SIZE];
	char name[SIZE];
	Scope  scope;//קליטה של מספר לקובץ
	Area  area;
	Profession profession;
	Experience experience; //היה חסר אז הוספתי
	char description[SIZE];
	char requirements[SIZE];
	bool status;//0-avalabe 1- ananabala
	char candidate1[SIZE2];
	char candidate2[SIZE2];
	char candidate3[SIZE2];
}Job;
int writeFileEmployer(Employer** employer, int size)
{
	int i;
	FILE* fp = fopen("employer.txt", "w");
	for (i = 0; i < size&&; i++)
		fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n", employer[i]->id, employer[i]->password, employer[i]->fullName, employer[i]->phoneNumber, employer[i]->companyName, employer[i]->description, employer[i]->gender);
	fclose(fp);
	return 1;
}
int writeFileCandidate(Candidate** candidate, int size)
{
	int i;
	FILE* fp = fopen("Candidate.txt", "w");
	for (i = 0; i < 2; i++)
		fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", candidate[i]->id, candidate[i]->password, candidate[i]->fullName, candidate[i]->phoneNumber, candidate[i]->education, candidate[i]->workExperience, candidate[i]->gender, candidate[i]->CV);
	fclose(fp);
	return 1;
}
int readFileEmployer(Employer** employer, int size)
{
	int i;
	FILE* fp = fopen("employer.txt", "r");
	for (i = 0; i < size; i++) {
		//x=fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n", employer[i]->fullName, employer[i]->companyName, employer[i]->id, employer[i]->password, employer[i]->phoneNumber, employer[i]->gender);
		fgets(employer[i]->id, SIZE2, fp);
		fgets(employer[i]->password, SIZE2, fp);
		fgets(employer[i]->fullName, SIZE2, fp);
		fgets(employer[i]->phoneNumber, SIZE2, fp);
		fgets(employer[i]->companyName, SIZE2, fp);
		fgets(employer[i]->description, SIZE2, fp);
		fgets(employer[i]->gender, SIZE2, fp);
	}
	fclose(fp);
	for (i = 0; i < 2; i++)
	{
		printf("%s%s%s%s%s%s%s", employer[i]->id, employer[i]->password, employer[i]->fullName, employer[i]->phoneNumber, employer[i]->companyName, employer[i]->description, employer[i]->gender);
	}

}
int readFileCandidate(Candidate** candidate, int size)
{
	int i;
	FILE* fp = fopen("Candidate.txt", "r");
	for (i = 0; i < 2; i++)
	{ /*x = fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n", candidate[i]->id, candidate[i]->fullName, candidate[i]->password, candidate[i]->phoneNumber, candidate[i]->education, candidate[i]->workExperience, candidate[i]->CV);*/
		fgets(candidate[i]->id, SIZE2, fp);
		fgets(candidate[i]->password, SIZE2, fp);
		fgets(candidate[i]->fullName, SIZE2, fp);
		fgets(candidate[i]->phoneNumber, SIZE2, fp);
		fgets(candidate[i]->education, SIZE2, fp);
		fgets(candidate[i]->workExperience, SIZE2, fp);
		fgets(candidate[i]->gender, SIZE2, fp);
		fgets(candidate[i]->CV, SIZE2, fp);
	}

	fclose(fp);

	for (i = 0; i < 2; i++)
	{
		printf("%s%s%s%s%s%s%s%s", candidate[i]->id, candidate[i]->fullName, candidate[i]->password, candidate[i]->phoneNumber, candidate[i]->education, candidate[i]->workExperience, candidate[i]->gender, candidate[i]->CV);
	}

}
int main() {
	Employer** employer = (Employer**)malloc(2 * sizeof(Employer*));
	Candidate** candidate = (Candidate**)malloc(2 * sizeof(Candidate*));
	int i;

	for (i = 0; i < 2; i++)
	{
		puts("enter all datils\n");
		employer[i] = (Employer*)malloc(1 * sizeof(Employer));
		if (!employer[i])
			return 0;
		gets(employer[i]->id);
		gets(employer[i]->password);
		gets(employer[i]->fullName);
		gets(employer[i]->phoneNumber);
		gets(employer[i]->companyName);
		gets(employer[i]->description);
		gets(employer[i]->gender);
	}



	for (i = 0; i < 2; i++)
	{
		puts("enter all datils\n");
		candidate[i] = (Candidate*)malloc(1 * sizeof(Candidate));
		if (!candidate[i])
			return 0;
		gets(candidate[i]->id);
		gets(candidate[i]->password);
		gets(candidate[i]->fullName);
		gets(candidate[i]->phoneNumber);
		gets(candidate[i]->education);
		gets(candidate[i]->workExperience);
		gets(candidate[i]->gender);
		gets(candidate[i]->CV);
		/*x = scanf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", candidate[i]->id, candidate[i]->fullName, candidate[i]->password, candidate[i]->phoneNumber, candidate[i]->education, candidate[i]->workExperience, candidate[i]->CV);*/

	}
	writeFileEmployer(employer, 2);
	readFileEmployer(employer, 2);
	writeFileCandidate(candidate, 2);
	readFileCandidate(candidate, 2);

	/*FILE* fp = fopen("arr.txt", "w");
	for (i = 0; i < 2; i++)
		fprintf(fp, "%s %d %f\n", arr[i]->name, arr[i]->age, arr[i]->price);
	fclose(fp);*/
	/*readFileEmployer(employer, 2);*/

	return 0;

}
 