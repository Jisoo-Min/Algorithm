#include <iostream>
#include <cstring>
using namespace std;

int answer[501][501];
int page_size[501];
int sum[501][501];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		int k;
		scanf("%d", &k);

		memset(answer, 0, sizeof(answer));

		for(int i = 1 ; i <= k; i++)
			scanf("%d", &page_size[i]);
		

		//sequential sum
		for(int i = 1; i <= k; i++)
		{
			int tmp_sum = page_size[i];
			for(int j = i+1; j <= k; j++)
			{
				tmp_sum += page_size[j];
				sum[i][j] = tmp_sum;
			}
		}

		for(int j = 2; j <= k; j++)
		{
			for(int i = j-1; i >= 1; i--)
			{
				for(int p = i; p < j; p++)
				{
					if(answer[i][j] == 0 || 
					   answer[i][j] > (answer[i][p] + answer[p+1][j] + sum[i][j]) )
					{
						answer[i][j] = answer[i][p] + answer[p+1][j] + sum[i][j];
					}
				}
			}
		}


		printf("%d\n", answer[1][k]);


	}
	return 0;
}