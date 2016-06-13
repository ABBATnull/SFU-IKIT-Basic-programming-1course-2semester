#include <cmath>
#include <clocale>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node {
	int info;
	node *link;
};

void print(node * l) {
	node * k = l;
	while (k != NULL) {
		cout << k->info << " ";
		k = k->link;
	}
	cout << endl;
}
int main() 
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int inputData, N;
	node *thisNode, *left, *right;

	cout << "������� ���������� ���������: ";
	cin >> N;
	cout << "������� �����: ";
	cin >> inputData;
	/* ������ �������*/
	thisNode = new node;
	thisNode->link = NULL;
	thisNode->info = inputData;
	left = right = thisNode;
	/* ���������� ��������� ��������� */
	for (int i = 0; i < N - 1; ++i) 
	{
		cin >> inputData;
		thisNode = new node;
		thisNode->link = NULL;
		thisNode->info = inputData;
		right->link = thisNode; //���������� ���� ������
		right = thisNode;
	}
	cout << "������ �� ��������������: ";
	print(left);
	/*���������� ����� */
	thisNode = left;
	while (thisNode->link != NULL) 
	{
		if (thisNode->link->info == 0)
		{
			for (int i = 0; i < 5; i++) 
			{
				node * newnode = new node;
				newnode->link = thisNode->link;
				newnode->info = rand() % 31;
				thisNode->link = newnode;
				thisNode = thisNode->link;
			}
		}
		thisNode = thisNode->link;
	}

	cout << "����� ���������� �����: ";
	print(left);
	node *tmp;
	while (left->link != NULL)
	{
		tmp = left;
		left=left->link;
		delete tmp;
	}

	system("pause.exe");
	return 0;
}
