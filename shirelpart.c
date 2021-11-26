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
	Experience experience;
	char description[SIZE];
	char requirements[SIZE];
	bool status;//0-avalabe 1- ananabala
	char candidate1[SIZE2];
	char candidate2[SIZE2];
	char candidate3[SIZE2];
}Job;


const char* getArea(enum Area area) //פונקציה להכנסת מס וקבלת מחרוזת המייצגת את האופציה מתוך הenum
{
	switch (area)
	{
	case 1: return "Fulltime";
	case 2: return "Parttime";
	case 3: return "Temporaryjob";
	case 4: return "Motherjob";
	
	}
}

const char* getScope(enum Scope scope) //פונקציה להכנסת מס וקבלת מחרוזת המייצגת את האופציה מתוך הenum
{
	switch (scope)
	{
	case 1: return "North";
	case 2: return "South";
	case 3: return "Central";
	case 4: return "Jerusalem";

	}
}

const char* getProfession(enum Profession profession) //פונקציה להכנסת מס וקבלת מחרוזת המייצגת את האופציה מתוך הenum
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
const char* getExperience(enum Experience experience) //פונקציה להכנסת מס וקבלת מחרוזת המייצגת את האופציה מתוך הenum
{
	switch (experience)
	{
	case 1: return "with_experience";
	case 2: return "without_experience";
	
	}
}


void print_current_jobs(Job* Job) //הדפסת משרה נוכחית 
{
	printf(" Job name : %s \n Company name: %s \n Scope: %s \n  area : %s \n Job description :%s \n Requirements : %s \n Proffesion: %s \n candidate 1: ", Job.name, Job.companyName, getScope(thescope), getArea(thearea), Job.description, Job.requirements, getProfession(theproffesion));
}

void present_candidate_history_4(Candidate candidate) //הדפסת המשרות שהמועמד הגיש אליהן מועמדות
{
	int i = 0;
	while (job[i] != NULL)
	{
		if (job[i].status == 0)
		{
			if(strcmp(job[i].candidate1,candidate.id)==0|| strcmp(job[i].candidate2 ,mcandidate.id)==0||strcmp(job[i].candidate3,candidate.id)==0)
			print_current_jobs(&job[i]); //שליחת הכתובת של המצביע , הקיים בתא זה במערך
		}
		i++;
	}
}

void viewjobs_5()//פונקציה המציגה למשתמש את כל המשרות הקיימות - על פי בחירה
{
	int choice;
	do
	{
		printf("pls select one of 3 options :\n 1. view all the jobs \n 2. Filter by properties \n 3. Back to the main menu\n");
		scanf("%d", &choice);

		switch (choice) {

		case 1://5.1 // פונקציה המדפיסה את כל המשרות הקיימות ולאחריה תפריט המאפשר בחירה נוספת
			viewallthejobs_5_1(); //קריאה לפונ המדפיסה את כל המשרות
			break;
		case 2://5.2 + 5.2.1
			filterjobs_5_2();
			menuforfilterjobs_5_2_1();
		case 3://5.3
			break;
		default:
			printf("invalid choice , try again!");
		}

	} while (choice != 3);

}

