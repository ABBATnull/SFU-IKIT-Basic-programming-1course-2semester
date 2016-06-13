#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void maxdig (int digit)
{
if (digit<=9)
   cout<<digit;
else
    {
 int rezerv=digit;
 list<int> l;
 list<int>::iterator it;
 while (rezerv)
       {
       l.push_back (rezerv%10);
       rezerv/=10;
       }
       l.sort();
       l.reverse();
       it=l.begin();
       cout<<*it;
    }
}

int maxdigRecur (int dig)
{
 int a,b;
 if(!dig) return 0;
 else
 {
  a = dig%10;
  b = maxdigRecur(dig/10);
  if(a>b) return a;
  else
  return b;
 }
}

int main ()
{
int digit;
setlocale (0, "Rus");
cout<<"Enter the whole number: "; cin>>digit; cout<<"*********************************\nCalling non-recursion function...\n"; cout<<"Max digit in number is= "; maxdig(digit);
cout<<"\n\n*********************************\nCalling recursion function...\n"; cout<<"Max digit in number is= "; cout<<maxdigRecur(digit);
}
