#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int picture[N][N];
	queue<pair<int, int>> q;
	for(int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for(int j = 0; j < N; j++)
		{
			if(tmp[j] == 'R')
				picture[i][j] = 0;
			else if(tmp[j] == 'G')
				picture[i][j] = 1;
			else
				picture[i][j] = 2;
		}
	}
	//B R G -> G랑 R구분X
 	
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};

	bool check1[100][100] = {0,};
	int people1 = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(check1[i][j] == false)
			{	
				people1 += 1;
				int color = picture[i][j];
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				check1[i][j] = true;

				while(!q.empty())
				{
					int x, y;
					tie(x, y) = q.front();
					q.pop();
					for(int d = 0; d < 4; d++)
					{
						int nx = x + dx[d];
						int ny = y + dy[d];
						if(0<=nx && nx<N && 0<=ny && ny<N 
						&& check1[nx][ny] == false && picture[nx][ny] == color)
						{
							q.push(make_pair(nx, ny));
							check1[nx][ny] = true;
						}
					}
				}
			}
		}
	}
	bool check2[100][100] = {0,};
	int people2 = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(check2[i][j] == false)
			{	
				people2 += 1;
				int color = picture[i][j];
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				check1[i][j] = true;

				while(!q.empty())
				{
					int x, y;
					tie(x, y) = q.front();
					q.pop();
					for(int d = 0; d < 4; d++)
					{
						int nx = x + dx[d];
						int ny = y + dy[d];
						if(0<=nx && nx<N && 0<=ny && ny<N 
						&& check2[nx][ny] == false
						&& (picture[nx][ny] == color || picture[nx][ny] == 1-color))
						{
							q.push(make_pair(nx, ny));
							check2[nx][ny] = true;
						}
					}
				}
			}
		}
	}


	cout << people1 << " " << people2;

	return 0;
}