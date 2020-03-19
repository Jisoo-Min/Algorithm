#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int n, m;
int office[8][8];

int dx[4] = {0, 1, 0, -1}; //동 남 서 북
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> cctv;

vector<int> direction;

bool can_see[8][8];
bool visit[8][8];
int min_area = 64;



void watch(int x, int y, int dir) //cctv로 볼 수 있는곳 체크
{
	

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;

	while(!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		int nx = now.first + dx[dir];
		int ny = now.second + dy[dir];
		if(0<=nx && nx<n && 0<=ny && ny<m && office[nx][ny]!=6)
		{	
			q.push(make_pair(nx, ny));
			visit[nx][ny] = true;
		}
	}


}

void simulate()
{
	memset(can_see, 0, sizeof(can_see));
	memset(visit, 0, sizeof(visit));
	//정한 방향에 대해서 확인
	for(int i = 0 ; i < cctv.size(); i++)
	{
		int x = cctv[i].first;
		int y = cctv[i].second;
		int d = direction[i];
		if(office[x][y] == 1)
		{
			watch(x, y, d); //x,y에서 시작해서 d방향으로 확인
		}else if(office[x][y] == 2)
		{
			watch(x, y, d);
			watch(x, y, d+2);
		}else if(office[x][y] == 3)
		{
			watch(x, y, d);
			watch(x, y, (d+1)%4);
		}else if(office[x][y] == 4)
		{
			watch(x, y, d);
			watch(x, y, (d+1)%4);
			watch(x, y, (d+2)%4);
		}else if(office[x][y] == 5)
		{
			watch(x, y, d);
			watch(x, y, d+1);
			watch(x, y, d+2);
			watch(x, y, d+3);
		}
	}



	int cannot = 0;
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0 ; j < m; j++)
		{
			if(visit[i][j] == false && office[i][j] != 6)
			{
				cannot += 1;
			}

		}
	}
	if(min_area > cannot)
		min_area = cannot;
}

void choose_dir(int p)
{
	
	if(p >= cctv.size()){
		simulate();
		return;
	}
	int cctv_type = office[cctv[p].first][cctv[p].second];
	//4번 회전 가능
	if(cctv_type == 1 || cctv_type == 3 || cctv_type == 4)
	{
		direction.push_back(0);
		choose_dir(p+1);
		direction.pop_back();

		direction.push_back(1);
		choose_dir(p+1);
		direction.pop_back();

		direction.push_back(2);
		choose_dir(p+1);
		direction.pop_back();

		direction.push_back(3);
		choose_dir(p+1);
		direction.pop_back();

	}//1번 회전 가능
	else if(cctv_type == 2)
	{
		direction.push_back(0);
		choose_dir(p+1);
		direction.pop_back();

		direction.push_back(1);
		choose_dir(p+1);
		direction.pop_back();
	}
	else if(cctv_type == 5)
	{
		direction.push_back(0);
		choose_dir(p+1);
		direction.pop_back();
	}

}




int main()
{
	scanf("%d %d", &n, &m);

	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0 ; j < m; j++)
		{
			scanf("%d", &office[i][j]); //6은 
			if(1 <= office[i][j] && office[i][j] <= 5)
				cctv.push_back(make_pair(i, j));
		}
	}

	choose_dir(0); //0번 부터 선택 

	//1번은 1화살표 -> 방향 4개 가능
	//2번은 2화살표 -> 방향 2개 가능
	//3번은 2화살표 -> 방향 4개 가능
	//4번은 3화살표 -> 방향 4개 가능
	//5번은 4화살표 -> 방향 1개 가능 

	cout << min_area;
	return 0;
}