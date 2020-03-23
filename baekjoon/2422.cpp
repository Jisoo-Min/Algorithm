#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, M;
bool dont[201][201];
int answer = 0;

vector<int> nums;

void dfs(int p, int total)
{
	if(total >= 4)
	{
		if(dont[nums[0]][nums[1]] == false &&
		   dont[nums[1]][nums[2]] == false && 
		   dont[nums[2]][nums[0]] == false)
			answer += 1;
		return;
	}
	if(p > N)
		return;

	nums.push_back(p);
	dfs(p+1, total+1);

	nums.pop_back();
	dfs(p+1, total);


}

int main()
{

	scanf("%d %d", &N, &M);

	memset(dont, 0, sizeof(dont));

	for(int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		dont[x][y] = true;
		dont[y][x] = true;
	}

	dfs(1, 1);

	cout << answer;

	return 0;
}