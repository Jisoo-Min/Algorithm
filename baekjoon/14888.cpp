#include <iostream>
#include <vector>

using namespace std;

int MAX = -1000000001;
int MIN = 1000000001;


void calculate(vector<int> nums, int index, int answer, int plus, int minus, int mul, int div)
{
	//정답
	if(plus+minus+mul+div == 0){
		if(MAX < answer){
			MAX = answer;
		}
		if(MIN > answer){
			MIN = answer;
		}
		return; //다 소진했기떄문에 더이상X
	}

	//끝났을떄 
	//위에서 끝냄

	//다음
	if(plus > 0)
		calculate(nums, index + 1, answer + nums[index], plus-1, minus, mul, div);
	if(minus > 0)
		calculate(nums, index + 1, answer - nums[index], plus, minus-1, mul, div);
	if(mul > 0)
		calculate(nums, index + 1, answer * nums[index], plus, minus, mul-1, div);
	if(div > 0)
		calculate(nums, index + 1, answer / nums[index], plus, minus, mul, div-1);

}

int main()
{
	int k;
	cin >> k;
	vector<int> nums(k);
	for(int i = 0; i < k; i++)
	{
		cin >> nums[i];
	}

	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;

	
	calculate(nums, 1, nums[0], plus, minus, mul, div);

	cout << MAX << "\n";
	cout << MIN 

	return 0;
}