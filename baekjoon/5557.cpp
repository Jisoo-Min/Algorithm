#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int nums[101];
	for(int i = 1; i <= N; i++)
		scanf("%d", &nums[i]);

	long long can_make[100][21]; // i번째 숫자를 추가했을때 합 => 그 합을 만들 수 있는 숫자 갯수
	memset(can_make, 0, sizeof(can_make));

	can_make[1][nums[1]] = 1;


	for(int i = 1; i <= N-1; i++)
	{
		for(int j = 0; j <= 20; j++)
		{
			if(can_make[i][j] > 0) //만들 수 있는 값이면 
			{
				if(0 <= (j + nums[i+1]) && (j + nums[i+1]) <= 20)
				{
					can_make[i+1][j + nums[i+1]] += can_make[i][j]; 
				}
				if(0 <= (j - nums[i+1]) && (j - nums[i+1]) <= 20)
				{
					can_make[i+1][j - nums[i+1]] += can_make[i][j]; 
				}
			}
		}
	} 



	printf("%lld", can_make[N-1][nums[N]]);
	return 0;
}