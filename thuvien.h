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

void ShowMenu();
void menu(int n);
