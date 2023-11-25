#include<Windows.h>
#include<iostream>

using namespace std;

typedef void (Operations)(int a, int b);
typedef void (Msg)(char *);

int main()
{
	HMODULE myLib = LoadLibrary(L"lab4.dll");
	Operations* addition = myLib ? (Operations*)GetProcAddress(myLib, "Addition") : NULL;
	Operations* subtraction = myLib ? (Operations*)GetProcAddress(myLib, "Subtraction") : NULL;
	Operations* multiplication = myLib ? (Operations*)GetProcAddress(myLib, "Multiplication") : NULL;
	Operations* division = myLib ? (Operations*)GetProcAddress(myLib, "Division") : NULL;
	Msg* doYouLikeCats = myLib ? (Msg*)GetProcAddress(myLib, "DoYouLikeCats") : NULL;

	int a, b;
	cout << "Enter a for addition: ";
	cin >> a;
	cout << "Enter b for addition: ";
	cin >> b;
	if(addition != NULL)
		addition(a, b);

	cout << "Enter a for subtraction: ";
	cin >> a;
	cout << "Enter b for subtraction: ";
	cin >> b;
	if (subtraction != NULL)
		subtraction(a, b);

	cout << "Enter a for multiplication: ";
	cin >> a;
	cout << "Enter b for multiplication: ";
	cin >> b;
	if (multiplication != NULL)
		multiplication(a, b);

	cout << "Enter a for division: ";
	cin >> a;
	cout << "Enter b for division: ";
	cin >> b;
	if (division != NULL)
		division(a, b);

	char answer[10];
	cout << "Do you like cats?(yes/no): ";
	cin.ignore();
	cin >> answer;
	if (doYouLikeCats != NULL)
		doYouLikeCats(answer);

	return 0;
}