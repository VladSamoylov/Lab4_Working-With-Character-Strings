#include "iostream"
#include "string.h"
#include "string"

using namespace std;

/**
 * @brief Перевіряє коректне значення типу int, яке ввів користувач до системи
 * @param i Значення типу int введене з клавіатури
 * @return Повертає коректне значення для подальшої роботи системи
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
 * @brief Перевіряє коректне значення символа, яке ввів користувач
 * @param symbol Символ введений з клавіатури
 * @return Повертає коректний символ до системи
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
 * @brief Перевіряє, щоб символ був літерою
 * @param symbol Символ введений з клавіатури
 * @return Повертає коректну літеру до системи
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
 * @brief Визначає скільки разів літера зустрічається у рядку на позиції кратній 5
 * @param symbol Літера введена користувачем з клавіатури
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
 * @brief Визначає символ з найбільшим кодом у наборі рядків 
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
 * @brief Інтерфейс який дає змогу користувачу працювати з додатком
 * @param q Вибір виконуваного завдання, яке задається користувачем з клавіатури
 * @return Повертає сама себе для продовження роботи користувача з додатком
*/
int MenuOfSolution(int* q) {
	char symbol;

	switch (*q) {
	case 1:
		cout << "\n__Task A__\n";
		cout << "Enter amount members of masive A: ";
		IdentifyTheSymbolWithLargestCode();
		//break;
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
		break;
	case 4:
		cout << "\n__Task D__\n";
		cout << "Enter number of colums: ";
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
	cout << "Task A) Fill masive A and created masive B - Enter 1\n";
	cout << "Task B) Find the team goes second place - Enter 2\n";
	cout << "Task C) Calculate Amount Of Abs Negative Elements - Enter 3\n";
	cout << "Task D) Amount Sequence Members - Enter 4\n";
	cout << "------------------------------------------------------------\n";
	cin >> q;
	q = CheckIntValue(&q);
	MenuOfSolution(&q);

	return main();
}