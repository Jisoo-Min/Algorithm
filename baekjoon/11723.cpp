#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{

	int n;
	scanf(" %d", &n);

	char operat[20];
	int num;

	int s = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", &operat);

		if(strcmp(operat, "add") == 0)
		{
			scanf("%d", &num); 
			s = s | (1<<num);
		}
		else if(strcmp(operat, "remove") == 0)
		{
			scanf("%d", &num); 
			s = s & ~(1<<num);
		}
		else if(strcmp(operat, "check") == 0)
		{
			scanf("%d", &num); 
			int check_num = (1<<num); 
			if(s & check_num)
				cout<<"1"<<"\n";
			else
				cout<<"0"<<"\n";
		}
		else if(strcmp(operat, "toggle") == 0)
		{
			scanf("%d", &num); 
			s = s ^ (1 << num);
		}
		else if(strcmp(operat, "all") == 0)
		{
			s = (1<<21) - 1;
		}
		else if(strcmp(operat, "empty") == 0)
		{
			s = 0;
		}


	}
}