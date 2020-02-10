#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int n;

bool can_go[15][15];
vector<pair<int, int>> queen;

int answer = 0;

bool can_put(int new_i, int new_j)
{
	for(int i = 0; i < queen.size(); i++)
	{
		//new_i == queen[i].first 이건 어짜피 이미 걸러졌음 한행에 1개니까 
		if(new_j == queen[i].second
		|| (new_i - queen[i].first) == (new_j - queen[i].second) 
		|| (new_i - queen[i].first)*(-1) == (new_j - queen[i].second))
			return false;
	}

	return true;
}


void move(int i, int j, int num)
{
	
	if(num == n){
		answer += 1;
		return;
	}

	for(int k2 = 0; k2 < n; k2++)
	{
		if(can_put(i+1, k2)){
			
			queen.push_back(make_pair(i+1, k2));
			move(i+1, k2, num+1);
			queen.pop_back();
		}
	}


	return;
}


int main()
{
	scanf("%d", &n);



	//시작점 
	for(int i = 0; i < n; i++) 
	{
		queen.push_back(make_pair(0, i));
		move(0, i, 1);
		queen.pop_back();
	}

	cout << answer;
	return 0;
}