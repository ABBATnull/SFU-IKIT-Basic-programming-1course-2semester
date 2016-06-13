#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>

bool comp(int a, int b)
{
     return b<a;
}

bool positive(int a)
{
     return a>0;
}

int main()
{
   using namespace std;
   ifstream in;
   in.open ("C:\\Users\\ABBAT\\Desktop\\STUDY\\Basics of programming\\II semak\\14 Team LAB\\14\\14lab\\input.txt", std::ios::in);
   if (!in.is_open())
   {
         cout<<"File was not founded!"; return 0;
   }
   int DigFromFile;
   list<int> list;
   std::list<int>::iterator p;
   while (!in.eof())
   {
          in>>DigFromFile;
          list.push_back (DigFromFile);
   }
   cout<<"Sequence: \n";
   for (p=list.begin(); p!=list.end(); ++p)
       cout<<*p<<" ";
   cout<<"\n-------------------------\n";
   cout<<"\nSequence without positive digits: \n";
       p=remove_if(list.begin(),list.end(),positive);		//удаляю положительные числа
       list.erase(p,list.end());	  						//стираю из итератора р мусор
   for (p=list.begin(); p!=list.end(); ++p)
      cout<<*p<<" ";							//вывод на экран списка без положительных чисел
   cout<<"\n-------------------------\n";
   list.sort(comp);
   cout<<"\nSorted sequence in non-increase:\n";
   for (p=list.begin(); p!=list.end(); ++p)
      cout<<*p<<" ";
}
