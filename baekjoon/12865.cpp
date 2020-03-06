#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main(){
	int n, k;
	scanf("%d %d", &n, &k);

 
	int goods_w[n+1]; //무게 weight
	int goods_v[n+1]; //가치 value
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &goods_w[i], &goods_v[i]);
	}
	

	int answer[n+1][k+1];
	//int answer[101][100001];
	memset(answer, 0, sizeof(answer));

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			// 1. i번째꺼 추가 X
			answer[i][j] = answer[i-1][j]; 

			// 2. 1번째꺼 추가 O
			if(j-goods_w[i] >= 0)
			{
				//answer[i][j] = max(answer[i][j], answer[i-1][j-goods_w[i]] + goods_v[i]);
				if(answer[i][j] < answer[i-1][j-goods_w[i]] + goods_v[i]) //1번보다 큰 경우
				{
					answer[i][j] = answer[i-1][j-goods_w[i]] + goods_v[i];
				}
			}
		}
	}

	printf("%d", answer[n][k]);


	return 0;
}