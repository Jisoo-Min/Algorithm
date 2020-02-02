#include <iostream>
#include <vector>

using namespace std;



int answer = 0;

void partial(vector<int> nums, int sum, int now_sum, int num_num, int index)
{
	//정답
	if(index >= num_num && now_sum == sum) //끝까지 다 가고, 합이 맞으면
	{
		answer +=1;
		return;
	}
	//종료조건
	if(index >= num_num && now_sum != sum){
		return;
	}
	//다음조건

	partial(nums, sum, now_sum + nums[index], num_num, index + 1);
	partial(nums, sum, now_sum 				, num_num, index + 1);

}




int main()
{

	int num_num, sum;
	cin >> num_num >> sum;

	vector<int> nums(num_num);
	for(int i = 0; i < num_num; i++)
	{
		cin >> nums[i];
	}

	partial(nums, sum, 0, num_num, 0);

	if(sum == 0) answer -= 1;
	
	cout << answer;


	return 0;
}