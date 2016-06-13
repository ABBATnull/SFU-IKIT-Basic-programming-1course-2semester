#include <cmath>
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <fstream>
//#include <windows.h>

using namespace std;

void see_you() {
	cout << "\t\t\t\t\t\tS";
	Sleep(150);
	cout << "e";
	Sleep(150);
	cout << "e";
	Sleep(150);
	cout << " ";
	Sleep(150);
	cout << "y";
	Sleep(150);
	cout << "o";
	Sleep(150);
	cout << "u";
	Sleep(150);
	cout << " ";
	Sleep(150);
	cout << "n";
	Sleep(150);
	cout << "e";
	Sleep(150);
	cout << "x";
	Sleep(150);
	cout << "t";
	Sleep(150);
	cout << " ";
	Sleep(150);
	cout << "t";
	Sleep(150);
	cout << "i";
	Sleep(150);
	cout << "m";
	Sleep(150);
	cout << "e";
	Sleep(150);
	cout << "!";
	Sleep(2000);
}

void show() {
	cout << "\t\t\t\t\t�������� - ������ 1.0 (BETA)\n\n\n";
	cout << "\t\t\t\t\t\tW";
	Sleep(150);
	cout << "e";
	Sleep(150);
	cout << "l";
	Sleep(150);
	cout << "c";
	Sleep(150);
	cout << "o";
	Sleep(150);
	cout << "m";
	Sleep(150);
	cout << "e";
	Sleep(150);
	cout << "!";
	Sleep(2000);
	cout << "\n\n\nLoading";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(300);
	system("cls");
}

//---------------------------------

void gorizontal(char* mass, int N, char* buff, int* check, int lol, char symb, int &a, int &b)
{
	int schet = 0, i, u = 0, k = 0, p = 0, pilla = 0, final = 0;
	for (i = 0; i<lol; i++)
		check[i] = 0;
	for (i = 0; i < lol; i++)
	{
		buff[i] = mass[u + (lol*(a - 1))];
		u++;
	}
	for (i = 0; i<lol; i++)
		if (buff[i] == symb) { schet++; check[pilla] = schet; }
		else { schet = 0; pilla++; }
		for (i = 0; i<N; i++)
			if (check[i] >= 5)   p = 1;
		cout << "\n-----------------------------------";
		cout << "\n���������:\n";
		if (p == 1) cout << "������� ���� ������ ������ '" << symb << "' � �������������� ����!";
		else
			cout << "���� ������ ������ '" << symb << "' � �������������� ���� �� ����������!";
		cout << "\n-----------------------------------\n\n";
}

//---------------------------------

void vertikal(char* mass, int N, char* buff, int* check, int lol, char symb, int &a, int &b)
{
	int i, k = 0, u = 0, p = 0, schet = 0, pilla = 0, final = 0;
	for (i = 0; i<lol; i++)
		check[i] = 0;
	for (i = 0; i < lol; i++)
	{
		buff[i] = mass[(b - 1) + u];
		u = u + lol;
	}
	for (i = 0; i<lol; i++)
		if (buff[i] == symb) { schet++; check[pilla] = schet; }
		else { schet = 0; pilla++; }
		for (i = 0; i<N; i++)
			if (check[i] >= 5)   p = 1;
		cout << "\n-----------------------------------";
		cout << "\n���������:\n";
		if (p == 1) cout << "������� ���� ������ ������ '" << symb << "' � ������������ ����!";
		else
			cout << "���� ������ ������ '" << symb << "' � ������������ ���� �� ����������!";
		cout << "\n-----------------------------------\n\n";
}

//---------------------------------

void diagonal(char* mass, int N, char* buff, int* check, int lol, char symb, int &a, int &b)
{
	int i, t, k, schet = 0, s = 0, u, p = 0, pilla = 0, final = 0, ind, sdv, korr, gl, pb;
	for (i = 0; i<lol; i++)
		check[i] = 0;
	ind = ((a - 1)*lol) + (b - 1);
	sdv = lol + 1;
	gl = sdv*(a - 1);
	korr = lol - abs(ind - gl);
	u = ind - ((a - 1)*sdv);
	for (i = 0;i < korr;i++)
	{
		buff[i] = mass[u];
		u = u + sdv;
	}
	for (i = 0; i<korr; i++)
		if (buff[i] == symb) { schet++; check[pilla] = schet; }
		else { schet = 0; pilla++; }
		schet = 0;
		pilla++;
		sdv = lol - 1;
		pb = sdv*a;
		korr = lol - abs(ind - pb);
		u = ind - ((a - 1)*sdv);
		for (i = 0;i < korr;i++)
		{
			buff[i] = mass[u];
			u = u + sdv;
		}
		for (i = 0; i<korr; i++)
			if (buff[i] == symb) { schet++; check[pilla] = schet; }
			else { schet = 0; pilla++; }
			for (i = 0; i<N; i++)
				if (check[i] >= 5)   p = 1;
			cout << "\n-----------------------------------";
			cout << "\n���������:\n";
			if (p == 1) cout << "������� ���� ������ ������ '" << symb << "' � ������������ ����!";
			else
				cout << "���� ������ ������ '" << symb << "' � ������������ ���� �� ����������!";
			cout << "\n-----------------------------------\n\n";
}

