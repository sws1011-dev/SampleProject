#include <iostream>

using namespace std;

int main()
{
	char userName[50];

	cout << "[User Name] \n";
	cout << "Input your name:";
	cin >> userName;
	
	cout << ":::::::::::::Welcome to the D&D World ::::::::::::::\n";
	cout << "User Name : [" << userName << "]!\n";

	return 0;
}