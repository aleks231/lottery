#include <iostream>	// za cin in cout 
#include <cstdlib>// za rand in srand funckijo 
#include <ctime>// za time funkcijo
//#include <algorithm>
//#include <set>

const int lotostevil = 39;
const int stevila = 7;



int generatorstevil(int[],int,int);
int steviloujemanj(int[],int[],int);
void izpisstevil(int[],int[]);
void winerluzer(int);

using namespace std;

int main()
{
	int loterija[7]= {0, 0, 0, 0, 0, 0, 0};
	int ujemanja= 0;
	int igralec[7]= {0,0,0,0,0,0,0};

	generatorstevil(loterija,stevila,lotostevil);

    cout<<"Loterija.."<<endl;
    
	for(int i=0;i<stevila;i++)
	{ 
		cout<<"Vstavite stevilo med 1 in 39:  ";
		cin>>igralec[i];
		
		
		while(igralec[i]<1 || igralec[i]>39)
		{
			
		cout<<"Vstavleno stevilo ni med 1 in 39 ";
		cin>>igralec[i];
		
		}
	
		
		
		for(int j=0;j <= i-1;j++)
		{
			if(igralec[j] == igralec[i])
			{
				
			cout<<"Stevila se ponavljajo,vnesite se enkrat: ";
			cin>>igralec[1];
			
			}
	
		}
	}
		
	ujemanja = steviloujemanj(loterija,igralec,ujemanja);

	izpisstevil(loterija, igralec);

	winerluzer(ujemanja);

	return 0;
}



int generatorstevil(int loterija[],int,int)
{
	unsigned seed = time(0);
	srand(seed);

	for(int y=0;y<stevila;y++)
	{ 
			loterija[y] = rand() % lotostevil +1;
	
		
		
		for(int i=0;i <= i-1;i++)
		{
			if(loterija[y] == loterija[i])
			{
			loterija[i] = rand() % lotostevil +1;
			
			}
		}
	}
	
	return 0;

} 


int steviloujemanj(int loto[],int vnos[],int)
{
	int ujemanje= 0;
	for(int i = 0;i < stevila;i++)
	{
		for(int x = 0;x < stevila;x++)
		{
			
			if(loto[i] == vnos[x])
			{
			ujemanje = ujemanje + 1;
			}
			
		}
	}

return ujemanje;
} 


void izpisstevil(int loterija[],int igralec[])
{
	cout<<"Zmagovalne stevilke so: "<<loterija[0]<<" "<<loterija[1]<<" "<<loterija[2]<<" "<<loterija[3]<<" "<<loterija[4]<<" "<<loterija[5]<<" "<<loterija[6]<<endl;
	cout<<"Tvoje stevilke so: "<<igralec[0]<<" "<<igralec[1]<<" "<<igralec[2]<<" "<<igralec[3]<<" "<<igralec[4] <<" "<<igralec[5]<<" "<<igralec[6] <<endl;
}


void winerluzer(int ujemanja)
{
	cout<<"Ujema se "<<ujemanja<<" stevilo/a"<<endl;

	if(ujemanja != stevila)
		cout<<"Nisi dobil nic"<<endl;
	else
		cout<<"Zmaga!"<<endl;
}
