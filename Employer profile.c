#include<stdlib.h>
#include<stdio.h>
void EmployerProfile() :
{
	do
	{
		int choice;
		//����� ���� ����� �� �� �.� ...
		printf("1. Edit Profile\n0. Back to the previous menu\n");
		scanf("%d", choice);
		switch (choice)
		{
		case 1:
			//Edit
		case 0:
			return;

		default:
			printf("Error,try again.\n")
			break;
		}


	} while (choice);
}
