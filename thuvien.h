#include <iostream>
#include <string>
#pragma once

using namespace std;
const int MAX = 100;

typedef struct Student {
	int code{};
	char name[30]{};
	float subject[3]{}; //Math, English, c++
	float averageSubject = 0;
}STUDENT;
typedef struct ContigousListStudent {
	int n;
	STUDENT list[MAX];
}CLS;

void OutputListStudent(CLS m);
void OutputOneStudent(CLS m, int i);

void EmptyListStudent(CLS& m);

void deleteList(CLS &m);

void averageSubject(STUDENT& student);

void addNewStudent(CLS& m, int quantity);
void removeStudent(CLS& m, int n);

void searchByCode(CLS m, int code);
void searchByName(CLS m, char name[]);

void updateStudentInformation(STUDENT& sv);
void updateStudent(CLS& m, int code);

void splitDuplicateCode(CLS& m, CLS& m1);

void removeDuplicateCode(CLS& m);

bool joinAndSort(CLS& m, CLS m1, CLS m2);

bool checkSumGoodStudentHeadHalfListIsBiggerThanSumGoodStudentFollowingHalfList(CLS m);

void OutputBestStudent(CLS m);

void ShowMenu();
void menu(int n);