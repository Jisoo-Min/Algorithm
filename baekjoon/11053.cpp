#include <iostream>
#include <cstring>

using namespace std;


int nums[1001] = {0,};
int length[1001] = {0,};

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
		for(int j = 1;  j < i; j++)
		{
			if(nums[j] < nums[i] && (length[j]+1 > length[i])){ 
			//쭉 보면서 나보다 작은앤지&& 그리고 그 값에서 1더한게 나보다 작은지
				length[i] = length[j]+1;
			}
		}
		// cout << i << ": " << length[i] << endl;;
	}


	int max = length[1];
	for(int i = 2; i<=n; i++)
	{
		if(max < length[i])
			max = length[i];
	}
	cout << max;

	return 0;
}