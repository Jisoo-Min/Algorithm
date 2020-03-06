#include <iostream>
#include <cstring>
using namespace std;

int answer[501][501];
int page_size[501];
int sum[501][501];

int go(int i, int j)
{
	if(i == j)
		return 0;
	if(answer[i][j] != -1)
		return answer[i][j];

	for(int k = i; k < j; k++)
	{
		int tmp = go(i, k) + go(k+1, j) + sum[i][j];
		if(answer[i][j] == -1 || answer[i][j] > tmp)
			answer[i][j] = tmp;
	}

	return answer[i][j];
}



int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		int k;
		scanf("%d", &k);

		memset(answer, -1, sizeof(answer));

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



		printf("%d\n", go(1, k));


	}
	return 0;
}