//--------------------------------- 

void instructagh() {
	cout << "-----------------------------------";
	cout << "\n\n��� ������: \n\n";
	cout << "������ �� ������ ������� ���������� ��� '���������' � ��� '�������'.\n���������� �������� ����� ������!\n";
	cout << "������� �������� ���������� ��� ������, � ����� ��� �������.\n\n";
	cout << "����� ����� ���������� ��������� ������� ���� ������ ������ ���������� �������� �� ���������� �������������\n";
	cout << "�� �����������, ��������� ��� ���������, �������: '0'\n\n";
	cout << "-----------------------------------\n\n";
	system("pause");
	system("cls");
}

//---------------------------------

void instruchtagh2(char symb) {
	cout << "-----------------------------------\n";
	cout << "������ ���������� ��������� ����������� �� ���� ������ '" << symb << "'\n";
	cout << "�� �����������, ��������� ��� ���������.\n\n";
	cout << "�������� ������ �������:\n1. ��������� �� �����������\n2. ��������� �� ���������\n3. ��������� �� ���������";
	cout << "\n-----------------------------------\n";
}

//---------------------------------

void vivod_mass(int N, int i, char* mass) {
	cout << "������� ����:\n\n";
	for (i = 0; i < N; i++) {
		if (fmod(i + 1, sqrt(N)) == 0)
			cout << mass[i] << "\n";
		else
			cout << mass[i] << " ";
	}
	cout << "\n";
}

//--------------------------------------

int vvod_coordinat(char symb, int custom, int i, int N, char* mass, int &a1, int &b1) {
	int a, b;
	cout << "\n>> ";
	cin >> a;
	if (a == 0)
	{
		system("cls");
		return 1;
	}
	else {
		cin >> b;
		if (a == 1)
			custom = b;
		else
			custom = sqrt(N)*(a - 1) + b;
		mass[custom - 1] = symb;
	}
	a1 = a;
	b1 = b;
	system("cls");
	return 0;
}

//--------------------------------------

void nolik() {
	cout << "------------------\n";
	cout << "�� - �����       |\n";
	cout << "------------------\n";
}

//--------------------------------------

void krestik() {
	cout << "------------------\n";
	cout << "�� - �������     |\n";
	cout << "------------------\n";
}

int main() {
	int i, N, custom = 0, a1, b1, choice = 0, choose;
	typedef void(*MENU) (char*, int, char*, int*, int, char, int&, int&);
	MENU menu1[3] = { gorizontal, vertikal, diagonal };
	char symb = 'O';
	bool exit = 0;
	setlocale(LC_ALL, "Rus");
	show();
	cout << "������� ����������� �������� ����������� ����\nP.S. ������� ���� ������ ���� �� 5�5 � ������\n\n>> ";
	cin >> N;
	while (N < 5) {
		system("cls");
		cout << "������! ������� ���� ������ ���� �� 5�5 � ������!\n������� ����������� �������� ����������� ���� �����!\n\n>> ";
		cin >> N;
	}
	N *= N;
	int lol = sqrt(N);
	char* buff = new char[lol];
	int* check = new int[N];
	char* mass = new char[N];
	cout << "\n\n";
	for (i = 0; i < N; i++) mass[i] = '.';
	system("cls");
	vivod_mass(N, i, mass);
	instructagh();
	vivod_mass(N, i, mass);
	while (choice != 4)
	{
		system("cls");
		vivod_mass(N, i, mass);
		if (symb == 'O')
		{
			symb = 'X';
			krestik();
		}
		else
		{
			symb = 'O';
			nolik();
		}
		choice = vvod_coordinat(symb, custom, i, N, mass, a1, b1);
		vivod_mass(N, i, mass);
		if (choice == 1)
		{
			if (symb == 'O')
				symb = 'X';
			else
				symb = 'O';
			while (choice != 2)
			{
				system("cls");
				vivod_mass(N, i, mass);
				instruchtagh2(symb);
				cout << "\n>> ";
				cin >> choice;
				while ((choice != 1) && (choice != 2) && (choice != 3))
				{
					system("cls");
					vivod_mass(N, i, mass);
					instruchtagh2(symb);
					cout << "������ �������� �� ���������!\n������� ��� ������� ������!\n\n>> ";
					cin >> choice;
				}
				system("cls");
				vivod_mass(N, i, mass);
				(*menu1[choice - 1])(mass, N, buff, check, lol, symb, a1, b1);
				system("pause");
				
				system("cls");
				vivod_mass(N, i, mass);
				cout << "\n-----------------------------------\n";
				cout << "���� �� ������ ���������� ��������, ������� '0'\n���� �������� ������ �� �����, ������� '2'\n";
				cout << "-----------------------------------\n\n>> ";
				cin >> choice;
				if (choice == 2) system("cls");

			}
			vivod_mass(N, i, mass);
			cout << "\n-----------------------------------\n";
			cout << "���� �� ������ ���������� ����, ������� '3'\n���� �� ������ ��������� ����, ������� '4'\n";
			cout << "-----------------------------------\n\n>> ";
			cin >> choice;
		}

	}
	system("cls");
	see_you();
	return 0;
}
