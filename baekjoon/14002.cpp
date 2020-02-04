#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int nums[1001] = {0,};
int length[1001] = {0,};
int idx[1001] = {0,};

int main()
{
	
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &nums[i]);
	}


	for(int i = 1; i <= n; i++)
	{
		length[i] = 1;
		idx[i] = i;
		for(int j = 1;  j < i; j++)
		{
			if(nums[j] < nums[i] && (length[j]+1 > length[i])){ 
			//쭉 보면서 나보다 작은앤지&& 그리고 그 값에서 1더한게 나보다 작은지
				length[i] = length[j]+1;
				idx[i] = j;
			}
		}
	}


	int max = length[1];
	int max_idx = 1;
	for(int i = 2; i<=n; i++)
	{
		if(max < length[i]){
			max = length[i];
			max_idx = i;
		}
	}

	cout << max << "\n"; //길이 최대

	vector<int> answer;

	//max_idx부터 본다 -> 백트래킹마냥
	for(int i = 0; i < max; i++)
	{
		answer.push_back(nums[max_idx]);
		max_idx = idx[max_idx];

	}

	//앞에서 부터 출력
	for(int i = max-1; i >=0; i--)
	{
		cout << answer[i] << " ";

	}


	return 0;
}