#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define MAX_GRADE 100
#define MIN_GRADE 0

//Q4
typedef struct
{
	char studentName[LEN];
	int studentGrade;
}Student;
//Q13
typedef struct
{
	Student* excellentSWEng;

}excellentSoftwareEngStudent;
//Requested functions.
Student** createArrayPointerToStudents(unsigned* n);
void getStudentsFromUser(Student* p[], unsigned n);
char** createArrayPointersToNames(unsigned* nex);
void getExcellentStudentsFromUser(char** names, const Student* p[], unsigned n, unsigned size);
void printArrayStudents(const Student A[], unsigned n);
//Added functions
Student** createArr(unsigned n);
char** createArrNames(unsigned nex);
Student* sortExcellentSoftwareStudents(const char* names[], const Student* p[], int size, int nex, int* newSize);
int checkGrade(int grade);
void cleanBuffer();
void printStudents(const Student* students[], unsigned n);
void printExSwStudents(const Student students[], unsigned n);
void freeMallocs(Student* p[], char* names[], int sizeOfStudents, int sizeOfNames);
void printExcStudentNames(const char* studentName[], unsigned nex);
int compareStudents(const void* a, const void* b);
int compareNames(const void* a, const void* b);
void sortStudentByAlphabet(const Student* p[], int sizeOfStudents, Student* sortArr[]);
void sortNamesByAlphabet(const char* names[], int sizeOfNames, char* sortArr[]);
//Q5
Student** createArrayPointerToStudents(unsigned* n)
{
	int i, size;
	printf("Please enter how many students do you have in software department:");
	scanf_s("%d", &size);
	Student** arr = (Student**)malloc(size * sizeof(Student*));

	if (!arr)
	{
		printf("ERROR! No more space.");
		return NULL;
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			arr[i] = (Student*)malloc(sizeof(Student) * LEN);
		}
	}
	*n = size;
	return arr;
}
Student** createArr(unsigned n)
{
	Student** arr = (Student**)malloc(n * sizeof(Student*));
	if (!arr)
	{
		printf("ERROR! No more space.");
		return NULL;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = (Student*)malloc(sizeof(Student) * LEN);
		}
	}
	return arr;
}
//Q6
void getStudentsFromUser(Student* p[], unsigned n)
{//Software department.
	int i, s_grade;
	int size = n;
	printf("\nSoftware department:\n--------------------\n");
	for (i = 0; i < size; i++)
	{
		printf("Please insert name for student #%d: ", i + 1);
		cleanBuffer();
		gets_s(p[i]->studentName, LEN);
		printf("Please insert grade for student number #%d: ", i + 1);
		scanf_s("%d", &s_grade);
		printf("\n");
		while (checkGrade(s_grade) != 1)
		{
			printf("Invalid grade.Please enter grade again: ");
			scanf_s("%d", &s_grade);
			checkGrade(s_grade);
		}
		if (checkGrade(s_grade) == 1)
		{
			p[i]->studentGrade = s_grade;
		}
	}
}
//Q7
char** createArrayPointersToNames(unsigned* nex)
{
	int i, size;
	printf("Please enter how many excellent students do you have from the whole college: ");
	scanf_s("%d", &size);
	char** ptrArrNames = (char**)malloc(size * sizeof(char*));

	if (!ptrArrNames)
	{
		printf("ERROR! No more space.");
		return NULL;
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			ptrArrNames[i] = (char*)malloc(sizeof(char) * LEN);
		}

	}
	*nex = size;
	return ptrArrNames;
}

char** createArrNames(unsigned nex)
{
	int i;
	char** ptrArrNames = (char**)malloc(nex * sizeof(char*));

	if (!ptrArrNames)
	{
		printf("ERROR! No more space.");
		return NULL;
	}
	else
	{
		for (i = 0; i < nex; i++)
		{
			ptrArrNames[i] = (char*)malloc(sizeof(char) * LEN);
		}

	}
	return ptrArrNames;
}
//Q8
void getExcellentStudentsFromUser(char** names, const Student* p[], unsigned n, unsigned size)
{
	int i, j, sizeOfNames = n, sizeOfStudents = size, counter = 0, flag;
	Student* tempStudent;
	tempStudent = p;
	char* tempName;
	char* excellentS;
	char** softwareEngEx = NULL;

	printf("Excellent students from the whole college:\n------------------------------------------\n");
	while (getchar() != '\n');
	for (i = 0; i < sizeOfNames; i++)
	{
		excellentS = (char*)malloc(sizeof(char) * LEN);
		printf("Please insert name for excellent student #%d: ", i + 1);
		gets_s(excellentS, LEN);
		printf("\n");
		for (j = 0, flag = 0; j < sizeOfStudents && flag != 1; j++)
		{
			tempName = (char*)malloc(sizeof(char) * LEN);
			strcpy(tempName, tempStudent[j].studentName);

			if (strcmp(excellentS, tempName) == 0)
			{
				names[i] = tempName;
				softwareEngEx = (char*)realloc(softwareEngEx, (counter) * sizeof(char));
				softwareEngEx[counter] = (char*)malloc(sizeof(char) * LEN);
				softwareEngEx[i] = tempName;
				flag = 1;
				counter++;

			}
		}
		if (flag == 0)
		{
			names[i] = excellentS;
			flag = 1;
		}
	}
}
int checkGrade(int grade)
{
	if (grade >= MIN_GRADE && grade <= MAX_GRADE)
		return 1;
	else
	{
		return 0;
	}

}
void printStudents(const Student* students[], unsigned n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%-10s\t%d", students[i]->studentName, students[i]->studentGrade);
		printf("\n");
	}
}
void printExcStudentNames(const char* studentName[], unsigned nex)
{
	for (int i = 0; i < nex; i++)
	{
		printf("%s\n", studentName[i]);
	}
}
void printExSwStudents(const Student students[], unsigned n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", students[i].studentName);
	}
}
void printArrayStudents(const Student A[], unsigned n)
{
	printf("Excellent students from the software major:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-10s	, %d", A[i].studentName, A[i].studentGrade);
		printf("\n");
	}
}
int compareStudents(const void* a, const void* b) {
	const Student* student1 = *(const Student**)a;
	const Student* student2 = *(const Student**)b;

	return strcmp(student1->studentName, student2->studentName);
}
int compareNames(const void* a, const void* b) {
	const char* name1 = *(const char**)a;
	const char* name2 = *(const char**)b;

	return strcmp(name1, name2);
}

