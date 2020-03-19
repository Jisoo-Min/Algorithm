#include <iostream>
#include <set>
using namespace std;
int pan[5][5];

set<int> answer;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void dfs(int x, int y, int t, int num)
{
	if(t > 6){
		answer.insert(num);
		return;
	}

	for(int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		if(0<=nx && nx<5 && 0<=ny && ny<5)
		{
			dfs(nx, ny, t+1, num*10 + pan[x][y]);
		}
	}

}



int main()
{

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			scanf("%d", &pan[i][j]);
		}
	}

	

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			dfs(i, j, 1, 0);
		}
	}

	cout << answer.size();

	return 0;
}