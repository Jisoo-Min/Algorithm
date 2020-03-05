#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	int num[T];
	for(int t = 0; t < T; t++)
		scanf("%d", &num[t]);

	int answer[100001];

	answer[0] = 1;


	for(int i = 1; i <= 100000; i++)
	{
		if(i-1 >= 0)//1추가 
		{
			answer[i] += answer[i-1];
		}
	}
	for(int i = 1; i <= 100000; i++)
	{
		if(i-2 >= 0)//2추가
		{
			answer[i] += answer[i-2];
		}
	}

	for(int i = 1; i <= 100000; i++)
	{	if(i-3 >= 0)//3추가
		{
			answer[i] += answer[i-3];
		}
	}
	
	for(int t = 0; t < T; t++) 
		printf("%d\n", answer[num[t]]);
	

	return 0;
}