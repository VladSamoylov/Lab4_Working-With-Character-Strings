#include "iostream"
#include "string.h"
#include "string"

using namespace std;

/**
 * @brief �������� �������� �������� ���� int, ��� ��� ���������� �� �������
 * @param i �������� ���� int ������� � ���������
 * @return ������� �������� �������� ��� �������� ������ �������
*/
int CheckIntValue(int* i) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> *i;
		}
		else {
			return *i;
		}
	}
}

/**
 * @brief �������� �������� �������� �������, ��� ��� ����������
 * @param symbol ������ �������� � ���������
 * @return ������� ��������� ������ �� �������
*/
char CheckCharValue(char* symbol) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> *symbol;
		}
		else {
			return *symbol;
		}
	}
}

/**
 * @brief ��������, �� ���������� ��� ���� ���� �����
 * @param word ����� ������� � ���������
 * @return ������� ���� ����� �� �������
*/
string CheckOneWordString(string* word) {
	
	cin.ignore(666, '\n');
	return *word;
}

/**
 * @brief ��������, ��� ������ ��� ������
 * @param symbol ������ �������� � ���������
 * @return ������� �������� ����� �� �������
*/
char CheckThisLetter(char* symbol) {
	int new_symbol;

	while (true) {
		if (int(*symbol) >= 65 && int(*symbol) <= 122) {
			if (int(*symbol) >= 65 && int(*symbol) <= 90) {
				new_symbol = int(*symbol) + 32;
				*symbol = char(new_symbol);
				return *symbol;
			}
			else {
				return *symbol;
			}			
		}
		else {
			cout << "You enter wrong data! Please enter Only Letter: \n";
			cin >> *symbol;
			*symbol = CheckCharValue(&*symbol);
		}
	}	
}

/**
 * @brief ������� ������ ���� ����� ����������� � ����� �� ������� ������ 5
 * @param symbol ˳���� ������� ������������ � ���������
*/
void DetermineHowManyTimesGivenLetterMultiplesOf5(char* symbol) {
	string str("determine how many times a given letter occurs in a given string in positions that are multiples of 5a.");
	int count = 0; 

	for (int i = 4; i < str.length(); i += 5) {
		if (str[i] == *symbol) {
			count++;
		}
	}
	cout << "The target letter: " << *symbol << " meets - " << count << " times.";
}

/**
 * @brief ������� ������ � ��������� ����� � ����� ����� 
*/
void IdentifyTheSymbolWithLargestCode() {
	char set_string[10][25] = { "How do you do", "It's Okey?", "Really it!", "Number: 22131345449", "!@3$%^&*()[]", "yep this is true!", "{imac restal god cod", " -=+*/-", "   sda   ", "333zizi" };
	char largest_code = ' ';

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 25; j++) {
			if (int(set_string[i][j]) > int(largest_code)) {
				largest_code = set_string[i][j];
			}
		}
	}
	cout << "The symbol: " << largest_code << " is largest code: " << (int)largest_code;		
}

/**
 * @brief �������� ������ ����� ������������ � ����� ����� ���� ������� ����� �����
 * @param word ����� ������� ������������ � ���������
*/
void InsertWordInTheString(string* word) {
	string str = "This string is the best string in the world";
	int space_pos;

	space_pos = str.find(" ");
	str.insert(space_pos, *word);
	cout << str << endl;
}

/**
 * @brief ��������� ���� �� ����� ����������� ��������� � ��������
 * @param q ���� ������������ ��������, ��� �������� ������������ � ���������
 * @return ������� ���� ���� ��� ����������� ������ ����������� � ��������
*/
int MenuOfSolution(int* q) {
	char symbol;
	string word;

	switch (*q) {
	case 1:
		cout << "\n__Task A__\n";
		cout << "Enter amount members of masive A: ";
		IdentifyTheSymbolWithLargestCode();
		return 0;
	case 2:
		cout << "\n__Task B__\n";
		cout << "Enter amount of Teams: ";
		cin >> symbol;
		symbol = CheckCharValue(&symbol);
		symbol = CheckThisLetter(&symbol);
		DetermineHowManyTimesGivenLetterMultiplesOf5(&symbol);
		break;
	case 3:
		cout << "\n__Task C__\n";
		cout << "Enter number of colums: ";
		cin >> word;
		word = CheckOneWordString(&word);
		//getline(cin, word);
		word.insert(0, " ");
		InsertWordInTheString(&word);
		break;
	default:
		cout << "\n__You don't enter any task for execution__\n";
		return 0;
	}
	return MenuOfSolution(q);
}

int main() {

	int q;
	cout << "\nCreated by Vladislav Samoilov / KNT - 223\n";

	cout << "--------Select task:--------\n";
	cout << "Task A) Identify The Symbol With Largest Code in the matrix - Enter 1\n";
	cout << "Task B) Determine How Many Times Given Letter Multiples Of 5 - Enter 2\n";
	cout << "Task C) Insert Word In The String - Enter 3\n";
	cout << "------------------------------------------------------------\n";
	cin >> q;
	q = CheckIntValue(&q);
	MenuOfSolution(&q);

	return main();
}