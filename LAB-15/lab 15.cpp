#include<iostream>
using namespace std;
class Money
{
private:
unsigned int r, k;
public:
// инициализирующий конструктор
Money(unsigned int R, unsigned int K)
{
        if(K<100&&R>0&&K>0)
            r=R, k=K;  //инициализация полей данных и занесение значений руб.  и коп.  в класс
        else
            r=k=0, cerr << "Incorrect money format" << endl;
}
// конструктор по умолчанию
Money(){}
void ShowSum()
{
        cout <<"\n"<<r<<" RUR "<<k<< " cop\n-------------------\n";
}
unsigned int GetRub()  {return r;}
unsigned int GetKop()  {return k;}
void SetRub(unsigned int _r)
{
    if(_r > 0) r=_r; else r=k=0, cerr <<"Incorrect typing of rubles"<<endl;
}
void SetKop (unsigned int _k)
{
    if(_k<100&&_k>0) k=_k; else k=r=0, cerr<<"Incorrect typing of cop"<< endl;
}
//разница в секундах с заданным временем
int Kopeck (Money m)
{
    return (m.GetRub()- r)*100 + (m.GetKop() -k);
}
};
int main()
{
  //Создаем, инициализируем и выводим первый объект
unsigned int r, k;
      cout<<"RUR: ";
      cin>>r;
      cout<<"cop: ";
      cin>>k;
      Money m1 (r, k);// используется инициализирующий конструктор
      cout << "\nMoney #1 ";
      m1.ShowSum ();
//Создаем, инициализируем и выводим второй объект
      Money m2 (10, 15); // используется инициализирующий конструктор
      cout<<"\nRUR: 10\ncop: 15\n";
      cout << "\nMoney #2 ";
      m2.ShowSum();
  //Создаем, инициализируем и выводим третий объект
      Money m3; // используется конструктор по умолчанию
    m3.SetRub (14) ;
    m3.SetKop (15) ;
    cout<<"\nRUR: 14\ncop: 15\n";
cout << "\nMoney #3";
      m3.ShowSum ();
  // Определяем разницу в секундах между первым и вторым объектом
int kk = m1.Kopeck(m2);
      cout<<"\nDifference between 1st and 2nd 'Money' (cop) is "<<kk<<endl;
}
