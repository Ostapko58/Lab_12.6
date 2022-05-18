#include<iostream>
#include<time.h>
#include<string>
#include<windows.h>
using namespace std;

struct Elem {
	Elem* link;
	int info1;
	string info2;
};



void enqueue(Elem*& first, Elem*& last,int value,string val)
{
	Elem* tmp = new Elem; // 1
	tmp->info1 = value;
	tmp->info2 = val;// 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

int dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link; // 1
	int value = first->info1; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	return value; // 6
}

void Simulation(Elem*& first, Elem*& last,int &T)
{
	int i = 1;
	while (first!=NULL)
	{
		if (T>first->info1)
		{	
			T -= first->info1;
			//dequeue(first, last);
			if (i % 2 == 0)
			{
				cout<<"„асу витрачено на додаванн€ покупц€(в хвилинах): "<< dequeue(first, last)<<endl;
			}
			else
			{
				cout << "„асу витрачено на обслуговуванн€ покупц€(в хвилинах): " << dequeue(first, last) << endl;
			}
			i++;
		}
		else
		{
			if (T!=0)
			{
				T = first->info1 - T;
			}
			return;
		}
	}
}

void Print(Elem* first)
{
	while (first!=NULL)
	{
		cout << first->info1 <<first->info2 << "\t";
		first = first->link;
	}
	cout << endl;

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	int t1 = 10, t2 = 5,N,T=20;
	Elem* first = NULL,
		* last = NULL;
	cout << "¬вед≥ть к≥льк≥сть покупц≥в: "; cin >> N;

	for (int i = 0; i < N; i++)
	{
		enqueue(first, last, rand() % (t1-1)+1," : обслуговуванн€");
		if (i!=N-1)
		{
			enqueue(first, last, rand() % (t2-1)+1, " : добавленн€");
		}
	}
	Print(first);

	Simulation(first, last, T);
	if (first==NULL)
	{
		cout << "„асу вистачило, щоб обслугувати вс≥х кл≥Їнт≥в" << endl;
	}
	else
	{
		cout << "„асу не вистачило!" << endl;
		cout << "«алишок черги:" << endl;
		Print(first);
	}


	return 0;
}

