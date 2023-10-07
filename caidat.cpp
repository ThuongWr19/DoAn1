#include "thuvien.h"

void printLine(int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "_";
	}
	cout << endl;
}

int& size(CLS& m) {
	return m.n;
}

void OutputListStudent(CLS m) {
	printLine(40);

	for (int i = 0; i < size(m); i++) {
		cout << "\nSerial: " << i + 1 << endl;
		cout << "Student code: " << m.list[i].code << endl;
		cout << "Student name: " << m.list[i].name << endl;
		cout << "Math\tEnglish\t C++" << endl;
		for (int j = 0; j < 3; j++) {
			cout << m.list[i].subject[j] << "\t ";
		}
		cout << "\nAverage subject: " << m.list[i].averageSubject << endl;
		printLine(40);
	}
	cout << endl;
}


void OutputOneStudent(CLS m, int i) {
	printLine(40);

	cout << "\nSerial: " << i + 1 << endl;
	cout << "Student code: " << m.list[i].code << endl;
	cout << "Student name: " << m.list[i].name << endl;
	cout << "Math\tEnglish\t C++" << endl;
	for (int j = 0; j < 3; j++) {
		cout << m.list[i].subject[j] << "\t ";
	}
	cout << "\nAverage subject: " << m.list[i].averageSubject << endl;
	printLine(40);
	cout << endl;
}

void EmptyListStudent(CLS& m) {
	size(m) = 0;
}

void deleteList(CLS& m) {
	if (size(m) > 0) {
		size(m) = 0;
	}
}

bool isFull(CLS m) {
	return size(m) >= MAX;
}

void averageSubject(STUDENT &student) {
	student.averageSubject = (student.subject[0] + student.subject[1] + student.subject[2]) / 3;
}

void removeStudent(CLS& m, int n) {
	for (int i = n; i < size(m)-1; i++) {
		m.list[i] = m.list[i + 1];
	}
	size(m)--;
}

void addNewStudent(CLS& m, int quantity) {
	Student stu{};
	for (int i = 1; i <= quantity; i++) {
		size(m)++;
		cout << "Enter code of new student [" << i << "]: ";
		cin >> m.list[size(m) - 1].code;

		cout << "Enter name of new student [" << i << "]: ";
		cin.ignore();
		cin.getline(m.list[size(m) - 1].name, 30);

		do {
			cout << "All subject only add when 0 < subject <= 10" << endl;
			cout << "Enter Math of new student [" << i << "] : ";
			cin >> m.list[size(m) - 1].subject[0];
			cout << "Enter English of new student [" << i << "] : ";
			cin >> m.list[size(m) - 1].subject[1];
			cout << "Enter C++ of new student [" << i << "] : ";
			cin >> m.list[size(m) - 1].subject[2];
			averageSubject(m.list[size(m) - 1]);
		} while (m.list[size(m) - 1].subject[0] < 0|| m.list[size(m) - 1].subject[0] > 10
				|| m.list[size(m) - 1].subject[1] < 0 || m.list[size(m) - 1].subject[1] > 10
				|| m.list[size(m) - 1].subject[2] < 0 || m.list[size(m) - 1].subject[2] > 10);
		cout << endl;
	}
}

void searchByCode(CLS m, int code) {
	int temp = 0;
	for (int i = 0; i < size(m); i++) {
		if (m.list[i].code == code) {
			temp = 1;
			OutputOneStudent(m, i);
			break;
		}
	}
	if (temp == 0) {
		cout << "No student have code: " << code;
	}
}

void searchByName(CLS m, char name[]) {
	int temp = 0;
	for (int i = 0; i < size(m); i++) {
		if (!strcmp(name, m.list[i].name)) {
			temp = 1;
			OutputOneStudent(m, i);
			break;
		}
	}
	if (temp == 0) {
		cout << "No student have name: " << name;
	}
}



void updateStudentInformation(STUDENT& student) {
	printLine(40);
	cout << "Enter new code student: ";
	cin >> student.code;

	cout << "Enter new name student: ";
	cin.ignore();
	cin.getline(student.name, 30);

	do {
		cout << "All subject only add when 0 < subject <= 10" << endl;
		cout << "Enter Math of new student: ";
		cin >> student.subject[0];
		cout << "Enter English of new student: ";
		cin >> student.subject[1];
		cout << "Enter C++ of new student: ";
		cin >> student.subject[2];
	} while (student.subject[0] < 0 || student.subject[0] > 10
		|| student.subject[1] < 0 || student.subject[1] > 10
		|| student.subject[2] < 0 || student.subject[2] > 10);
	averageSubject(student);
	printLine(40);
}

