#include <iostream>

using namespace std;


long long sticker[2][100001];


long long answer[100001][3];
//0: 아무것도 선택X
//1: 위에꺼 선택
//2: 아래꺼 선택

int main()
{

	int t;
	scanf("%d", &t);

	for(int go = 0; go <t; go++){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < 2; i++){
			for(int j = 1; j <= n; j++)
			{
				scanf("%lld", &sticker[i][j]);
			}
		}

		answer[1][0] = 0;
		answer[1][1] = sticker[0][1];
		answer[1][2] = sticker[1][1];

		for(int i = 2; i <= n; i++)
		{
			//0
			long long max0 = 0;
			if(max0 < answer[i-1][0])
				max0 = answer[i-1][0];
			if(max0 < answer[i-1][1])
				max0 = answer[i-1][1];
			if(max0 < answer[i-1][2])
				max0 = answer[i-1][2];

			answer[i][0] = max0;

			//1
			long long max1 = 0;
			if(max1 < answer[i-1][0])
				max1= answer[i-1][0];
			if(max1 < answer[i-1][2])
				max1 = answer[i-1][2];
			answer[i][1] = max1 + sticker[0][i];

			//2
			long long max2 = 0;
			if(max2 < answer[i-1][0])
				max2= answer[i-1][0];
			if(max2 < answer[i-1][1])
				max2 = answer[i-1][1];
			answer[i][2] = max2 + sticker[1][i];

		}

		long long max = answer[n][0];
		if(max < answer[n][1])
			max = answer[n][1];
		if(max < answer[n][2])
			max = answer[n][2];

		cout << max << "\n";





	}


	return 0;
}