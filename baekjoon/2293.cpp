#include <iostream>
#include <cstring>
using namespace std;

int main()
{

	int n, k;
	scanf("%d %d" , &n, &k);

	int coin[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &coin[i]);


	int answer[100001];
	memset(answer, 0, sizeof(answer));
	answer[0] = 1;


	for(int c = 0; c < n; c++)
	{
		int coin_num = coin[c];
		for(int i = 1; i <= k; i++)
		{
			if(i-coin_num >= 0)
				answer[i] += answer[i-coin_num];
		}
	}


	printf("%d", answer[k]);
	return 0;
}