void sortStudentByAlphabet(const Student* p[], int sizeOfStudents, Student* sortArr[])
{
	for (int i = 0; i < sizeOfStudents; i++)
	{
		strcpy(sortArr[i]->studentName, p[i]->studentName);
		sortArr[i]->studentGrade = p[i]->studentGrade;
	}
	qsort(sortArr, sizeOfStudents, sizeof(Student*), compareStudents);
}
void sortNamesByAlphabet(const char* names[], int sizeOfNames, char* sortArr[])
{
	for (int i = 0; i < sizeOfNames; i++)
	{
		strcpy(sortArr[i], names[i]);
	}
	qsort(sortArr, sizeOfNames, sizeof(char*), compareNames);
}
// Function to perform binary search on the sorted array of students
int binarySearch(const char* name, const Student* p[], int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		int cmp = strcmp(name, p[mid]->studentName);

		if (cmp == 0)
			return mid;
		else if (cmp < 0)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}
// Function to display the names of outstanding students from the software major
Student* sortExcellentSoftwareStudents(const char* names[], const Student* p[], int size, int nex, int* newSize) {
	int counter = 0;
	Student* arr = NULL;

	for (int i = 0; i < nex; i++) {
		int index = binarySearch(names[i], p, 0, size - 1);
		if (index != -1)
		{
			arr = (Student*)realloc(arr, (counter + 1) * sizeof(Student));
			strcpy(arr[counter].studentName, p[index]->studentName);
			arr[counter].studentGrade = p[index]->studentGrade;
			counter++;
		}
	}
	*newSize = counter;
	return arr;
}
void cleanBuffer()
{
	char c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
void printMenu()
{
	const char menu[] = "=====MENU========\n"
		"[1] - Print all students from software dep:\n"
		"[2] - Print the college excellent students:\n"
		"[3] - Sort the students from software dep. by name:\n"
		"[4] - Search and print excellent students from software dep:\n"
		"[5] - Create and print a new array consists of excellent students from software dep:\n"
		"\n[E/e] - Exit this program\n"
		"=============\n";
	puts(menu);

}



void freeMallocs(Student* p[], char* names[], int sizeOfStudents, int sizeOfNames)
{
	int i;
	for (i = 0; i < sizeOfStudents; i++) {
		free(p[i]);
	}
	free(p);

	for (i = 0; i < sizeOfNames; i++) {
		free(names[i]);
	}
	free(names);
}


void main()
{
	unsigned size, nex, exSwSize;
	Student** arr;
	Student** sortArr;
	Student* excSwStudentsArr;
	char** names;
	char** sortNames;
	char** p;

	arr = createArrayPointerToStudents(&size);
	names = createArrayPointersToNames(&nex);
	getStudentsFromUser(arr, size);
	getExcellentStudentsFromUser(names, arr, nex, size);
	sortArr = createArr(size);
	sortNames = createArrNames(nex);
	char choice = NULL;
	do {
		printMenu();
		choice = getchar();
		while (getchar() != '\n');
		switch (choice)
		{
		case '1':
			printStudents(arr, size);
			break;
		case '2':
			printExcStudentNames(names, nex);
			break;
		case '3':
			excSwStudentsArr = sortExcellentSoftwareStudents(names, arr, size, nex, &exSwSize);
			sortStudentByAlphabet(arr, size, sortArr);
			printStudents(sortArr, size);
			break;
		case '4':
			sortStudentByAlphabet(arr, size, sortArr);
			sortNamesByAlphabet(names, nex, sortNames);
			excSwStudentsArr = sortExcellentSoftwareStudents(sortNames, sortArr, size, nex, &exSwSize);
			printExSwStudents(excSwStudentsArr, exSwSize);
			free(excSwStudentsArr);
			break;
		case '5':
			sortStudentByAlphabet(arr, size, sortArr);
			sortNamesByAlphabet(names, nex, sortNames);
			excSwStudentsArr = sortExcellentSoftwareStudents(sortNames, sortArr, size, nex, &exSwSize);
			printArrayStudents(excSwStudentsArr, exSwSize);
			free(excSwStudentsArr);
			break;
		case 'E':
		case 'e':
			freeMallocs(arr, names, size, nex);
			printf("\nExiting program.\n");
			exit(0);
			break;
		default:
			printf("Invalid input.Please insert input again:");
			break;
		}
		printf("\n");
	} while (choice != 'e' && choice != 'E');
}