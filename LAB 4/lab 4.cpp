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
	cout<<"Минимальный элемент: "<<min<<endl;
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
			cout<<"k не может быть отриц. или больше кол-ва строк!\nПовторите ввод!"<<endl;
			cin>>k;
			}	
}

//---------------------------------------------------------

void Selection (int n, int *mass)
{
	int i=0;
	cout<<"\n\nk-ая матрица- строка:\n";
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
			
cout<<"Произведение = "<<pow (min, stepen)<<"\n\n";
}

//---------------------------------------------------------

int main()
{
	int m, n; int i=0, k=0, lol=0, bin=0, bin1=0;
	setlocale (0, "Rus");
	
	ofstream birth;    													//СОЗДАНИЕ БИНАРНОГО ФАЙЛА
    birth.open ("C:\\Users\\ABBAT\\Desktop\\666\\binary.txt", ios::binary|ios::out);
	birth.close();							
	
	fstream out;    													//БИНАРНЫЙ ФАЙЛ
    out.open ("C:\\Users\\ABBAT\\Desktop\\666\\binary.txt", ios::binary|ios::out|ios::in);						
	
    ifstream in;    													//ТЕКСТОВЫЙ ФАЙЛ
    in.open ("C:\\Users\\ABBAT\\Desktop\\666\\ishodnic.txt", ios::in);
    	if (in.is_open())	
		{in>>m>>n;												//считывание размерности матрицы
    int* mass= new int [n];											//одномерный массив для считывания и записи матрицы 
    out.write ((char*)& m, sizeof m);									//ЗАПИСЬ M И N В БИНАРНЫЙ ФАЙЛ																	
	out.write ((char*)& n, sizeof n);
	
    cout<<"Матрица в текстовом файле:\n";
    cout<<m<<" "<<n<<"\n";    
    	while (lol<m)
    		{
    		for (i=0; i<n; i++)		
				in>>mass[i];
				out.write ((char*)(mass), sizeof (mass[0])*n);				//ЗАПИСЬ МАССИВА В БИНАРНЫЙ ФАЙЛ	
			
		View (m, n, mass);
		lol++;
			}
			
		for (i=0; i<n; i++)		
					mass[i]=0;												//ОННУЛИРОВАНИЕ МАССИВА
					
	out.seekg(0, ios::beg);
	out.read((char*)&bin, sizeof(bin));	
	out.read((char*)&bin1, sizeof(bin1));	
	
	cout<<"\n\nСодержимое двоичного файла:\n";
	cout<<bin<<" "<<bin1<<" ";
	
lol=0;	
	while (lol<m)
	{
		out.read((char*)(mass), sizeof(mass[0])*n);
		
				for (i=0; i<n; i++)
					cout<<mass[i]<<" ";
	lol++;
	}	
	cout<<"\n\n\nВведите k:\n";
	cin>>k;
	Err_k (k, m);														//ПРОВЕРКА К НА ОДЗ		
	
	out.seekg(sizeof(int)*(2 + (k-1) * n), ios::beg);				//ПЕРЕХОД НА К- УЮ СТРОКУ
	out.read((char*)(mass), sizeof(mass[0])*n);						//ЧТЕНИЕ СТРОКИ И ЕЁ ЗАПИСЬ В МАССИB	
  	in.close ();
	out.close();															
	Selection (n, mass);												//ВЫВОД ВЫБРАННОЙ МАТРИЦЫ- СТРОКИ
	cout<<endl;	
	int min =Mass_min (mass, n);										//ПОИСК И ВЫВОД МИНИМАЛЬНОГО ЭЛ- ТА МАССИВА	
	SimElements (mass, n, min);	
    cout<<endl;
    delete [] mass;
		}
		else cout<<"Текстовый файл не был открыт!";
	system("pause");
    return 0;							
}
