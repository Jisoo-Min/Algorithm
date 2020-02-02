#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int MAX = 10000;
int maze[102][102];
int crush[102][102];

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	memset(crush, -1, sizeof(crush));
	memset(maze, -1, sizeof(maze));

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}



	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));

	queue<pair<int, int>> next_q;


	//아래랑 오른쪽만 갈수이뜸
	int dir_x[4] = {1, 0, -1, 0};
	int dir_y[4] = {0, 1, 0, -1};

	crush[1][1] = 0;

	while(!q.empty())
	{

		pair<int, int> head = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int next_x = head.first + dir_x[i];
			int next_y = head.second+ dir_y[i];

			if(maze[next_x][next_y]!= -1 && crush[next_x][next_y] == -1) //미로 범위 안에 있어야하고, 안들렸음
			{

				if(maze[next_x][next_y] == 1){ //벽이면,
					crush[next_x][next_y] = crush[head.first][head.second] + 1 ;
					next_q.push(make_pair(next_x, next_y));
				}else{ //갈수있는 빈방
					crush[next_x][next_y] = crush[head.first][head.second];
					q.push(make_pair(next_x, next_y));
				}
			}
		}

		
		if(q.empty()){
			q = next_q;
			next_q = queue<pair<int, int>>();
		}
		

	}

	cout << crush[n][m];

	return 0;
}
