#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int R, C;
int yard[251][251];
bool visit[251][251];

int sheep = 0;
int wolf = 0;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void go(int sx, int sy)
{

	int sub_sheep = 0;
	int sub_wolf  = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visit[sx][sy] = true;

	while(!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();
		//cout <<"In q : " << now.first << ", " << now.second << endl;
		if(yard[now.first][now.second] == 'o')
			sub_sheep += 1;
		else if(yard[now.first][now.second] == 'v')
			sub_wolf += 1;

		for(int d = 0; d < 4; d++)
		{
			int nx = now.first + dx[d];
			int ny = now.second +dy[d];

			if(0<=nx && nx<R && 0<=ny && ny<C 
			&& yard[nx][ny] != '#' && visit[nx][ny] == false)
			{
				q.push(make_pair(nx, ny));
				visit[nx][ny] = true;
			}

		}
	}


	if(sub_sheep > sub_wolf)
		sheep += sub_sheep;
	else
		wolf += sub_wolf;
}

int main()
{
	scanf("%d %d", &R, &C);

	memset(visit, 0, sizeof(visit));

	for(int i = 0; i < R; i++)
	{
		string tmp;
		cin >> tmp;
		for(int j = 0; j <C; j++)
			yard[i][j] = tmp[j];
	}


	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(yard[i][j] != '#' && visit[i][j] == false)
				go(i, j);
		}
	}


	cout << sheep << " " << wolf;
	return 0;
}