#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>
#define SIZE 30
#define SIZE2 500 //for free text
//typedef enum { employer = 0, candidate = 1 }Gender;
typedef enum { FALSE = 0, TRUE = 1 }Bool;
typedef struct {
	char id[SIZE];
	char password[SIZE];
	char fullName[SIZE];
	char phoneNumber[SIZE];
	char education[SIZE2];
	char workExperience[SIZE2];
	char gender[SIZE];
	char CV[SIZE2];//קורות חיים
}Candidate;
typedef struct {
	char id[SIZE];
	char password[SIZE];
	char fullName[SIZE];
	char phoneNumber[SIZE];
	char companyName[SIZE];
	char description[SIZE2];
	char gender[SIZE];
}Employer;
typedef enum { Fulltime = 1, Parttime = 2, Temporaryjob = 3, Motherjob = 4 }Scope;
typedef enum { North = 1, South = 2, Central = 3, Jerusalem = 4 }Area;
typedef enum { Sales = 1, AccountingAndFinance = 2, Logistics = 3, EducationandTraining = 4, HiTech = 5, Securing = 6, Restaurants = 7 }Profession;
typedef enum { With_experience = 1, Without_experience = 2 }Experience; //היה חסר אז הוספתי-שיראל
typedef struct {
	int id;
	char companyName[SIZE];
	char name[SIZE];
	Scope  scope;//קליטה של מספר לקובץ
	Area  area;
	Profession profession;
	//Experience experience; //היה חסר אז הוספתי
	char description[SIZE];
	char requirements[SIZE];
	Bool status;//0-avalabe 1- ananabala
	char candidate1[SIZE2];
	char candidate2[SIZE2];
	char candidate3[SIZE2];
}Job;
/////////////////////////////////////////////////////////////////////
Bool id_input_validity(char id[]);
Bool IsDigit(char c);
Bool IsLetter(char c);
Bool passpword_input_validity(char password[]);
Bool fulname_input_validity(char fulname[]);
Bool jobname_input_validity(char jobname[]);
Bool IdInSystem(char id[], Candidate** candidateDataBase, int* sizeC);
void exist_user_menu(Candidate** candidateDataBase, Employer** employer, Job** job, int* sizeJ, int* sizeC, int* sizeE);
void new_user_menu(Candidate** candidateDataBase, Employer** employer, Job** job, int* sizeJ, int* sizeC, int* sizeE);
void user_main_menu(Candidate** candidateDataBase, Employer** employer, Job** job, int* sizeJ, int* sizeC, int* sizeE);
void writeFileEmployer(Employer** employer, int size);
void writeFileCandidate(Candidate** candidate, int size);
void writeFileJobs(Job** job, int size);
void readFileEmployer(Employer** employer, int size);
void readFileCandidate(Candidate** candidate, int size);
void readFileJobs(Job** job, int size);
void readSize(int* sizeEmployer, int* sizeCandidate, int* sizeJob);
///////////////////////////////////////////////////////////////////
void main_candidate_menu(Candidate** candidateDataBase, Job** job, int sizeJ, int i);
void menu_edit_c_profile(Candidate** candidateDataBase, int i);
void candidate_profile(Candidate** candidateDataBase, int i);
int exeperience_input_validity(char* exeperience);
int education_input_validity(char* education);
int phonenum_input_validity(char* phonenum);
void filterbyscope(Job* job);

/////////////////////////////////////////////////////////////////
//Bool jobname_input_validity(char jobname[]);
void EmployerProfile(Employer* employer);
void EditProfile(Employer* e);
const char* getArea(enum Area area);
const char* getScope(enum Scope scope);
const char* getProfession(enum Profession profession);
const char* getExperience(enum Experience experience);
void print_current_jobs(Job* Job);
void viewAllJobOfEmployer(Employer* employer, Job** job, int size);
void historyOfDeletedJobs(Employer* employer, Job** job, int size);
void jobRestoration(Job* job);
void menuJob(Job* job);
void editJob(Job* job);
void deleteJob(Job* job);
void jobPosting(Job** job, int size);
void EmployerMenu(Employer* employer, Job** job, int size);
void filterbyrea_5_2_2(Job* job);
void filterjobsbyprofession_5_2_3(Job* job);
void present_candidate_history_4(Candidate* candidate, Job** job, int size);//
void viewjobs_5(Candidate* candidate, Job** job, int size);
void viewallthejobs_5_1(Candidate* candidate, Job** job, int size);
void apply_5_1_1(Candidate* candidate, Job** job, int size);
void printalljobs(Job** job, int size);
void filterjobs_5_2(Job** job, int size);
void menuforfilterjobs_5_2_1(Candidate* candidate, Job** job, int size);
void printbysomefilter(char filte[], char filtername[], Job** job, int size);
void filter_by_area_5_2_2(Job** job, int size);
void filter_jobs_by_profession_5_2_3(Job** job, int size);
void filter_jobs_by_scope_5_2_4(Job** job, int size);
void filter_by_job_experience_5_2_5(Job** job, int size);
void logingout_5_4();

