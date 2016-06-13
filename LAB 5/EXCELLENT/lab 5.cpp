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
input.open ("input.txt", ios::out);						//ÔÀÉË Ñ×ÅÒÀ ÊÎË-ÂÀ ÑÒĞÎÊ 
		if (!input.is_open ())
			{
			cout<<"Òåêñòîâûé ôàéë íå áûë îòêğûò!";
			system ("pause");
			}			
		else
		{
			while(getline(input, vvod))
			mpl++;				 	//Ñ×ÈÒÀÅÌ ÊÎËÈ×ÅÑÒÂÎ ÑÒĞÎÊ Â ÒÅÊÑÒ. ÔÀÉËÅ	
			input.close ();	
			cout<<"Êîëè÷åñòâî ñòğîê â ôàéëå: " <<mpl<<"\n\n\n";	
		}
}

//-----------------------------------------------------------


int main()
{	
	
	struct tourist											//ÑËÀÄÊÀß ÑÒĞÓÊÒÓĞÀ ÄÀÍÍÛÕ
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
	powar.open ("input.txt");								//ÔÀÉË ÄËß ÇÀÏÎËÍÅÍÈß ÑÒĞÓÊÒÓĞÛ ÄÀÍÍÛÕ
		tourist *buff;										//ÁÓÔÅĞ ÄËß Ñ×ÈÒÛÂÀÍÈß	
		buff = new tourist [p];	
		
			while ( (!powar.eof ()) && (i<p) )
			{
			powar>>buff[i].name>>buff[i].year>>buff[i].town>>buff[i].education;
			cout<<buff[i].name<<" "<<buff[i].year<<" "<<buff[i].town<<" "<<buff[i].education<<endl;
			i++; 
			}	
	powar.close();	

//----------------------------------------------------

	cout<<"\n\n\nÂâåäèòå íàçâàíèå áèíàğíîãî ôàéëà äëÿ ñîõğàíåíèÿ: " ;cin>>filename;	//ÑÎÇÄÀÂÀÅÌÛÉ ÊÎÍÅ×ÍÛÉ ÔÀÉË
	fstream bin (strcat (filename, ".bin"), ios::binary|ios::out);	 	
	
	cout<<"Ââåäèòå íàçâàíèå ãîğîäà: "; cin>>city;	
	cout<<"\n\nÈíôîğìàöèÿ î ëşäÿõ, æèâóùèõ â ãîğîäå "<<city<<":\n";			//ÏÎÈÑÊ È ÂÛÂÎÄ ÏÎ ÃÎĞÎÄÓ
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
	cout<<"Ñîäåğæèìîå äâîè÷íîãî ôàéëà:\n";	
		for (int i=0; i<lol; i++)
		{
		bin1.read((char*)&buff[i], sizeof(tourist));					 //Ñ×ÈÒÛÂÀÍÈÅ ÁÈÍÀĞÍÎÃÎ ÔÀÉËÀ
		cout<<buff[i].name<<" "<<buff[i].year<<" "<<buff[i].town<<" "<<buff[i].education<<"\n";
		}
		bin1.close();	
	delete [] buff;
	system("pause");
    return 0;							
}
