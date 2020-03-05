#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int coins[n];
	for(int i = 0 ; i < n; i++)
		scanf("%d", &coins[i]);


	int answer[k+1];
	memset(answer, -1, sizeof(answer));

	answer[0] = 0;

	for(int i = 1; i <= k; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int coin = coins[j];

			if(i-coin >= 0 && answer[i-coin] != -1) //범위 안에있고, 만들수있는 가지수가 있을 경우 
			{
				if(answer[i] == -1 ||  answer[i-coin]+1 < answer[i]) //한번도 체크 안한 것이거나, 더 적은 갯수로 만들수있으면 
					answer[i] = answer[i-coin] + 1;
			}
		}
	}


	printf("%d", answer[k]);
}