void updateStudent(CLS& m, int code) {
	int temp = 0;
	for (int i = 0; i < size(m); i++) {
		if (m.list[i].code == code) {
			temp = 1;
			printLine(40);
			cout << "\nUpdate student information with code: " << code;
			updateStudentInformation(m.list[i]);
			averageSubject(m.list[i]);
			break;
		}
	}
	if (temp == 0) {
		cout << "No student have code: " << code;
	}
}

void sortUpByAverageSubject(CLS& m) {
	STUDENT temp;
	for (int i = 0; i < size(m); i++) {
		for (int j = i + 1; j < size(m); j++) {
			if (m.list[i].averageSubject > m.list[j].averageSubject) {
				swap(m.list[j].averageSubject, m.list[j - 1].averageSubject);
			}
		}
	}
}

void splitDuplicateCode(CLS& m, CLS& m1) {
	size(m1) = 0;

	int codeTemp = 0;
	for (int i = 0; i < size(m); i++) {
		codeTemp = m.list[i].code;
		for (int j = 0; j < size(m); j++) {
			if ((codeTemp == m.list[j].code || m.list[i].code == m.list[j].code)) {
				if ((strcmp(m.list[j].name, m.list[i].name)) != 0 && j != i) {
					codeTemp = m.list[j].code;
					size(m1)++;
					m1.list[size(m1) - 1] = m.list[i];
					removeStudent(m, i);
					break;
				}
			}
		}
		if ((codeTemp == m.list[i].code) && size(m) > 1) {
			codeTemp = m.list[i].code;
			size(m1)++;
			m1.list[size(m1) - 1] = m.list[i];
			removeStudent(m, i);
			break;
		}
	}
}

void removeDuplicateCode(CLS& m) {
	int codeTemp = 0;
	for (int i = 0; i < size(m); i++) {
		codeTemp = m.list[i].code;
		for (int j = 0; j < size(m); j++) {
			if ((codeTemp == m.list[j].code || m.list[i].code == m.list[j].code)) {
				if ((strcmp(m.list[j].name, m.list[i].name)) != 0 && j != i) {
					codeTemp = m.list[j].code;
					removeStudent(m, i);
					break;
				}
			}
		}
		if ((codeTemp == m.list[i].code) && size(m) > 1) {
			codeTemp = m.list[i].code;
			removeStudent(m, i);
			break;
		}
	}
}

void SortUpByMath(CLS& m) {
	for (int i = 0; i < size(m) - 1; i++) {
		for (int j = size(m) - 1; j > i; j--) {
			if (m.list[j].subject[0] < m.list[j - 1].subject[0])
				swap(m.list[j], m.list[j - 1]);
		}
	}
}

bool joinAndSort(CLS& m, CLS m1, CLS m2) {
	for (int i = 0; i < size(m1); i++) {
		m.list[size(m)++] = m1.list[i];
	}
	for (int i = 0; i < size(m2); i++) {
		m.list[size(m)++] = m2.list[i];
	}
	SortUpByMath(m);
	OutputListStudent(m);

	return true;
}

int binarySearchByMath(CLS m, int x) {
	int left = 0, right = size(m) - 1;
	while (left <= right) {
		int i = (left + right) / 2;
		if (m.list[i].subject[0] == x) {
			return i;
		} else if (m.list[i].subject[0] < x) {
			left = i + 1;
		}
		else {
			right = i - 1;
		}
	}
	return -1;
}

bool CheckListIsAscendingMath(CLS m) {
	int count = 0;
	for (int i = 0; i < size(m) - 1; i++) {
		if (m.list[i + 1].subject[0] >= m.list[i].subject[0])
			count++;
	}
	if (count == size(m) - 1) 
		return true;
	else
		return false;
}

bool CheckListIsAscendingEnglish(CLS m) {
	int count = 0;
	for (int i = 0; i < size(m) - 1; i++) {
		if (m.list[i + 1].subject[1] >= m.list[i].subject[1])
			count++;
	}
	if (count == size(m) - 1)
		return true;
	else
		return false;
}

bool CheckListIsAscendingCPP(CLS m) {
	int count = 0;
	for (int i = 0; i < size(m) - 1; i++) {
		if (m.list[i + 1].subject[2] >= m.list[i].subject[2])
			count++;
	}
	if (count == size(m) - 1)
		return true;
	else
		return false;
}

bool CheckListIsDescendingMath(CLS m) {
	int count = 0;
	for (int i = 0; i < size(m) - 1; i++) {
		if (m.list[i+1].subject[0] <= m.list[i].subject[0])
			count++;
	}
	if (count == size(m) - 1)
		return true;
	else
		return false;
}

