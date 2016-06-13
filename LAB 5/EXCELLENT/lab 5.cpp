#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <clocale>
#include <fstream>

using namespace std;


const int length=30;

//------------------------------------------------------------

void count (int &mpl)
{
string vvod;
ifstream input;
input.open ("input.txt", ios::out);						//���� ����� ���-�� ����� 
		if (!input.is_open ())
			{
			cout<<"��������� ���� �� ��� ������!";
			system ("pause");
			}			
		else
		{
			while(getline(input, vvod))
			mpl++;				 	//������� ���������� ����� � �����. �����	
			input.close ();	
			cout<<"���������� ����� � �����: " <<mpl<<"\n\n\n";	
		}
}

//-----------------------------------------------------------


int main()
{	
	
	struct tourist											//������� ��������� ������
	{
	char name [length];
	char year [length];
	char town [length];
	char education [length]; 
	};
		
	int i=0; int p=0; char city [20]; char filename [length]; int lol=0;
	setlocale(LC_ALL,"Rus");
	count (p);	
	ifstream powar;
	powar.open ("input.txt");								//���� ��� ���������� ��������� ������
		tourist *buff;										//����� ��� ����������	
		buff = new tourist [p];	
		
			while ( (!powar.eof ()) && (i<p) )
			{
			powar>>buff[i].name>>buff[i].year>>buff[i].town>>buff[i].education;
			cout<<buff[i].name<<" "<<buff[i].year<<" "<<buff[i].town<<" "<<buff[i].education<<endl;
			i++; 
			}	
	powar.close();	

//----------------------------------------------------

	cout<<"\n\n\n������� �������� ��������� ����� ��� ����������: " ;cin>>filename;	//����������� �������� ����
	fstream bin (strcat (filename, ".bin"), ios::binary|ios::out);	 	
	
	cout<<"������� �������� ������: "; cin>>city;	
	cout<<"\n\n���������� � �����, ������� � ������ "<<city<<":\n";			//����� � ����� �� ������
	for (i=0; i<p; i++)
		if (!strcmpi (buff[i].town, city))
		{
		cout<<buff[i].name<<" "<<buff[i].year<<" "<<buff[i].town<<" "<<buff[i].education<<"\n";
		bin.write((char*)&buff[i], sizeof(tourist));
		lol++;
		}
	bin.close ();
	
	fstream bin1 (filename, ios::binary|ios::in);	 	
	cout<<"\n\n\n";
	cout<<"���������� ��������� �����:\n";	
		for (int i=0; i<lol; i++)
		{
		bin1.read((char*)&buff[i], sizeof(tourist));					 //���������� ��������� �����
		cout<<buff[i].name<<" "<<buff[i].year<<" "<<buff[i].town<<" "<<buff[i].education<<"\n";
		}
		bin1.close();	
	delete [] buff;
	system("pause");
    return 0;							
}
