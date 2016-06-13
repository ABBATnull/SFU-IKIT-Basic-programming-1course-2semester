#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;
struct journal
{
  string name,
         theme;
  int coast, kol;
    journal *next;
};
int main ()
{
    ifstream ft("input.txt");

    journal *top1, *top2, *k1, *k2;
    top1 = NULL;
    top2 = NULL;
    string namen, themen;
    int coastn, koln;
    cout<<"This is in text file:\n";
    if (!ft.is_open()) {cout<<"File was not open!!!"; return 1;}
    cout<<"____________________________________________________________\n";
    while (ft >> namen >> coastn >> koln >> themen)
    {
        cout.setf(ios::left);
        cout.width(15);
        cout << namen;
        cout.width(5);
        cout << coastn;
        cout.width(20);
        cout << koln;
        cout.width(20);
        cout << themen << endl;
        if (koln<1000)
        {
             k1 = new journal;
             k1 -> next = top1;
             k1 -> name = namen;
             k1 -> coast = coastn;
             k1 -> kol = koln;
             k1 -> theme = themen;
             top1 = k1;
             delete top1;
        }
        else
        {
             k2 = new journal;
             k2 -> next = top2;
             k2 -> name = namen;
             k2 -> coast = coastn;
             k2 -> kol = koln;
             k2 -> theme = themen;
             top2 = k2;
        }
    }
char namef1[11], namef2[11];
cout<<"____________________________________________________________\n";
cout << "Enter the filename to save journals with circulation less than 1000 exemplars:" << endl;

cin >> namef1;
cout << "Enter the filename to save others journals:" << endl;
cin >> namef2;

ofstream fbw1 (strcat (namef1, ".bin"), ios::binary);
ofstream fbw2 (strcat (namef2, ".bin"), ios::binary);
k1 = top1;
while (k1 != NULL)
{
    fbw1.write((char*)k1,sizeof (journal));
    k1=k1->next;
}
k2 = top2;
while (k2 != NULL)
{
    fbw2.write((char*)k2,sizeof (journal));
    k2=k2->next;
}
fbw1.close();
fbw2.close();

ifstream fbr1 (namef1, ios::binary);
ifstream fbr2 (namef2, ios::binary);
cout <<endl << "Journals with circulation less than 1000 exemplars:" << endl;
k1 = new journal;
cout<<"____________________________________________________________\n";
while (fbr1.peek()!=EOF)
{
        fbr1.read((char*)k1,sizeof (journal));
        cout.setf(ios::left);
        cout.width(15);
        cout<<k1->name<<" ";
        cout.width(5);
        cout<<k1->coast<<" ";
        cout.width(20);
        cout<<k1->kol<<" ";
        cout.width(20);
        cout<<k1->theme<<" \n";
}
cout<<"____________________________________________________________\n";
cout << endl << "Other journals:" << endl;
cout<<"____________________________________________________________\n";
k2 = new journal;
while (fbr2.peek()!=EOF)
{
    fbr2.read((char*)k2,sizeof (journal));
    cout.setf(ios::left);
    cout.width(15);
    cout<<k2->name<<" ";
    cout.width(5);
    cout<<k2->coast<<" ";
    cout.width(20);
    cout<<k2->kol<<" ";
    cout.width(20);
    cout<<k2->theme<<" \n";
}
cout<<"____________________________________________________________\n";
fbr1.close();
fbr2.close();
remove(namef1);
remove(namef2);

k1=top1;

while (k1!=NULL)
  {     
        journal *tmp;
        tmp=k1;
        k1=k1->next;
        delete[] tmp;
  }

k2=top2;

while (k2!=NULL)
  {
        journal *tmp;
        tmp=k2;
        k2=k2->next;
        delete[] tmp;
  }

}