bool CheckListIsDescendingEnglish(CLS m) {
	int count = 0;
	for (int i = 0; i < size(m) - 1; i++) {
		if (m.list[i + 1].subject[1] <= m.list[i].subject[1])
			count++;
	}
	if (count == size(m) - 1)
		return true;
	else
		return false;
}

bool CheckListIsDescendingCPP(CLS m) {
	int count = 0;
	for (int i = 0; i < size(m)-1; i++) {
		if (m.list[i + 1].subject[2] <= m.list[i].subject[2])
			count++;
	}
	if (count == size(m) - 1)
		return true;
	else
		return false;
}


bool checkSumGoodStudentHeadHalfListIsBiggerThanSumGoodStudentFollowingHalfList(CLS m) {
	int count1 = 0, count2 = 0;
	for (int i = 0; i < size(m) / 2; i++) {
		if (m.list[i].averageSubject > 8)
			count1++;

		for (int j = size(m)/2; j > size(m); j--) {
			if (m.list[i].averageSubject > 8)
				count1++;
		}
	}
	if (count1 > count2)
		return true;
	else
		return false;
}

//Cau 15
void find2studentshavetotalmathscores(CLS m) {
	int temp = 0;
	for (int i = 1; i < size(m); i++) {
		for (int j = 0; j < size(m); j++) {
			if (m.list[i].subject[0] + m.list[j].subject[0] < 5 && i != j) {
				cout << "\n2 The first students have total math scores < 5: " << m.list[i].name << " & " << m.list[j].name;
				temp = 1;
				break;
			}
		}
		if (temp == 1)
			break;
	}


}

//Cau16
void addnewstudenntcheckalikecode(CLS& m, int quantity) {
	int h = 0;
	bool flag = true;
	for (int i = 1; i <= quantity; i++) {
		size(m)++;
		cout << "\nSinh vien thu " << i + 1 << endl;
		/*cout << "Enter code of new student [" << i << "]: ";
		cin >> m.list[size(m) - 1].code;*/
		do {
			int k = 0;
			cout << "Enter code of new student [" << i << "]: ";
			cin >> h;

			for (int t = 0; t < size(m); t++) {
				if (h == m.list[t].code)
					break;

				k++;
				if (size(m) == k)
					flag = false;
			}
		} while (flag);
		m.list[size(m) - 1].code = h;
		cout << "Enter name of new student [" << i << "]: ";
		cin.ignore();
		cin.getline(m.list[size(m) - 1].name, 30);

		do {
			cout << "All subject only add when 0 < subject <= 10" << endl;
			cout << "Enter Math of new student [" << i << "] : ";
			cin >> m.list[size(m) - 1].subject[0];
			cout << "Enter English of new student [" << i << "] : ";
			cin >> m.list[size(m) - 1].subject[1];
			cout << "Enter C++ of new student [" << i << "] : ";
			cin >> m.list[size(m) - 1].subject[2];
			averageSubject(m.list[size(m) - 1]);
		} while (m.list[size(m) - 1].subject[0] < 0 || m.list[size(m) - 1].subject[0] > 10
			|| m.list[size(m) - 1].subject[1] < 0 || m.list[size(m) - 1].subject[1] > 10
			|| m.list[size(m) - 1].subject[2] < 0 || m.list[size(m) - 1].subject[2] > 10);
	}
}
//Cau 17
void splitgoodstuddents(CLS& m, CLS& m1) {
	int d = 0; int s = 0;
	size(m1) = 0;
	//int j = 0;
	for (int i = 0; i < size(m); i++) {
		if (m.list[i].averageSubject / 3 >= 8) {
			size(m1)++;
			m1.list[size(m1) - 1] = m.list[i];
			s++;
			for (int k = i; k < size(m) - 1; k++)
				m.list[k] = m.list[k + 1];
			size(m)--;


		}
	}
	printLine(40);
	cout << "\n------------ Split list good students ------------ ";

	for (int g = 0; g < size(m1); g++) {
		cout << "\nSerial: " << g + 1 << endl;
		cout << "Student code: " << m1.list[g].code << endl;
		cout << "Student name: " << m1.list[g].name << endl;
		cout << "Math\tEnglish\t C++" << endl;
		for (int f = 0; f < 3; f++) {
			cout << m1.list[g].subject[f] << "\t ";
		}
		cout << "\nAverage subject: " << m1.list[g].averageSubject << endl;
		printLine(40);
	}
	cout << endl;
}
//Cau 19
void split3subjectstuddents(CLS& m, CLS& m2) {
	int d = 0;
	size(m2) = 0;
	for (int i = 0; i < size(m); i++) {
		if ((m.list[i].subject[0] > 6.5) && (m.list[i].subject[1] > 6.5) && (m.list[i].subject[2]) > 6.5) {
			size(m2)++;
			m2.list[size(m2) - 1] = m.list[i];
			for (int k = i; k < size(m) - 1; k++)
				m.list[k] = m.list[k + 1];
			size(m)--;



		}
	}

	printLine(40);
	cout << "\n------------ Split list of students with the best academic achievements in 3 subjects (>6.5) ------------ ";

	for (int g = 0; g < size(m2); g++) {
		cout << "\nSerial: " << g + 1 << endl;
		cout << "Student code: " << m2.list[g].code << endl;
		cout << "Student name: " << m2.list[g].name << endl;
		cout << "Math\tEnglish\t C++" << endl;
		for (int f = 0; f < 3; f++) {
			cout << m2.list[g].subject[f] << "\t ";
		}
		cout << "\nAverage subject: " << m2.list[g].averageSubject << endl;
		printLine(40);
	}
	cout << endl;
}

