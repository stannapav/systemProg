#include"lab4.h"
#include<iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Enter a for addition: ";
	cin >> a;
	cout << "Enter b for addition: ";
	cin >> b;	
	Addition(a, b);

	cout << "Enter a for subtraction: ";
	cin >> a;
	cout << "Enter b for subtraction: ";
	cin >> b;
	Subtraction(a, b);

	cout << "Enter a for multiplication: ";
	cin >> a;
	cout << "Enter b for multiplication: ";
	cin >> b;
	Multiplication(a, b);

	cout << "Enter a for division: ";
	cin >> a;
	cout << "Enter b for division: ";
	cin >> b;
	Division(a, b);

	char answer[10];
	cout << "Do you like cats?(yes/no): ";
	cin.ignore();
	cin >> answer;
	DoYouLikeCats(answer);

	return 0;
}