#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int num_int;
	cin >> num_int;
	vector<int> nums(num_int);

	for(int i = 0; i<num_int; i++)
	{
		nums[i] = i+1;
	}

	do{

		for(int i = 0; i < num_int; i++)
		{
			cout << nums[i] << ' ';
		}
		cout<<"\n";
	}while(next_permutation(nums.begin(), nums.end()));

	return 0;
}