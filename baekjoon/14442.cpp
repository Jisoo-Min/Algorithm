#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};

	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	int pan[N+1][M+1];
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			scanf("%1d", &pan[i][j]);
		}
	}

	int check[N+1][M+1][K+1]; //벽 몇번 부숴서가니 
	memset(check, 0, sizeof(check));

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 1, 0));
	check[1][1][0] = 1;//거리 

	while(!q.empty())
	{
		int x, y, l;
		tie(x, y, l) = q.front();
		q.pop();

		for(int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(1<=nx && nx<=N && 1<=ny && ny<=M)
			{
				//벽을 안부수고 갈 수 있는 경우
				if(pan[nx][ny] == 0 && check[nx][ny][l] == 0)//l번 부순적없어야함 
				{	
					q.push(make_tuple(nx, ny, l));
					check[nx][ny][l] = check[x][y][l] + 1;
				}
				//뱍을 부숴야하는 경우
				if(pan[nx][ny] == 1 && check[nx][ny][l+1] == 0 && l+1<=K) //l+1번 부순적없어야하고, 부수는 횟수 넘으면 안됨 
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
		if(check[N][M][i] != 0)
		{
			if(answer == -1 || answer > check[N][M][i])
				answer = check[N][M][i];
		}
	}


	cout << answer;


	return 0;
}