void OutputBestStudent(CLS m) {
	float maxAverageSubject = m.list[0].averageSubject;
	int index = 0;
	for (int i = 0; i < size(m); i++) {
		if (m.list[i].averageSubject > maxAverageSubject) {
			maxAverageSubject = m.list[i].averageSubject;
			index = i;
		}
	}
	OutputOneStudent(m, index);
}



void ShowMenu() {
	cout << endl;
	printLine(40);
	cout << "1. Create empty list of student." << endl;
	cout << "2. Delete list of student." << endl;
	cout << "3. Add new student." << endl;
	cout << "4. Remove student." << endl;
	cout << "5. Search student." << endl;
	cout << "6. Update student information." << endl;
	cout << "7. Sort list student by average subject." << endl;
	cout << "8. Split duplicate student code." << endl;
	cout << "9. Remove duplicate student code." << endl;
	cout << "10. Input 2 class to join and sort up ascending." << endl;
	cout << "11. Binary search math." << endl;
	cout << "12. Check list ascending." << endl;
	cout << "13. Check list descending." << endl;
	cout << "14. Check sum head half list is bigger than following half list." << endl;
	cout << "15. Find 2 the first students have total math scores > 5. " << endl;
	cout << "16. Add new student check alike code." << endl;
	cout << "17. Split good students. " << endl;
	cout << "18. Output." << endl;
	cout << "19. Split list studdents have score 3 subject > 6.5 . " << endl;
	cout << "20. Output best student." << endl;
	printLine(40);
	cout << endl;
}


