#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int pan[100][100];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &pan[i][j]);
		}
	}


	long long count[100][100];
	count[0][0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(count[i][j] > 0) //갈 수 있는 곳이면 
			{	
				int movable = pan[i][j];
				if(movable == 0)
					continue;
				if(i+movable < n)
				{
					count[i+movable][j] += count[i][j];
					
				}
				if(j+movable < n)
				{
					count[i][j+movable] += count[i][j];
				
				}
			}

			

		}
	}



	printf("%lld", count[n-1][n-1]);

	return 0;
}