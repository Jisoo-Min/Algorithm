#include <iostream>
#include <vector>
using namespace std;


int energy[20][20];

int min_val = 9999999;

void dfs(int n, int now_num, vector<int>& left, vector<int>& right) //현재값,
{

	//계쏙 조건 
	if(left.size() < n/2)
	{
		left.push_back(now_num);
		dfs(n, ++now_num, left, right);
		left.pop_back();
		now_num--;
	}

	if(right.size() < n/2)
	{
		right.push_back(now_num);
		dfs(n, ++now_num, left, right);
		right.pop_back();
		now_num--;
	}

	//종료조건
	if(left.size() == n/2 && right.size() == n/2)
	{
		int left_sum = 0; int right_sum = 0;
		for(int i = 0; i < n/2; i++)
		{
			for(int j = i; j < n/2; j++)
			{
				left_sum  += (energy[left[i]][left[j]] + energy[left[j]][left[i]]);
				right_sum += (energy[right[i]][right[j]] + energy[right[j]][right[i]]);
			}
		}

		int gap = left_sum - right_sum;
		if(gap < 0)
			gap = -gap;
		if(gap < min_val)
			min_val = gap;
	}

}



int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &energy[i][j]);
		}
	}


	//사람은 0부터 n-1까지 있는 것임

	vector<int> left;
	vector<int> right;


	dfs(n, 0, left, right);

	cout << min_val;

	return 0;
}