#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(vector<int> nums, int num_int)
{
	int sum = 0;
	for(int i = 0; i <= num_int-2; i ++)
	{
		sum += abs(nums[i]-nums[i+1]);
	}
	return sum;
}

int main()
{
	int num_int;
	cin >> num_int;

	vector<int> nums(num_int);

	for(int i = 0; i < num_int; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());


	int sum = 0;
	int tmp_sum = 0;
	do
	{
		tmp_sum = calculate(nums, num_int);
		if(sum<tmp_sum)
		{
			sum = tmp_sum;
		}
	}
	while(next_permutation(nums.begin(), nums.end()));

	cout<<sum;

	return 0;
}