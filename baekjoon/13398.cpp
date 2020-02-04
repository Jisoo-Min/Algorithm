#include <iostream>

using namespace std;


int nums[100001];
int left_start_sum[100002] = {0,};
int right_start_sum[100002] = {0,};

int main()
{

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &nums[i]);

 	//0과 n+1 은 0임 더해도 지장없게

	left_start_sum[1] = nums[1];
	for(int i = 2; i <= n; i++)
	{
		if(left_start_sum[i-1] + nums[i] < nums[i]);
			left_start_sum[i] = nums[i]; //첫수가 음수이면 [i-1] = 0일 때 0 이 답이 되어버린다 -> 2부터 시작
		if(left_start_sum[i-1] + nums[i] > nums[i]) //앞에껄 포함X 나부터시작
			left_start_sum[i] = left_start_sum[i-1] + nums[i];
	}


	right_start_sum[n] = nums[n];
	for(int i = n-1; i >= 1; i--)
	{
		if(right_start_sum[i+1] + nums[i] < nums[i])
			right_start_sum[i] = nums[i];
		else
			right_start_sum[i] = right_start_sum[i+1] + nums[i];
	}


	//정답 찾기
	int max = nums[1]; //첫번째 기준 //음수일 수도 있으니까, 0으로 기준 잡을 수 X, 첫번쨰로 기준잡기


	for(int i = 2; i <= n; i++)
	{
		int tmp_sum_without_i = left_start_sum[i-1] + right_start_sum[i+1]; //하나 제거하는 경우 
		int tmp_sum_with_i = left_start_sum[i];//제거하지않아도되는 경우 

		if(max < tmp_sum_without_i)
			max = tmp_sum_without_i;
		if(max < tmp_sum_with_i)
			max = tmp_sum_with_i;
	}

	printf("%d", max);



	return 0;
}