void viewallthejobs_5_1()
{
	int choice;
		do
	{

		printf("pls select one of 3 options :\n 1. view all the jobs without filtering \n 2. apply \n 0. Back to the previous menu-view jobs \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1://הדפסת כל המשרות בלי סינון 
			printalljobs();
			break;
		case 2://apply 
			apply_5_1_1;
			break;
		case 0://back to the previous menu
			viewjobs_5();
			break;
		default:
			printf("invalid choice , try again!");

		}

	} while (choice != 0);
}
void apply_5_1_1(Candidate candidate)
{
	char jobid[SIZE];//מס מזהה של משרה 
	int i = 0;

	printf("Type in the ID number of the job to which you want to apply.");
	scanf("%s", jobid);

	while (job[i] != NULL)
	{
		if ((strcmp(job[i].id , jobid)==0) && (job[i].status == 0))
		{
			if (strcmp(job[i].candidate1 , '-')!=0)
			{
				job[i].candidate1 = candidate.id
					printf("the apply seccess !");
			}
			else if (strcmp(job[i].candidate2, '-') != 0)
			{
				job[i].candidate2 = candidate.id
				printf("the apply seccess !");
			}
			else if (strcmp(job[i].candidate3, '-')
			{
				job[i].candidate3 = candidate.id
				printf("the apply seccess !");
			}
			else
				printf("Oops! The max number of candidates who can apply for each job is 3.")
		}
		++i;
		else if(job[i]==NULL)
		printf("the job is unavailable")
	}
	
}

void printalljobs() //משתמשת בה בדרישה מס 5.1
{
	int i = 0;
	while (job[i] != NULL)
	{
		if(job[i].status == 0) // מערך של מצביעים- מערך כל המשרות הקיימות
		print_current_jobs(&job[i]); //שליחת הכתובת של המצביע , הקיים בתא זה במערך

		i++;
	}
}

void filterjobs_5_2()
{
	int choice;

	printf("pls select one of 4 filtering options  :\n 1. area \n 2. proffesional \n 3. job scope \n 4. job exeperience\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		filter_by_area_5_2_2();
		break;
	case 2:
		filter_jobs_by_profession_5_2_3();
		break;
	case 3:
		filter_jobs_by_scope_5_2_4();
		break;
	case 4:
		filter_by_job_exeperience_5_2_5();
		break;
	default:
		printf("invalid choice , try again!");

	}

}
void menuforfilterjobs_5_2_1()
{
	int choice;
	printf("pls press:\n 5. apply \n 0. back to previous menu- view jobs ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 5:
		apply_5_1_1();
		break;
	case 0:
		viewjobs_5();
		break;
	default:
		printf("invalid choice , try again!");
	}
}
void printbysomefilter(char filte[], char filtername[])//פונקציה שמדפיסה משרות לפי מאפייני סינון //לתקן
{
	int i = 0;
	while(job[i]!=NULL)
	{
		if (strcmp(job[i].filter, filtername) == 0)
			print_current_jobs(&job[i]); //שליחת הכתובת של המצביע , הקיים בתא זה במערך

		++i
			if(job[i]==NULL)
				printf("there is no job by this filter")
	}
}

void filter_by_area_5_2_2() //סינון לפי אזור
{
	int choice;
	char filter[] = "area"; //האם בסדר שלא רשמתי את אורך המחרוזת בתוך הסוגריים
	//char namefilter[M];

		printf("pls select one of 4 optionals area:\n 1. North\n 2. South\n 3.Central\n 4.Jerusalem\n");
		scanf("%d", &choice);

		while (choice < 1 || choice>4)
		{
			printf("invalid choice,try again");
			scanf("%d", &choice);
		}

	printbysomefilter(filter, getArea(choice));
	
	/*switch (choice)
	{
	case 1:
		strcpy(namefilter, "North");
		printbysomefilter(filter, namefilter);
		break;
	case 2:
		strcpy(namefilter, "South");
		printbysomefilter(filter, namefilter);
		break;
	case 3:
		strcpy(namefilter, "Central");
		printbysomefilter(filter, namefilter);
		break;
	case 4:
		strcpy(namefilter, "Jerusalem");
		printbysomefilter(filter, namefilter);
		break;
	default:
		printf("invalid choice , try again!");
	}*/
}


void filter_jobs_by_profession_5_2_3()
{
	int choice;
	char filter[] = "proffesion"; //האם בסדר שלא רשמתי את אורך המחרוזת בתוך הסוגריים

	printf("pls select one of 7 optionals proffesion:\n 1. Sales \n 2.Accounting and Finance \n 3.Logistics \n 4.Education and training \n 5.HiTech \n 6.Securing \n7. Restaurants\n");
	scanf("%d", &choice);

	while (choice < 1 || choice>7)
	{
		printf("invalid choice,try again");
		scanf("%d", &choice);
	}

	printbysomefilter(filter, getProfession(choice));

}

void filter_jobs_by_scope_5_2_4()
{
	int choice;
	char filter[] = "scope"; 

	printf("pls select one of 4 optionals scope:\n 1. Fulltime \n 2. Parttime \n 3. Temporaryjob \n 4. Motherjob \n");

	while (choice < 1 || choice>4)
	{
		printf("invalid choice,try again");
		scanf("%d", &choice);
	}

	printbysomefilter(filter, getScope(choice));
}

void filter_by_job_experience_5_2_5()
{
	int choice;
	char filter[] = "exprience";

	printf("pls select one of 2 optionals experience:\n 1. with_experience \n 2. without_experience \n ");

	while (choice < 1 || choice>2)
	{
		printf("invalid choice,try again");
		scanf("%d", &choice);
	}

	printbysomefilter(filter, getExperience(choice));
}




void logingout_5_4()
{
	return;
}












int main()
{
	int numofalljobs = 0;




	return 0;
}
