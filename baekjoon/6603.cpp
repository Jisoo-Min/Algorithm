#include <iostream>
#include <vector>

using namespace std;


void rotto(vector<int> &nums, vector<int> possible, int rotto_length, int index)
{
	//정답조건
	if(possible.size() == rotto_length)
	{
		for(int i = 0; i < rotto_length; i++)
		{
			cout << possible[i] << " ";
		}
		cout << "\n";

		return;
	}

	//종료조건(못찾고 끝)
	if(index >= nums.size()){
		return;
	}

	possible.push_back(nums[index]);
	rotto(nums, possible, rotto_length, index+1);

	possible.pop_back();
	rotto(nums, possible, rotto_length, index+1);

	//다음조건
}


int main()
{

	int k;
	cin >> k;

	while(true){

		vector<int> nums(k);
		for(int i = 0; i < k; i++)
		{
			cin >> nums[i];
		}


		vector<int> possible;
		rotto(nums, possible, 6, 0);
		cout << "\n";

		cin >> k;
		if(k==0)
			break;
	}

	return 0;
}