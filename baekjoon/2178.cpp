#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int map[100][100] = {0,};
int visit[100][100] = {0,};

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 우 하 상 좌

int n, m;
queue<pair<int, int>> q;
queue<int> foots;

int foot = 1;
void bfs()
{
	int now_i = 0;
	int now_j = 0;
	q.push({now_i, now_j});
	visit[now_i][now_j] = 1;
	foots.push(foot);

	while(!q.empty())
	{
		pair<int, int> head = q.front();
		q.pop();
		foot = foots.front();
		foots.pop();

		foot++;
		for(int i = 0; i < 4; i++)
		{	
			int next_i = head.first + dir[i][0];
			int next_j = head.second+ dir[i][1];
			if(0<=next_i && next_i< n && 0<=next_j && next_j < m
				&& map[next_i][next_j] == 1 && visit[next_i][next_j] == 0){
				q.push({next_i, next_j});
				foots.push(foot);
				map[next_i][next_j] = foot;
				visit[next_i][next_j] = 1;
				if(next_i == n && next_j == m){
					foot += 1;
					return;
				}
			}
			
		}
	}

}

int main()
{

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();



	printf("%d", map[n-1][m-1]);

	return 0;
}