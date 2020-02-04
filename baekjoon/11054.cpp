#include <iostream>

using namespace std;

int nums[1001];
int increasing_length[1001];
int decreasing_length[1001];

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}

	//increasing 부터 구하기
	for(int i = 1; i <= n; i++)
	{
		increasing_length[i] = 1;
		for(int j = 1; j < i; j++)
		{
			if(nums[j] < nums[i] 
			&& increasing_length[j]+1 > increasing_length[i]){
				increasing_length[i] = increasing_length[j] + 1;
			}
		}
	}
	
	//decreasing 거꾸로 구하기
	for(int i = n; i >= 1; i--)
	{
		decreasing_length[i] = 1;
		for(int j = n; j > i; j--)
		{
			if(nums[j] < nums[i]
			&& decreasing_length[j] + 1 > decreasing_length[i])
				decreasing_length[i] = decreasing_length[j] + 1;
		}
	}

	int max = 0;

	for(int i = 1; i <= n; i++)
	{
		int tmp = increasing_length[i] + decreasing_length[i] - 1;
		if(max < tmp)
			max = tmp;
	}
	cout << max;


	return 0;
}
