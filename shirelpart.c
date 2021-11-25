#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define M 30

struct Date
{
	int day;
	int month;
	int year;
};

struct Job
{
	long idnum_of_job;
	char jobName[N];
	char companyName[N];
	enum scope scope;
	enum positionArea area;
	char jobDescription[M];
	char requirements[M];
	enum profession profession;
	int numofcandidate;

};

struct Employer
{
	char name[N];
	//Date birthday;
	long id;
	long phoneNumber;
	char companyName[N];
	char companyDescription[M];
	Job* employer_jobarray; //���� ������ ������� ����

};
struct Candidate
{
	char name[N];
	//Date birthday;
	long id;
	long phoneNumber;
	char education[M];
	char workexperience[M];
	Job* c_jobarray; //���� ������ ������� ���� ����� �������
	//int numofjobs=0;

};

int numofalljobs = 0; //��� ��� �� ����� ����� ������ �� �� �� ������?

void print_current_jobs(Job* job) //����� ���� ������ 
{
	printf(" Job name : %s \n Company name: %s \n Scope: %d \n Position area : %d \n Job description :%s \n Requirements : %s \n Proffesion: %d", job.jobName, job.companyName, job.scope, job.area, job.jobDescription, job.requirements, job.profession);
}

void present_candidate_history_4() //����� ���� ������ ������� ���� ����� �������
{
	/*����� ���� ����� ������ ������ ���� ���� �����:
	* ��� ��� ����� ����� ��� ������ , ������ ����� ������ ���� ��� , �� �� ����� ����� ���� ������ .
	* 1.������ ����� �� �� ���� ������� �� ������ �� ����� , ���� ���� .
	* 2.��� ��� ������� ���� ������� ����� , ������ ����� ����� �� ���� ����� �� ���� ����� ,���� ����.
	* ����� ���� �� ������ ���������� ����.
	* 3.���� ������ ���� ����� ������ ����� ���� ������� , ������ ����� ������ -��� ������ �� ����� ����� �������
	* ��� ���� ��� ���� ������ ��� ������ ���� ������  �� ��� ����.
	* ���� ����� ���� ����������.
	* 4.���� �������� ����� �� ����� �� ����� ������ - ��� ����� �� ����� ������� �� ��� �����
	* ���� ��� ���� �����.
	*/
	int i = 0;
	while (c_jobarray[i] != NULL)//������ ����� ������� ���� ���� ����� ����
	{
		print_current_jobs(&c_jobarray[i]); //����� ������ �� ������ , ����� ��� �� �����
		i++;
	}
}
void viewjobs_5()//������� ������ ������ �� �� ������ ������� - �� �� �����
{
	int choice;
	do
	{
		printf("pls select one of 3 options :\n 1. view all the jobs \n 2. Filter by properties \n 3. Back to the main menu\n");
		scanf("%d", &choice);

		switch (choice) {

		case 1://5.1 // ������� ������� �� �� ������ ������� ������� ����� ������ ����� �����
			printalljobs(); //����� ���� ������� �� �� ������
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
	long jobid;//�� ���� �� ���� 
	int j = numofalljobs;
	do
	{

		printf("pls select one of 3 options :\n 1. view all the jobs without filtering \n 2. apply \n 0. Back to the previous menu-view jobs \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1://����� �� ������ ��� ����� 
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
void apply_5_1_1()
{
	long jobid;//�� ���� �� ����

	printf("Type in the ID number of the position to which you want to apply.");
	scanf("%ld", &jobid);

	for (int i = 0; i < j; i++)
	{
		if (jobarray[i].idnum_of_job == jobid)
		{
			numofalljobs++;
			/*����� �������� ������ �� ������ ����� , �������� ����� �� ����� ����� ���� ����� �� ������
			��� �� ����� ����� �� ���� ����� �� ����� ����� �� ������
			*/
		}
	}
	printf("the apply seccess !");
}

void printalljobs() //������ �� ������ �� 5.1
{
	int i = 0;
	while (jobarray[i] != NULL || jobarray[i].status) // ���� �� �������- ���� �� ������ �������
	{
		print_current_jobs(&jobarray[i]); //����� ������ �� ������ , ����� ��� �� �����
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
		filterbyrea_5_2_2();
		break;
	case 2:
		filterjobsbyprofession_5_2_3();
		break;
	case 3:

		break;
	case 4:

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
void printbysomefilter(char filte[], char filtername[])//������� ������� ����� ��� ������� ����� 
{
	for (int i = 0; i < numofalljobs; i++)
	{
		if (strcmp(jobarray[i].filter, filtername) == 0)
			print_current_jobs(&jobarray[i]); //����� ������ �� ������ , ����� ��� �� �����
	}
}

void filterbyrea_5_2_2() //����� ��� ����
{
	int choice;
	char filter[] = "area"; //��� ���� ��� ����� �� ���� ������� ���� ��������
	char namefilter[M];
	printf("pls select one of 4 optionals area:\n 1. North\n 2. South\n 3.Central\n 4.Jerusalem\n");
	scanf("%d", &choice);
	switch (choice)
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
	}
}


void filterjobsbyprofession_5_2_3()
{
	int choice;
	char filter[] = "proffesion"; //��� ���� ��� ����� �� ���� ������� ���� ��������
	char namefilter[M] = "";
	printf("pls select one of 7 optionals proffesion:\n 1. Sales \n 2.Accounting and Finance \n 3.Logistics \n 4.Education and training \n 5.HiTech \n 6.Securing \n7. Restaurants\n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		strcpy(namefilter, "Sales");
		printbysomefilter(filter, namefilter);
		break;
	case 2:
		strcpy(namefilter, "Accounting and Finance");
		printbysomefilter(filter, namefilter);
		break;
	case 3:
		strcpy(namefilter, "Logistics");
		printbysomefilter(filter, namefilter);
		break;
	case 4:
		strcpy(namefilter, "Education and training");
		printbysomefilter(filter, namefilter);
		break;
	case 5:
		strcpy(namefilter, "HiTech");
		printbysomefilter(filter, namefilter);
		break;
	case 6:
		strcpy(namefilter, "Securing");
		printbysomefilter(filter, namefilter);
		break;
	case 7:
		strcpy(namefilter, "Restaurants");
		printbysomefilter(filter, namefilter);
		break;
	default:
		printf("invalid choice , try again!");
	}
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
