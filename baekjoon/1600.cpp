#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
	int K, W, H;
	scanf("%d", &K);
	scanf("%d %d", &W, &H);

	int pan[H][W];
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			scanf("%d", &pan[i][j]);
		}
	}
	//일반적인 이동
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	//나이트이동
	int kx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int ky[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	
	int check[H][W][K+1];
	memset(check, -1, sizeof(check));

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	check[0][0][0] = 0;

	while(!q.empty())
	{
		int x, y, l;
		tie(x, y, l) = q.front();
		q.pop();

		for(int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(0<=nx && nx<H && 0<=ny && ny<W
			 && pan[nx][ny] == 0 && check[nx][ny][l] == -1)//범위 안에 있고, 벽이아님, 방문한 적없음
			{
				q.push(make_tuple(nx, ny, l));
				check[nx][ny][l] = check[x][y][l] + 1;
			}
		}
		if(l+1<=K){ //말처럼 뛸 수 있는 경우에만
			for(int d = 0; d < 8; d++)
			{
				int nx = x + kx[d];
				int ny = y + ky[d];
				if(0<=nx && nx<H && 0<=ny && ny<W
				 && pan[nx][ny] == 0 && check[nx][ny][l+1] == -1)//범위 안에 있고, 벽이아님, 방문한 적없음
				{
					q.push(make_tuple(nx, ny, l+1));
					check[nx][ny][l+1] = check[x][y][l] + 1;
				}
			}

		}	
		

	}

	int answer = -1;
	for(int i = 0; i <= K; i++)
	{
		if(check[H-1][W-1][i] != -1 && (answer == -1 || answer > check[H-1][W-1][i]))
			answer = check[H-1][W-1][i];
	}

	cout << answer;

	return 0;
}