int main()
{
	int i, sizeEmployer, sizeCandidate, sizeJob;
	readSize(&sizeEmployer, &sizeCandidate, &sizeJob);

	Employer** employer = (Employer*)malloc(50 * sizeof(Employer));
	if (!employer)
	{
		printf("error1\n");
		return 0;
	}
	Candidate** candidate = (Candidate*)malloc(100 * sizeof(Candidate));
	if (!candidate)
	{
		printf("error1\n");
		return 0;
	}
	Job** job = (Job*)malloc(100 * sizeof(Job));
	if (!job) {
		printf("error1\n");
		return 0;
	}
	for (i = 0; i < 50; i++)
		employer[i] = NULL;
	for (i = 0; i < 100; i++)
		candidate[i] = NULL;
	for (i = 0; i < 100; i++)
		job[i] = NULL;
	if (sizeCandidate > 0)
		readFileCandidate(candidate, sizeCandidate);
	if (sizeEmployer > 0)
		readFileEmployer(employer, sizeEmployer);
	if (sizeJob > 0)
		readFileJobs(job, sizeJob);
	user_main_menu(candidate, employer, job, &sizeJob, &sizeCandidate, &sizeEmployer);
	writeFileCandidate(candidate, sizeCandidate);
	writeFileEmployer(employer, sizeEmployer);
	writeFileJobs(job, sizeJob);
	FILE* fp = fopen("sizes.txt", "w");
	fprintf(fp, "%d\n%d\n%d\n", sizeEmployer, sizeCandidate, sizeJob);
	fclose(fp);
	printf("end\n");
	return 0;
}
//void writeSize(int* sizeEmployer, int* sizeCandidate, int* sizeJob) {
//	int i;
//	FILE* fp = fopen("sizes.txt", "w");
//	fprintf(fp, "%d\n%d\n%d\n", sizeEmployer, sizeCandidate, sizeJob);
//	fclose(fp);
//	return;
//}
void writeFileEmployer(Employer** employer, int size)
{
	int i;
	FILE* fp = fopen("employer.txt", "w");
	for (i = 0; i < size && employer[i] != NULL; i++)
		fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n", employer[i]->id, employer[i]->password, employer[i]->fullName, employer[i]->phoneNumber, employer[i]->companyName, employer[i]->description, employer[i]->gender);
	fclose(fp);
	return;
}
void writeFileCandidate(Candidate** candidate, int size)
{
	int i;
	FILE* fp = fopen("Candidate.txt", "w");
	for (i = 0; i < size && candidate[i] != NULL; i++)
		fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", candidate[i]->id, candidate[i]->password, candidate[i]->fullName, candidate[i]->phoneNumber, candidate[i]->education, candidate[i]->workExperience, candidate[i]->gender, candidate[i]->CV);
	fclose(fp);
	return 1;
}
void writeFileJobs(Job** job, int size)
{
	int i;
	FILE* fp = fopen("jobs.txt", "w");
	for (i = 0; i < size && job[i] == NULL; i++)
		fprintf(fp, "%s\n%s\n%d\n%d\n%d\n%s\n%s\n%d\n%s\n%s\n%s\n", job[i]->companyName, job[i]->name, job[i]->scope, job[i]->area, job[i]->profession, job[i]->description, job[i]->requirements, job[i]->status, job[i]->candidate1, job[i]->candidate2, job[i]->candidate3);
	fclose(fp);
	return 1;
}
void readSize(int* sizeEmployer, int* sizeCandidate, int* sizeJob) {
	FILE* fp = fopen("sizes.txt", "r");
	fscanf(fp, "%d", sizeEmployer);
	fscanf(fp, "%d", sizeCandidate);
	fscanf(fp, "%d", sizeJob);
	fclose(fp);
}
void readFileJobs(Job** job, int size)
{

	int i;
	FILE* fp = fopen("jobs.txt", "r");
	for (i = 0; i < size; i++)
	{

		job[i] = (Job*)malloc(1 * sizeof(Job));
		if (!job[i])
			return;
		job[i]->id = 0;
		fgets(job[i]->companyName, SIZE2, fp);
		job[i]->companyName[strlen(job[i]->companyName) - 1] = '\0';
		fgets(job[i]->name, SIZE2, fp);
		job[i]->name[strlen(job[i]->name) - 1] = '\0';
		fscanf(fp, "%d\n", &job[i]->scope);
		fscanf(fp, "%d\n", &job[i]->area);
		fscanf(fp, "%d\n", &job[i]->profession);
		fgets(job[i]->description, SIZE2, fp);
		job[i]->description[strlen(job[i]->description) - 1] = '\0';
		fgets(job[i]->requirements, SIZE2, fp);
		job[i]->requirements[strlen(job[i]->requirements) - 1] = '\0';
		fscanf(fp, "%d\n", &job[i]->status);
		fgets(job[i]->candidate1, SIZE2, fp);
		job[i]->candidate1[strlen(job[i]->candidate1) - 1] = '\0';
		fgets(job[i]->candidate2, SIZE2, fp);
		job[i]->candidate2[strlen(job[i]->candidate2) - 1] = '\0';
		fgets(job[i]->candidate3, SIZE2, fp);
		job[i]->candidate3[strlen(job[i]->candidate3) - 1] = '\0';
		if (feof(fp))
			break;
	}
	fclose(fp);
}
void readFileEmployer(Employer** employer, int sizeE)
{
	int i;
	FILE* fp = fopen("employer.txt", "r");
	for (i = 0; i < sizeE; i++) {
		employer[i] = (Employer*)malloc(1 * sizeof(Employer));
		if (!employer[i])
			return;
		fgets(employer[i]->id, SIZE2, fp);
		employer[i]->id[strlen(employer[i]->id) - 1] = '\0';
		fgets(employer[i]->password, SIZE2, fp);	
		employer[i]->password[strlen(employer[i]->password) - 1] = '\0';
		fgets(employer[i]->fullName, SIZE2, fp);
		employer[i]->fullName[strlen(employer[i]->fullName) - 1] = '\0';
		fgets(employer[i]->phoneNumber, SIZE2, fp);
		employer[i]->phoneNumber[strlen(employer[i]->phoneNumber) - 1] = '\0';
		fgets(employer[i]->companyName, SIZE2, fp);
		employer[i]->companyName[strlen(employer[i]->companyName) - 1] = '\0';
		fgets(employer[i]->description, SIZE2, fp);
		employer[i]->description[strlen(employer[i]->description) - 1] = '\0';
		fgets(employer[i]->gender, SIZE2, fp);
		employer[i]->gender[strlen(employer[i]->gender) - 1] = '\0';
	}
	fclose(fp);
}
void readFileCandidate(Candidate** candidate, int size)
{
	int i,len=0;

	FILE* fp = fopen("Candidate.txt", "r");
	for (i = 0; i < size; i++)
	{
		candidate[i] = (Candidate*)malloc(1 * sizeof(Candidate));
		if (!candidate[i])
			return;
		fgets(candidate[i]->id, SIZE, fp);
		candidate[i]->id[strlen(candidate[i]->id) - 1] = '\0';
		fgets(candidate[i]->password, SIZE, fp);
		candidate[i]->password[strlen(candidate[i]->password) - 1] = '\0';
		fgets(candidate[i]->fullName, SIZE, fp);
		candidate[i]->fullName[strlen(candidate[i]->fullName) - 1] = '\0';
		fgets(candidate[i]->phoneNumber, SIZE, fp);
		candidate[i]->phoneNumber[strlen(candidate[i]->phoneNumber) - 1] = '\0';
		fgets(candidate[i]->education, SIZE, fp);
		candidate[i]->education[strlen(candidate[i]->education) - 1] = '\0';
		fgets(candidate[i]->workExperience, SIZE, fp);
		candidate[i]->workExperience[strlen(candidate[i]->workExperience) - 1] = '\0';
		fgets(candidate[i]->gender, SIZE, fp);
		candidate[i]->gender[strlen(candidate[i]->gender) - 1] = '\0';
		fgets(candidate[i]->CV, SIZE, fp);
		candidate[i]->CV[strlen(candidate[i]->CV) - 1] = '\0';

	}

	fclose(fp);


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
		return FALSE;
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

	int len = strlen(jobname);
	if (len < 1 || len>20)
		return FALSE;

	return TRUE;
}
Bool IdInSystem(char id[], Candidate** candidateDataBase, int* sizeC) {
	//בדיקה אם ת"ז קיימת במערכת
	int i;
	if (*sizeC != 0) {
		for (i = 0; i < *sizeC; i++)
		{
			if (strcmp(candidateDataBase[i]->id, id) == 0) {
				return TRUE;
			}
		}
	}
	return FALSE;
}
void user_main_menu(Candidate** candidateDataBase, Employer** employer, Job** job, int* sizeJ, int* sizeC, int* sizeE) {
	int choice;
	printf("STARJOB\n");
	printf("Please enter:\n1-User exist \n2-New user\n");
	scanf_s("%d", &choice);
	while (choice != 1 && choice != 2)
	{
		printf("Wrong number, try again!  ");
		scanf_s("%d", &choice);
	}
	if (choice == 1)
		exist_user_menu(candidateDataBase, employer, job, sizeJ, sizeC, sizeE);
	else
		new_user_menu(candidateDataBase, employer, job, sizeJ, sizeC, sizeE);


}
void exist_user_menu(Candidate** candidateDataBase, Employer** employer, Job** job, int* sizeJ, int* sizeC, int* sizeE) {
	char id[SIZE],password[SIZE];
	int i = 0, typeuser;
	printf("candidate- prees 1, Employer- pree 2  \n");
	scanf_s("%d", &typeuser);
	while (typeuser != 2 && typeuser != 1)
	{
		printf("error!, enter again\n");
		scanf_s("%d", &typeuser);
	}
	printf("Exiting user\n");
	printf("Please enter ID\n");
	getchar();
	gets(id);
	if (typeuser == 1) {
		while (i < (*sizeC))
		{
			if ((strcmp(candidateDataBase[i]->id, id)) == 0)
			{
				printf("Enter password\n");
				gets(password);
				while ((strcmp(password, candidateDataBase[i]->password)) != 0)
				{
					printf("Incorrect password, please try again");
					getchar();
					gets(password);
				}
				main_candidate_menu(candidateDataBase, job, *sizeJ, i);
				break;
			}
			if (i == (*sizeC) - 1)
			{
				printf("ID card is not in the system, try again:\n");
				getchar();
				gets(id);
				i = -1;
			}
			i++;
		}
	}
	else {
		while (i < (*sizeE))
		{
			if ((strcmp(employer[i]->id, id)) == 0)
			{
				printf("Enter password\n");
				//getchar();
				gets(password);
				while ((strcmp(password, employer[i]->password)) != 0)
				{
					printf("Incorrect password, please try again");
					getchar();
					gets(password);
				}
				EmployerMenu(employer[i], job, *sizeJ);
				break;
			}
			if (i == (*sizeE) - 1)
			{
				printf("ID card is not in the system, try again:\n");
				//getchar();
				gets(id);
				i = -1;
			}
			i++;
		}
	}
	printf("secssful!\n");
	//צריך לתת לו גם אופציה להקליד מחדש שם משתמש?
}
void new_user_menu(Candidate** candidateDataBase, Employer** employer, Job** job, int* sizeJ, int* sizeC, int* sizeE) {
	char id[SIZE], fullname[SIZE2], password[SIZE2];
	int i = 0, typeuser;
	printf("New user\n");
	printf("Please enter ID\n");
	getchar();
	gets(id);
	while (id_input_validity(id) == FALSE || IdInSystem(id, candidateDataBase, sizeC) == TRUE) {
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
	printf("pass: %s\n", password);
	while (passpword_input_validity(password) != TRUE) {
		printf("Please enter a valid password between 6 and 20 characters containing only uppercase and lowercase letters\n");
		gets(password);
	}
	printf("If you are Candidate- press 1 and if you Employer press 2: \n");
	scanf_s("%d", &typeuser);
	while (typeuser != 2 && typeuser != 1)
	{
		printf("error!, enter again\n");
		scanf_s("%d", &typeuser);
	}

	if (typeuser == 2) {

		employer[*sizeE] = (Employer*)malloc(1 * sizeof(Employer));

		strcpy(employer[*sizeE]->id, id);
		strcpy(employer[*sizeE]->fullName, fullname);
		strcpy(employer[*sizeE]->password, password);
		strcpy(employer[*sizeE]->companyName, "-");
		strcpy(employer[*sizeE]->description, "-");
		strcpy(employer[*sizeE]->gender, "-");
		strcpy(employer[*sizeE]->phoneNumber, "-");

		int i = *sizeE;
		++(*sizeE);
		EditProfile(employer[i]);
		EmployerMenu(employer[i], job, *sizeJ);
	}
	else
	{
		if (*sizeC <= 100) {
			candidateDataBase[*sizeC] = (Candidate*)malloc(1 * sizeof(Candidate));
			if (!candidateDataBase[*sizeC])
			{
				return 0;
			}
			strcpy(candidateDataBase[*sizeC]->id, id);
			strcpy(candidateDataBase[*sizeC]->fullName, fullname);
			strcpy(candidateDataBase[*sizeC]->password, password);
			strcpy(candidateDataBase[*sizeC]->CV, "-");
			strcpy(candidateDataBase[*sizeC]->education, "-");
			strcpy(candidateDataBase[*sizeC]->gender, "-");
			strcpy(candidateDataBase[*sizeC]->phoneNumber, "-");
			strcpy(candidateDataBase[*sizeC]->workExperience, "-");
			int i = *sizeC;
			++(*sizeC);
			menu_edit_c_profile(candidateDataBase, i);
			main_candidate_menu(candidateDataBase, job, *sizeJ, i);
		}
		else
			printf("Unable to register. The number of possible subscribers is over");
	}

	////פונקציה משתמש
}
int phonenum_input_validity(char* phonenum)
{
	if (IsDigit(phonenum)) {
		if (strlen(phonenum) == 10 && phonenum[0] == 0)
		{
			return 0;
		}
	}
	return 1;
}
int education_input_validity(char* education)
{
	int len = strlen(education);
	if (len > 500)
	{
		return 1;
	}
	return 0;
}
int exeperience_input_validity(char* exeperience)
{
	int len = strlen(exeperience);
	if (len > 500)
	{
		return 1;
	}
	return 0;
}
void main_candidate_menu(Candidate** candidateDataBase, Job** job, int sizeJ, int i)
{
	int choice;
	do
	{
		printf(" To  Profile press '1' \n To  Jobs History press '2' \n To  View jobs press '3' \n To Loging out press '4' \n ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			candidate_profile(candidateDataBase, i);
			break;
		case 2:
			//עפה בזמן ריצה
			present_candidate_history_4(candidateDataBase[i], job, sizeJ);
			break;
		case 3:
			viewjobs_5(candidateDataBase[i], job, sizeJ);
			break;
		case 4:
			logingout_5_4();
			break;
		default:
			printf("Error,try again.\n");
			break;
		}

	} while (choice != 0);
}
void candidate_profile(Candidate** candidateDataBase, int i) {
	int choice;
	do
	{

		printf("%s\n%s\n%s\n%s\n%s\n", candidateDataBase[i]->fullName, candidateDataBase[i]->id, candidateDataBase[i]->phoneNumber,/* candidate->email,*/ candidateDataBase[i]->education, candidateDataBase[i]->workExperience);//חסר הדפסת תאריך לידה
		printf("\n To Edit Profile press '1' \n To Back to the previous menu press '2' \n ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			menu_edit_c_profile(candidateDataBase, i);
			break;
		case 2:
			return;

		default:
			printf("Error,try again.\n");
		}
		break;

	} while (choice != 0);
}
void menu_edit_c_profile(Candidate** candidateDataBase, int i)
{
	int choice, flag = 0;
	char name[SIZE];
	char id[SIZE];
	char email[SIZE];
	char education[SIZE2];
	char workexperience[SIZE2];
	char phoneNumber[SIZE];
	do
	{
		printf("The editable fields for a candidate are:\n'1' Full name\n'2' Email address\n'3' cell phone number\n'4' Education\n'5' Work experience\n'6' Resume\n'0' - Back to the previous menu - the profile menu\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0:
			return;
		case 1:
			printf("Enter your name:\n");
			gets(name);
			while ((fulname_input_validity(name)) != TRUE)
			{
				printf("Normal input contains only 3-20 letters\n");
				printf("Enter your name\n");
				gets(name);
			}
			printf("To update press '0' To not change press '1'\n");
			scanf_s("%d", &flag);
			while (flag != 0 && flag != 1)
			{
				printf("To update press '0' To not change press '1'\n");
				scanf_s("%d", &flag);
			}
			if (flag == 0)
			{
				strcpy(candidateDataBase[i]->fullName, name);
				printf("The name has been updated\n");
				break;
			}
			if (flag == 1)
			{
				break;
			}
		case 2:
			printf("Enter your email address:\n");
			
			gets(email);
			//while (//תקינות  איימיל =0)
			//	{
			//	   printf("The email address is incorrect\n");
			//	   printf("Enter your email address:\n");
			//	   /* getchar();
			//		gets_s(email, N);*/
			//	}
			printf("To update press '0' To not change press '1'\n");
			scanf_s("%d", &flag);
			while (flag != 0 && flag != 1)
			{
				printf("To update press '0' To not change press '1'\n");
				scanf_s("%d", &flag);

			}
			if (flag == 0)
			{
				//strcpy(, email);*/
				printf("The email has been updated\n");
				break;
			}
			if (flag == 1)
			{
				break;
			}
		case 3:
			printf("Enter your phone number:\n");
			getchar();
			gets(phoneNumber);
			while (phonenum_input_validity(phoneNumber) == 1)
			{
				printf("The phone number is incorrect\n");
				printf("Enter your phone number:\n");
				gets(phoneNumber);
			}
			printf("To update press '0' To not change press '1'\n");
			scanf_s("%d", &flag);
			while (flag != 0 && flag != 1)
			{
				printf("To update press '0' To not change press '1'\n");
				scanf_s("%d", &flag);

			}
			if (flag == 0)
			{
				strcpy(candidateDataBase[i]->phoneNumber, phoneNumber);
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
			gets(education);
			while (education_input_validity(education) == 1)
			{
				printf("Normal input contains only 0-500 letters\n");
				printf("Enter your education\n");
				gets(education);
			}
			printf("To update press '0' To not change press '1'\n");
			scanf_s("%d", &flag);
			while (flag != 0 && flag != 1)
			{
				printf("To update press '0' To not change press '1'\n");
				scanf_s("%d", &flag);
			}
			if (flag == 0)
			{
				strcpy(candidateDataBase[i]->education, education);
				printf("The education has been updated\n");
				break;
			}
			if (flag == 1)
			{
				break;
			}
		case 5:
			printf("Enter your work experience:\n");

			gets(workexperience);
			while (exeperience_input_validity(workexperience) == 1)
			{
				printf("Normal input contains only 0-500 letters\n");
				printf("Enter your work experience\n");
				gets(workexperience);
			}
			printf("To update press '0' To not change press '1'\n");
			scanf_s("%d", &flag);
			while (flag != 0 && flag != 1)
			{
				printf("To update press '0' To not change press '1'\n");
				scanf_s("%d", &flag);
			}
			if (flag == 0)
			{
				strcpy(candidateDataBase[i]->workExperience, workexperience);
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
//////////////////////////////////////////////////////////////////////////
void EmployerMenu(Employer* employer, Job** job, int size)

{
	int choice;
	do {
		printf("--- M E N U--- \n 1) open profile window\n 2) View posted job\n 3)  advertise a new job\n");
		printf(" 4) open the window of deleted jobs history\n 5) Filtering options\n");
		printf(" 000) log out from the system\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			EmployerProfile(employer);
			break;
		case 2:
			viewAllJobOfEmployer(employer, job, size);

			break;
		case 3:
			jobPosting(job, size);
			break;
		case 4:
			historyOfDeletedJobs(employer, job, size);
			break;
		case 5:
			filterjobs_5_2(job, size);
			break;
		case 000:
			break;

		default:
			printf("Error,try again.\n");
			break;
		}
	} while (choice != 000);
}
void jobPosting(Job** job, int size)
{
	int i, index=0, fullArray = 0;
	char* indexChar = NULL;
	for (i = 0; i < size; i++)
	{

		if (job[i] == NULL)
		{
			index = i;
			break;
		}
		++fullArray;

	}
	if (fullArray == 100)//Check if the set of jobs is full
	{
		printf("It is not possible to add another position.\n");
		return;
	}
	job[index] = (Job*)malloc(1 * sizeof(Job));
	if (!(job[index]))
		return;
	job[index]->id = index;
	strcpy(job[index]->candidate1, "-");
	strcpy(job[index]->candidate2, "-");
	strcpy(job[index]->candidate3, "-");
	job[index]->status = TRUE;
	editJob(job[index]);
	printf("The job was added successfully\n");

}
void EmployerProfile(Employer* employer)
{
	int choice;
	do
	{
		printf("%s\n%s\n%s\n%s\n%s\n", employer->fullName, employer->id, employer->phoneNumber, employer->companyName, employer->description);
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
	char name[SIZE];
	char id[SIZE];
	char companyName[SIZE];
	char companyDescription[SIZE];
	char phoneNumber[SIZE];

	do
	{

		//הדפסת פרטי משתמש של שם ת.ז ...
		printf("1. Full name\n 2. phone number\n 3.company name\n 4. general description\n5. Back to the previous menu\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter your name:\n");
			getchar();
			gets_s(name, SIZE);
			strcpy(e->fullName, name);

			break;
		case 2:
			printf("Enter your phone:\n");
			getchar();
			gets_s(phoneNumber, SIZE);
			strcpy(e->phoneNumber, phoneNumber);
			break;


		case 3:
			printf("Enter your name company:\n");
			getchar();
			gets_s(companyName, SIZE);
			strcpy(e->companyName, companyName);
			break;

		case 4:
			printf("Enter a description of your company :\n");
			getchar();
			gets_s(companyDescription, SIZE2);
			strcpy(e->description, companyDescription);

			break;
		case 5:
			return;

		default:
			printf("Error,try again.\n");
			break;
		}


	} while (choice != 5);
}
const char* getArea(enum Area area) //ôåð÷öéä ìäëðñú îñ å÷áìú îçøåæú äîééöâú àú äàåôöéä îúåê äenum
{
	switch (area)
	{
	case 1: return "North";
	case 2: return "South";
	case 3: return "Central";
	case 4: return "Jerusalem";
	}
}
const char* getScope(enum Scope scope) //ôåð÷öéä ìäëðñú îñ å÷áìú îçøåæú äîééöâú àú äàåôöéä îúåê äenum
{
	switch (scope)
	{
	case 1: return "Fulltime";
	case 2: return "Parttime";
	case 3: return "Temporaryjob";
	case 4: return "Motherjob";

	}
}
const char* getProfession(enum Profession profession) //ôåð÷öéä ìäëðñú îñ å÷áìú îçøåæú äîééöâú àú äàåôöéä îúåê äenum
{
	switch (profession)
	{
	case 1: return "Sales";
	case 2: return "AccountingAndFinance";
	case 3: return "Logistics";
	case 4: return "EducationandTraining ";
	case 5: return "HiTech";
	case 6: return "Securing";
	case 7: return "Restaurants";

	}
}
const char* getExperience(enum Experience experience) //ôåð÷öéä ìäëðñú îñ å÷áìú îçøåæú äîééöâú àú äàåôöéä îúåê äenum
{
	switch (experience)
	{
	case 1: return "with_experience";
	case 2: return "without_experience";

	}
}
void print_current_jobs(Job* Job)
{
	printf("\n Job name : %s \n Company name: %s \n job id: %d \n Scope: %s \n  area : %s \n Job description :%s \n Requirements : %s \n Proffesion: %s \n  : ", Job->name, Job->companyName, Job->id, getScope(Job->scope), getArea(Job->area), Job->description, Job->requirements, getProfession(Job->profession));
}
void viewAllJobOfEmployer(Employer* employer, Job** job, int size)
{
	char choise[SIZE];
	int choise1;
	do
	{
		for (int i = 0; i < size && job[i] != NULL; ++i)
		{
			if (strcmp(employer->companyName, job[i]->companyName) == 0 && job[i]->status == TRUE)
				print_current_jobs(job[i]);
			else
				printf("No jobs were posted\n");

		}

		printf("Enter a job ID number to edit a job / delete a job / view job applicants\nPress 00 to return to the main menu\n");
		getchar();
		gets(choise);
		choise1 = atoi(choise);
		while (job[choise1] == NULL || choise1 < 0)
		{
			printf("Error. Insert a valid ID\n");
			getchar();
			gets(choise);
			choise1 = atoi(choise);

		}

		if (strcmp(choise, "00") == 0)
			return;
		choise1 = atoi(choise);
		menuJob(job[choise1]);


	} while (choise != 0);


}
void historyOfDeletedJobs(Employer* employer, Job** job, int size)
{
	int choise, id, flag = 0;
	do
	{
		for (int i = 0; i < size; ++i)
		{
			if (strcmp(employer->companyName, job[i]->companyName) == 0 && job[i]->status == FALSE)
			{
				print_current_jobs(job[i]);
				flag = 1;
			}

		}
		if (flag == 0)
		{
			printf("there is no deleted job\n");
			return;
		}
		printf("1. Job Restoration\n 0.return to the main menu\n");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			printf("Enter the ID number of the job you want to restore/\n");
			scanf("%d", &id);
			jobRestoration(job[id]);
		case 0:
			return;

		default:
			printf("Error,try again.\n");
			break;
		}

	} while (choise != 0);


}
void jobRestoration(Job* job)
{
	job->status = TRUE;
	printf("The job was successfully restored\n");
}
void menuJob(Job* job)
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
			//לשאול איך אנחנו מציגים רשימת מועמדים ועוברים לפרופיל
			break;
		case 0:
			return;

		default:
			printf("Error,try again.\n");
			break;
		}

	} while (choice != 0);

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
			filterbyscope(job);

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
void deleteJob(Job* job)
{
	if (job->status)
	{
		job->status = FALSE;
		printf("The job was deleted.\n");
	}
}
void filterbyscope(Job* job)
{
	int choice;
	printf("pls select one of 4 optionals scope:\n 1. Fulltime \n 2. Parttime \n 3. Temporaryjob \n 4. Motherjob \n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		job->area = Fulltime;

		break;
	case 2:
		job->area = Parttime;
		break;
	case 3:
		job->area = Temporaryjob;
		break;
	case 4:
		job->area = Motherjob;
		break;
	default:
		printf("invalid choice , try again!");
	}
}
//Bool jobname_input_validity(char jobname[]) {
//	int len = strlen(jobname);
//	if (len < 1 || len>20)
//		return FALSE;
//	return TRUE;
//}
void present_candidate_history_4(Candidate* candidate, Job** job, int size)
{
	int i = 0;
	while (job[i] != NULL && i < size)
	{
		if (job[i]->status == TRUE)
		{
			if (strcmp(job[i]->candidate1, candidate->id) == 0 || strcmp(job[i]->candidate2, candidate->id) == 0 || strcmp(job[i]->candidate3, candidate->id) == 0)
				print_current_jobs(&job[i]);
		}
		i++;
	}
}
void viewjobs_5(Candidate* candidate, Job** job, int size)// להכניס את המניו של תאיר
{
	int choice;
	do
	{
		printf("pls select one of 3 options :\n 1. view all the jobs \n 2. Filter by properties \n 3. Back to the main menu\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1://5.1
			viewallthejobs_5_1(candidate, job, size);
			break;
		case 2://5.2 + 5.2.1
			filterjobs_5_2(job, size);
			menuforfilterjobs_5_2_1(candidate, job, size);
			break;
		case 3://5.3
			return;
		default:
			printf("invalid choice , try again!");
		}

	} while (choice != 3);

}
void viewallthejobs_5_1(Candidate* candidate, Job** job, int size)
{
	int choice;
	do
	{

		printf("pls select one of 3 options :\n 1. view all the jobs without filtering \n 2. apply \n 0. Back to the previous menu-view jobs \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printalljobs(job, size);
			break;
		case 2://apply
			apply_5_1_1(candidate, job, size);
			break;
		case 0://back to the previous menu
			viewjobs_5(candidate, job, size);
			break;
		default:
			printf("invalid choice , try again!");

		}

	} while (choice != 0);
}
void apply_5_1_1(Candidate* candidate, Job** job, int size)
{
	int jobid;
	int i = 0;

	printf("Type in the ID number of the job to which you want to apply.\n");
	scanf("%d", &jobid);

	while (job[i] != NULL && i < size)
	{
		if ((job[i]->id == jobid) && (job[i]->status == TRUE))
		{
			if (strcmp(job[i]->candidate1, "-") == 0)
			{
				strcpy(job[i]->candidate1, candidate->id);
				printf("the apply seccess !");
				break;
			}
			else if (strcmp(job[i]->candidate2, "-") == 0)
			{
				strcpy(job[i]->candidate2, candidate->id);
				printf("the apply seccess !");
				break;
			}
			else if (strcmp(job[i]->candidate3, "-") == 0)
			{
				strcpy(job[i]->candidate3, candidate->id);
				printf("the apply seccess !");
				break;
			}
			else
			{
				printf("Oops! The max number of candidates who can apply for each job is 3.");
				break;
			}
		}
		++i;
		if (job[i] == NULL)
		{
			printf("the job is unavailable");
			break;
		}

	}

}
void printalljobs(Job** job, int size)
{
	int i = 0;
	while (job[i] != NULL && i < size)
	{
		if (job[i]->status == TRUE)
			print_current_jobs(job[i]);

		i++;
	}
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
void filterjobs_5_2(Job** job, int size)
{
	int choice;

	printf("pls select one of 4 filtering options  :\n 1. area \n 2. proffesional \n 3. job scope \n 4. job exeperience\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		filter_by_area_5_2_2(job, size);
		return;
	case 2:
		filter_jobs_by_profession_5_2_3(job, size);
		return;
	case 3:
		filter_jobs_by_scope_5_2_4(job, size);
		return;
	case 4:
		filter_by_job_experience_5_2_5(job, size);
		return;
	default:
		printf("invalid choice , try again!");

	}

}
void menuforfilterjobs_5_2_1(Candidate* candidate, Job** job, int size)
{
	int choice;
	printf("pls press:\n 5. apply \n 0. back to previous menu- view jobs ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 5:
		apply_5_1_1(candidate, job, size);//להכניס את המועמד עם באינדקס הנכון
		break;
	case 0:
		viewjobs_5(candidate, job, size);
		break;
	default:
		printf("invalid choice , try again!");
	}
}
void printbysomefilter(char filter[], char filtername[], Job** job, int size)
{
	int i = 0;
	int flag = 0;
	while (job[i] != NULL && i < size)
	{
		if (strcmp(filter, "area") == 0)
		{
			if (strcmp(getArea(job[i]->area), filtername) == 0)
			{
				print_current_jobs(job[i]);
				flag = 1;
			}

		}

		else if (strcmp(filter, "scope") == 0)
		{
			if (job[i]->scope == filtername)
			{
				print_current_jobs(job[i]);
				flag = 1;
			}
		}

		else if (strcmp(filter, "proffesion") == 0)
		{
			if (job[i]->profession == filtername)
			{
				print_current_jobs(job[i]);
				flag = 1;
			}
		}

		/*	else if (strcmp(filter, "experience") == 0)
			{
				if (job[i]->experience == filtername)
				{
					print_current_jobs(job[i]);
					flag = 1;
				}
			}*/

			//if (job[i] == NULL && flag==0)
			//printf("there is no job by this filter");

		++i;

	}
	if (flag == 0)
		printf("there is no job by this filter");
	return;
}
void filter_by_area_5_2_2(Job** job, int size)
{
	int choice;
	char filter[] = "area";


	printf("pls select one of 4 optionals area:\n 1. North\n 2. South\n 3.Central\n 4.Jerusalem\n");
	scanf("%d", &choice);

	while (choice < 1 || choice>4)
	{
		printf("invalid choice,try again");
		scanf("%d", &choice);
	}

	printbysomefilter(filter, getArea(choice), job, size);


}
void filter_jobs_by_profession_5_2_3(Job** job, int size)
{
	int choice;
	char filter[] = "proffesion";

	printf("pls select one of 7 optionals proffesion:\n 1. Sales \n 2.Accounting and Finance \n 3.Logistics \n 4.Education and training \n 5.HiTech \n 6.Securing \n7. Restaurants\n");
	scanf("%d", &choice);

	while (choice < 1 || choice>7)
	{
		printf("invalid choice,try again");
		scanf("%d", &choice);
	}

	printbysomefilter(filter, getProfession(choice), job, size);

}
void filter_jobs_by_scope_5_2_4(Job** job, int size)
{
	int choice;
	char filter[] = "scope";

	printf("pls select one of 4 optionals scope:\n 1. Fulltime \n 2. Parttime \n 3. Temporaryjob \n 4. Motherjob \n");
	scanf("%d", &choice);

	while (choice < 1 || choice > 4)
	{
		printf("invalid choice,try again");
		scanf("%d", &choice);
	}

	printbysomefilter(filter, getScope(choice), job, size);
}
void filter_by_job_experience_5_2_5(Job** job, int size)
{
	int choice;
	char filter[] = "exprience";

	printf("pls select one of 2 optionals experience:\n 1. with_experience \n 2. without_experience \n ");
	scanf("%d", &choice);

	while (choice < 1 || choice >2)
	{
		printf("invalid choice,try again");
		scanf("%d", &choice);
	}

	printbysomefilter(filter, getExperience(choice), job, size);
}
void logingout_5_4()
{
	return;
}
