#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
  //--------------------------------
#include <iostream.h>
#include <stdio.h>
using namespace std;

int main()
{
	int LastNum;
	int FirstNum = 3;
	bool IsSimple = false;
	bool g = false;
	int temp = 0;

	cout<< "Factorization \t Array 1...";
	cin>>LastNum;
	LastNum += 1;

	int *TableArray = new int[LastNum]; // size of table of simple numbers

	int Index = 0;
	TableArray[Index] = 2;
	Index++;
	
	for (int i = 0; i < LastNum; i++)
	{
		for (int j = 2; j < FirstNum; j++)
		{
		   if (FirstNum % j == 0)
		   {
			  IsSimple = false;
			  break;
		   }
		   else
		   {
			  IsSimple = true;
		   }
		}

		if (!IsSimple)
		{
			FirstNum++;
			continue;
		}
		else
		{
			TableArray[Index] = FirstNum;
			FirstNum++;
			Index++;
		}
	}

	bool yes = false;

	for (int i = 0; i < LastNum; i++)
	{
		for (int j = 0; j < LastNum; j++)
		{
			if (i == TableArray[j] || i < 3)
			{
				cout <<"simple number ";
				cout << i;
				cout << "\n";
				yes = true;
				break;
			}
		}
		if (!yes)
		{
		   cout <<"factorization ";
		   cout << i;
		   cout << " = ";

		   for (int k = 0; k < i; k++)
		   {
		   	  if (g == true) break;

			  if (i % TableArray[k] == 0)
			  {
				temp =  i / TableArray[k];
				cout << TableArray[k];
				cout << " * ";
				
				int b = 0;
				
				while (true)
				{   
					if (temp == 1)
					{   
						g = true;
						break;
					}
					if (temp % TableArray[b] == 0)
					{
						cout << TableArray[b];
						if (temp /  TableArray[b] != 1) cout << " * ";
						temp /=  TableArray[b];		
					} 
					else 
					{
						b++;
					}
				}				
			  }
			  else
			  {
				  continue;
			  }
		   }
		   g = false;
		   temp = 0;
		   cout << "\n";
		}
		else
		{
			yes = false;
		}
	}

	system("pause");
	return 0;
}
