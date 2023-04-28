
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define MAX_GRADE 100
#define MIN_GRADE 0
typedef struct 
{
	char studentName[LEN];
	int studentGrade;
} Student;

Student** createArrayPointerToStudnets(unsigned* n);
void getStudentsFromUser(Student* p[], unsigned n);

Student** createArrayPointerToStudnets(unsigned* n)
{	
	int i, size;
	printf("Please enter number of students: ");
	scanf_s("%d", &size);
	Student** arr = (Student**)malloc(size * sizeof(Student*));
	if(!arr)
		return NULL;
	for (i = 0; i < size; i++)
	{
		arr[i] = i + 1;
		*n = size;
		return arr;
	}
}
void getStudentsFromUser(Student* p[], unsigned n)
{
	//int i;
	//int* ptrGrade;
	//char* studentName = '\0';
	//for (i = 0; i < n; i++) 
	//{
	//	printf_s("Please enter student name: ");
	//	puts(p[i] -> studentName);
	//	printf_s("Please enter student grade: ");
	//	scanf_s("%d", ptrGrade);
	//	if (*ptrGrade < MIN_GRADE || *ptrGrade > MAX_GRADE)
	//	{
	//		printf_s("Invalid grade\nPlease enter grade again.");
	//		scanf_s("%d", ptrGrade);
	//	}
	//	else
	//	{
	//		p[i]-> studentGrade = *ptrGrade;
	//	}
	//}
}
void main()
{
	int size;
	Student** arr;
	arr = createArrayPointerToStudnets(&size);
	//getStudentsFromUser(arr, size);
	char choice;
	char* menu = "[1] - Show list of all software engineer department students.\n"
		"[2] - Show names of all excellent students.\n"
		"[3] - Sort student's names order by alphabet and print.\n"
		"[4] - Show names of all excellent students from software engineer department and sort them by alphabet.\n"
		"[5] - Create new struct of excellent students from software engineer department.\n"
		"[E/e] - Exit this program:";
	do {
		printf("%s", menu);
		choice = getchar();
		switch (choice)
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case 'E':
		case 'e':
			printf("\nExiting program.\n");
			break;
		default:
			printf("Invalid input.\nplease enter input again.");
			break;
		}
	} while (choice != 'e' && choice != 'E');
		


	
}


