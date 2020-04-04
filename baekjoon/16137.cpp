#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
int cloud[10][10];

int bfs()
{
	int visit[10][10];
	memset(visit, -1, sizeof(visit));

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0)); //현재위치(0, 0), 시간 0
	visit[0][0] = 0;

	while(!q.empty())
	{
		int x, y, t;
		tie(x, y, t) = q.front(); q.pop();


		for(int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(0<=nx && nx<n && 0<=ny && ny<n)
			{	
				//다음이 일반다리면, 현재 오작교인지 아닌지 상관없이 갈 수 있음 
				if(cloud[nx][ny] == 1 && (visit[nx][ny] == -1 || visit[nx][ny] > t+1)) //방문한 적이 없거나, 더 빨리 방문한 경우
				{
					q.push(make_tuple(nx, ny, t+1));
					visit[nx][ny] = t+1;
				}
				else if(cloud[nx][ny] == 0)  //못건너는 경우 
				{
					continue;
				}
				else if(cloud[nx][ny] > 1)//다음이 오작교인경우 
				{
					if(cloud[x][y] > 1) continue; //현재도 오작교면 연속이니까 갈수 X
					int possible_time = t+1 + (cloud[nx][ny] - ((t+1)%cloud[nx][ny])); //언제 이 오작교를 건널 수 있는지계산
					if( (t+1)%cloud[nx][ny] == 0){ //바로 시간 딱 되서 건널 수 있는 경우 
						q.push(make_tuple(nx, ny, t+1));
						visit[nx][ny] = t+1;
					}
					else if(visit[nx][ny] == -1 || visit[nx][ny] > possible_time)
					{
						q.push(make_tuple(nx, ny, possible_time));
						visit[nx][ny] = possible_time;
					}
				}
			}
		}
		//지금 오작교 위에 올라와 있으면?
			//1. 다음이 일반다리 
			//2. 다음이 오작교 X (불가능)

		//지금 일반 다리 위에 있으면?
			//1. 다음이 일반다리인가? 
			//2. 다음이 오작교인가 

		
	}
	return visit[n-1][n-1];

}


bool check_cross(int x, int y)
{
	//가로
	bool garo = false;	
	if(y-1 >= 0 && cloud[x][y-1] == 0)
		garo = true;
	if(y+1 < n  && cloud[x][y+1] == 0)
		garo = true;

	//세로
	bool sero = false;
	if(x-1 >= 0 && cloud[x-1][y] == 0)
		sero = true;
	if(x+1 < n  && cloud[x+1][y] == 0)
		sero = true;

	if(garo==true && sero==true)
		return true;
	else
		return false;
}
int main()
{
	//한 곳에 주기가 m인 오작교 설치 가능
	
	scanf("%d %d", &n, &m);

	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			scanf("%d", &cloud[i][j]);
	}


	int ans = -1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(cloud[i][j] == 0 && check_cross(i, j)==false){// 한 곳에 오작교 놓기, 교차로가 아닌 곳

				cloud[i][j] = m; //오작교로 바꾸어주고 

				int go = bfs();
				if(go != -1 && (ans == -1 || ans > go))//갈 수 있어야하고, 최소인지 
					ans = go;

				cloud[i][j] = 0;
			} 
			
		}
	}

	cout << ans;

	return 0;
}