#include <cstdlib>
#include <sstream>
#include <iostream>
#include <clocale>
#include <string>
#include <fstream>
int const pole=12;
using namespace std;
void function (bool a, string &zapis)
{
 if (a) zapis+=" ";	else zapis+=". ";
}
int main ()
{
string s, zapis, sub;  int k;
setlocale (0, "Rus");
ifstream here1; //��������� ���� �� ������
here1.open ("input.txt");
cout<<"--------------------------------\n���������� ����� input.txt: \n\n";
while (getline(here1, s))
{
cout<<s;
cout<<"\n";
}
here1.close ();	
//------------------------
ifstream iss; //��������� ���� �� ������
iss.open ("input.txt");
ofstream save; //��������� ���� �� ������
save.open ("save.txt");
cout<<"\n\n--------------------------------\n���������� ����� save.txt: \n\n�������   |  �������� | ���������\n\n";
while (!iss.eof())
{
iss>>sub;					// ���������� ������ ����� �������
zapis=sub;
for (k=0; k<pole-sub.size(); k++)
function (1, zapis);
function (1, zapis);
iss>>sub;
zapis+=sub[0];
function (0, zapis);
iss>>sub;
zapis+=sub [0];
function (0, zapis);
iss>>sub;
  if (sub[0]=='1')
  zapis+="\t���������";
   if (sub[0]=='2')
   zapis+="\t������";
    if (sub[0]=='3')
    zapis+="\t������� �������������";
     if (sub[0]=='4')
     zapis+="\t���������";
save<<zapis<<"\n";
cout<<zapis<<"\n";
}
cout<<"\n--------------------------------\n\n\n\n";
iss.close ();		  
save.close ();
system ("pause");
return 0;
}

