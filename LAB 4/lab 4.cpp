#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <clocale>
#include <fstream>		

using namespace std;


//---------------------------------------------------------

int Mass_min (int *mass, int n)								
{
	int i=0; int min=mass[0];

		for (i=1; i<n; i++)
			if (min>mass[i])
				min=mass[i]; 
	cout<<"����������� �������: "<<min<<endl;
	return min;
}

//---------------------------------------------------------

void View (int m, int n, int *mass)
{
int i=0;
		for (i=0; i<n; i++)		
			cout<<mass[i]<<" ";	
  	cout<<"\n";
}

//---------------------------------------------------------

void Err_k (int k, int m)
{	
			while (k>m || k<=0)
			{
			cout<<"k �� ����� ���� �����. ��� ������ ���-�� �����!\n��������� ����!"<<endl;
			cin>>k;
			}	
}

//---------------------------------------------------------

void Selection (int n, int *mass)
{
	int i=0;
	cout<<"\n\nk-�� �������- ������:\n";
		for (i=0; i<n; i++)
		{
			cout<<mass [i]<<" ";
				if (i==(n-1))	cout<<"\n";	
		}
}

//---------------------------------------------------------

void SimElements (int *mass, int n, int min)
{
	int i=0; int stepen=0;	
		for (i=0; i<n; i++)
			if (mass[i]==min) stepen++;
			
cout<<"������������ = "<<pow (min, stepen)<<"\n\n";
}

//---------------------------------------------------------

int main()
{
	int m, n; int i=0, k=0, lol=0, bin=0, bin1=0;
	setlocale (0, "Rus");
	
	ofstream birth;    													//�������� ��������� �����
    birth.open ("C:\\Users\\ABBAT\\Desktop\\666\\binary.txt", ios::binary|ios::out);
	birth.close();							
	
	fstream out;    													//�������� ����
    out.open ("C:\\Users\\ABBAT\\Desktop\\666\\binary.txt", ios::binary|ios::out|ios::in);						
	
    ifstream in;    													//��������� ����
    in.open ("C:\\Users\\ABBAT\\Desktop\\666\\ishodnic.txt", ios::in);
    	if (in.is_open())	
		{in>>m>>n;												//���������� ����������� �������
    int* mass= new int [n];											//���������� ������ ��� ���������� � ������ ������� 
    out.write ((char*)& m, sizeof m);									//������ M � N � �������� ����																	
	out.write ((char*)& n, sizeof n);
	
    cout<<"������� � ��������� �����:\n";
    cout<<m<<" "<<n<<"\n";    
    	while (lol<m)
    		{
    		for (i=0; i<n; i++)		
				in>>mass[i];
				out.write ((char*)(mass), sizeof (mass[0])*n);				//������ ������� � �������� ����	
			
		View (m, n, mass);
		lol++;
			}
			
		for (i=0; i<n; i++)		
					mass[i]=0;												//������������� �������
					
	out.seekg(0, ios::beg);
	out.read((char*)&bin, sizeof(bin));	
	out.read((char*)&bin1, sizeof(bin1));	
	
	cout<<"\n\n���������� ��������� �����:\n";
	cout<<bin<<" "<<bin1<<" ";
	
lol=0;	
	while (lol<m)
	{
		out.read((char*)(mass), sizeof(mass[0])*n);
		
				for (i=0; i<n; i++)
					cout<<mass[i]<<" ";
	lol++;
	}	
	cout<<"\n\n\n������� k:\n";
	cin>>k;
	Err_k (k, m);														//�������� � �� ���		
	
	out.seekg(sizeof(int)*(2 + (k-1) * n), ios::beg);				//������� �� �- �� ������
	out.read((char*)(mass), sizeof(mass[0])*n);						//������ ������ � Ũ ������ � �����B	
  	in.close ();
	out.close();															
	Selection (n, mass);												//����� ��������� �������- ������
	cout<<endl;	
	int min =Mass_min (mass, n);										//����� � ����� ������������ ��- �� �������	
	SimElements (mass, n, min);	
    cout<<endl;
    delete [] mass;
		}
		else cout<<"��������� ���� �� ��� ������!";
	system("pause");
    return 0;							
}
