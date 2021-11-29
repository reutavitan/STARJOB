#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
//////////////////////
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
/////////////////////

Bool id_input_validity(char id[]);
Bool IsDigit(char c);
Bool IsLetter(char c);
Bool passpword_input_validity(char password[]);
Bool fulname_input_validity(char fulname[]);
Bool jobname_input_validity(char jobname[]);
Bool IdInSystem(char id[], Candidate** candidateDataBase);
void exist_user_menu(Candidate** candidateDataBase);
void new_user_menu(Candidate** candidateDataBase);
void user_main_menu(Candidate** candidateDataBase);
int main() {
	char name[] = "3uz";
	/// <summary>
	/// 	
	Candidate** candidateDataBase = (Candidate**)malloc(sizeof(Candidate*) * SIZE);
	Employer** employerDataBase = (Employer**)malloc(sizeof(Employer*) * SIZE);
	Job** jobDataBase = (Job**)malloc(sizeof(Job*) * SIZE);
	Bool fillDefaultCandidateDataBase(Candidate * *candidateDataBase); {

	};
	/// </summary>
	/// <returns></returns>
	return 0;
}
Bool IsDigit(char c) {

	if (c < '0' || c>'9')
		return FALSE;
	return TRUE;
}
Bool IsLetter(char c) {

	if (c < 'A' || c>'z' || c < 'Z' && c>'a')
		return FALSE;
	return TRUE;
}
Bool id_input_validity(char id[]) {
	int i, len;
	len = strlen(id);
	printf(" len: %d\n", len);
	if (len != 9)
		return FALSE;
	for (i = 0; i < len; i++)
		if (IsDigit(id[i]) == FALSE)
			return FALSE;
	return TRUE;
}
Bool passpword_input_validity(char password[]) {
	int i, len = strlen(password);
	if (len < 6 || len>20)
		return 0;
	for (i = 0; i < len; i++)
	{
		if (IsDigit(password[i]) == FALSE && IsLetter(password[i] == FALSE))
			return FALSE;
	}
	return TRUE;
}
Bool fulname_input_validity(char fulname[]) {
	int i;
	int len = strlen(fulname);
	if (len < 3 || len>20)
		return FALSE;
	for (i = 0; i < len; i++)
	{
		if (IsLetter(fulname[i]) == FALSE && fulname[i] != ' ')
			return FALSE;
	}
	return TRUE;
}
Bool jobname_input_validity(char jobname[]) {
	int i;
	int len = strlen(jobname);
	if (len < 1 || len>20)
		return FALSE;

	return TRUE;
}
Bool IdInSystem(char id[], Candidate** candidateDataBase) {
	//בדיקה אם ת"ז קיימת במערכת
	int i;
	for (i = 0; i < SIZE && candidateDataBase[i] != NULL; i++)
	{
		if (strcmp(candidateDataBase[i]->id, id) == 0) {
			return TRUE;
		}
	}
	return FALSE;
}
void exist_user_menu(Candidate** candidateDataBase) {
	char* id = NULL, * password = NULL;
	int i = 0, index;
	printf("Exiting user\n");
	printf("Please enter ID\n");
	gets(id);
	while (i < SIZE && candidateDataBase[i] != NULL)
	{
		if (strcmp(candidateDataBase[i]->id, id) == 0) {
			index = i;
			break;
		}
		if (i == SIZE - 1 || candidateDataBase[i] == NULL)
			print("ID card is not in the system, try again:\n");
		scanf("%s", id);
		i = -1;
	}
	i++;
	printf("Enter password\n");
	gets(password);
	while (strcmp(password, candidateDataBase[index]->password) != 0)
	{
		printf("Incorrect password, please try again");
		gets(password);
	}
	//Enter -func main menu
	//צריך לתת לו גם אופציה להקליד מחדש שם משתמש?
}

void new_user_menu(Candidate** candidateDataBase) {
	char* id = NULL, * fullname = NULL, * password = NULL;
	int i = 0, index, typeuser;
	printf("New user\n");
	printf("Please enter ID\n");
	gets(id);
	while (id_input_validity(id) == FALSE || IdInSystem(id, candidateDataBase) == TRUE) {
		printf("Please enter a valid ID number containing only 9 digits\n");
		gets(id);
	}
	printf("Eneter  full name:\n");
	gets(fullname);
	while (fulname_input_validity(fullname) != TRUE) {
		printf("Please enter a valid first name between 3 and 20 characters in letters only\n");
		gets(fullname);
	}
	printf("Enter password\n");
	gets(password);
	while (passpword_input_validity(password) != TRUE) {
		printf("Please enter a valid password between 6 and 20 characters containing only uppercase and lowercase letters\n");
		gets(password);
	}
	print("If you are Candidate- press 1 and if you Employer press 2: \n");
	scanf_s("%d", typeuser);
	while (typeuser != 0 || typeuser != 1)
	{
		printf("error!, enter again\n");
		scanf_s("%d", typeuser);
	}
	if (typeuser == 1) {
		// פונקציה מעסיק
	}
	else
		printf("dfghjk");
	//פונקציה משתמש
}
void user_main_menu(Candidate** candidateDataBase) {
	int choice;
	printf("STARJOB\n");
	printf("Please enter:\n1-Exiting user\n2-New user\n");
	scanf_s("%d", &choice);
	while (choice != 1 && choice != 2)
	{
		printf("Wrong number, try again!  ");
		scanf_s("%d", &choice);
	}
	if (choice == 1)
		exist_user_menu(candidateDataBase);
	else
		new_user_menu(candidateDataBase);

}
void restore_job(Job** jobDataBase, char name[]) {
	int i;
	for (i = 0; i < SIZE && jobDataBase[i] != NULL; i++)
	{
		if (strcmp(name, jobDataBase[i]->name) == 0) {
			jobDataBase[i]->description;//מה מתאר אם היא מוחצגת או לא?
			break;
		}
	}
}


