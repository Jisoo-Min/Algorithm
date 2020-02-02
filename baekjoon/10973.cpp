#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int num_int;
	cin >> num_int;


	vector<int> nums(num_int);
	int tmp_num;
	for(int i = 0; i<num_int; i++)
	{
		cin >> nums[i];
	}

	if(prev_permutation(nums.begin(), nums.end()))
	{
		for(int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
		}
	}
	else
	{
		cout << "-1";
	}




	return 0;
}