void menu(int n) {
	ContigousListStudent m{}, m1{}, m2{}, m3{}, m4{};
	int x, n1, n2, n5, choose, code;
	char name[30];
	ShowMenu();
	do {
		switch (n) {
		case 1:
			system("cls");
			EmptyListStudent(m);
			cout << "Success create empty student list!"<< endl;
			ShowMenu();
			break;

		case 2:			
			if (size(m) > 0) {
				system("cls");
				deleteList(m);
				cout << "Success delete student list!" << endl;
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 3:
			system("cls");
			cout << "Enter quantity of new student: ";
			cin >> n5;
			addNewStudent(m, n5);
			cout << "Success add new student!" << endl;
			ShowMenu();  
			break;

		case 4:
			if (size(m) > 0) {
				int temp = 0;
				system("cls");
				cout << "Enter student code you want to remove: ";
				cin >> code;
				for (int i = 0; i < size(m); i++) {
					if (m.list[i].code == code) {
						temp = 1;
						removeStudent(m, i);
						cout << "Success delete student with code: " << code;
					}
				}
				cout << endl;
				if (temp == 0) {
					cout << "No student have code: " << code;
				}
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 5:
			if (size(m) > 0) {
				system("cls");
				cout << "What do you want to search by?" << endl;
				cout << "1. Code\t 2.Name" << endl;
				cin >> choose;
				if (choose == 1) {
					cout << "Enter code to search: ";
					cin >> code;
					searchByCode(m, code);
					ShowMenu();
					break;
				}
				else {
					cout << "Enter name to search: ";
					cin.ignore();
					cin.getline(name, 30);
					searchByName(m, name);
					ShowMenu();
					break;
				}
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 6:
			if (size(m) > 0) {
				system("cls");
				cout << "Enter student code you want to update information: ";
				cin >> code;
				updateStudent(m, code);
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 7:
			if (size(m) > 0) {
				system("cls");
				sortUpByAverageSubject(m);
				cout << "Succesful sort list by average subject!";
				OutputListStudent(m);
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}
		case 8:
			if (size(m) > 0) {
				system("cls");
				splitDuplicateCode(m, m1);
				cout << "Succesful split duplicate student code!";
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 9:
			if (size(m) > 0) {
				system("cls");
				removeDuplicateCode(m);
				cout << "Succesful remove all duplicate student code!";
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 10:
				system("cls");	
				cout << "Enter quantity of new student in class 1: ";
				cin >> n1;
				addNewStudent(m2, n1);
				cout << endl;
				cout << "Enter quantity of new student in class 2: ";
				cin >> n2;
				addNewStudent(m3, n2);
				system("cls");
				cout << "Succesful join 2 class and sort up ascending! Here's the result";
				joinAndSort(m4, m2, m3);
				ShowMenu();
				break;

		case 11:
			if (size(m4) > 0) {
				system("cls");
				cout << "Enter a number you want to search: ";
				cin >> x;
				if (binarySearchByMath(m4, x) >= 0) {
					OutputOneStudent(m4, binarySearchByMath(m4, x));
				}
				else {
					cout << "No result!";
				}
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 12:
			if (size(m) > 0) {
				system("cls");
				cout << "What do you want to test the ascending array about?" << endl;
				cout << "1. Math\t2.English\t3.C++";
				cin >> x;
				if (x == 1) {
					if (CheckListIsAscendingMath(m))
						cout << "This list is asscending math!";
					else
						cout << "This list is not asscending math!";
				}
				if (x == 2) {
					if (CheckListIsAscendingEnglish(m))
						cout << "This list is asscending english!";
					else
						cout << "This list is not asscending english!";
				}
				if (x == 3) {
					if (CheckListIsAscendingCPP(m))
						cout << "This list is asscending C++!";
					else
						cout << "This list is not asscending C++!";
				}
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 13:
			if (size(m) > 0) {
				system("cls");
				cout << "What do you want to test the descending array about?" << endl;
				cout << "1. Math\t2.English\t3.C++";
				cin >> x;
				if (x == 1) {
					if (CheckListIsDescendingMath(m))
						cout << "This list is descending math!";
					else
						cout << "This list is not descending math!";
				}
				if (x == 2) {
					if (CheckListIsDescendingEnglish(m))
						cout << "This list is descending english!";
					else
						cout << "This list is not descending english!";
				}
				if (x == 3) {
					if (CheckListIsDescendingCPP(m))
						cout << "This list is descending C++!";
					else
						cout << "This list is not descending C++!";
				}
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}
		case 14:
			if (size(m) > 0) {
				system("cls");
				if (checkSumGoodStudentHeadHalfListIsBiggerThanSumGoodStudentFollowingHalfList(m)) {
					cout << "Sum good head half list is bigger than sum good following half list!" << endl;
				}
				else {
					cout << "Sum good head half list is NOT bigger than sum good following half list!" << endl;
				}
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		case 15:
			system("cls");
			find2studentshavetotalmathscores(m);
			ShowMenu();
			break;

		case 16:
			system("cls");
			cout << "Enter quantity of new student";
			cin >> n;
			addnewstudenntcheckalikecode(m, n);
			ShowMenu();
			break;

		case 17:
			system("cls");
			splitgoodstuddents(m, m1);
			cout << "\n------------ List of old students ------------ " << endl;
			OutputListStudent(m);
			ShowMenu();
			break;

		case 18:
			if (size(m) > 0) {
				system("cls");
				OutputListStudent(m);
				if (m1.n > 0) {
					cout << "List student have duplicate code";
					OutputListStudent(m1);
				}
				ShowMenu();
				break;
			}

			else {
				system("cls");
				cout << "No any student in list!";
				ShowMenu();
				break;
			}

		case 19:
			system("cls");
			split3subjectstuddents(m, m2);
			cout << "\n------------ List of old students ------------ " << endl;
			OutputListStudent(m);
			ShowMenu();
			break;


		case 20:
			if (size(m) > 0) {
				system("cls");
				cout << "Here's the best student!";
				OutputBestStudent(m);
				ShowMenu();
				break;
			}
			else {
				system("cls");
				cout << "No student in list!";
				ShowMenu();
				break;
			}

		

			
		default:
			cout << "Enter wrong number! Choose again." << endl;
			break;
		}
		cout << "Enter number to run: ";
		cin >> n;
	} while (n != 0);
}