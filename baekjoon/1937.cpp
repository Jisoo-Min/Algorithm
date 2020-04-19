#include <iostream>
#include <queue>
#include <tuple>
using namespace std;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int forest[500][500];
int n;


int answer[500][500] = {0,}; //정답 길이 

int solve(int x, int y)
{
	if(answer[x][y] != 0)
		return answer[x][y];
	else
	{
		answer[x][y] = 1; //기본값은 자기자신하나 ! 1이다

		for(int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];

			if(0<=nx && nx<n && 0<=ny && ny<n)
			{
				if(forest[x][y] > forest[nx][ny])
					answer[x][y] = max(answer[x][y], solve(nx, ny)+1);
			}
		}
	}

	return answer[x][y];
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> forest[i][j];
		}
	}


	int ans = -1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int tmp_ans = solve(i, j);
			if(ans < tmp_ans)
				ans = tmp_ans;
		}
	}


	cout << ans;


	return 0;
}