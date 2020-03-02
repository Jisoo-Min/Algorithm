#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	//홍준이가 칠판에 적는 수
	int num[2001];
	for(int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	
	bool answer[2001][2001];

	for(int j = 1; j <= n; j++)
	{
		for(int i = j; i >= 1; i--)
		{
			if(i==j) //시작 == 끝
				answer[i][j] = 1;
			else if(j-i == 1) //차이가 1인 경우 
			{
				if(num[i] == num[j])
					answer[i][j] = 1;
				else
					answer[i][j] = 0;
			}
			else
			{
				if(answer[i+1][j-1] == 1)
				{
					if(num[i] == num[j])
						answer[i][j] = 1;
					else
						answer[i][j] = 0;
				}
				else //사이가 애초에 팰린드롬이 아님
				{
					answer[i][j] = 0;
 				}
			}


		}
	}

	int m;
	scanf("%d", &m);
	for(int i = 0 ; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", answer[s][e]);
	}



	


	return 0;
}