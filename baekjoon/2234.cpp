#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int castle[51][51][5];
vector<int> area(1, 0); //0으로 초기화된 1개의 원소를 가짐 


int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

/*
	2
1		4
	8
*/
void bfs(int x, int y, int area_num)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	castle[x][y][4] = area_num;

	int count = 0;
	while(!q.empty())
	{
		int now_x, now_y;
		tie(now_x, now_y) = q.front();
		q.pop();
		count += 1;
		for(int d = 0; d < 4; d++)
		{
			int next_x = now_x + dx[d];
			int next_y = now_y + dy[d];
			//벽이없어야됝다, 방문한적없 
			if(0<=next_x && next_x<M && 0<=next_y && next_y<N
			&& castle[now_x][now_y][d] == 0 && castle[next_x][next_y][4] == 0)
			{	
				q.push(make_pair(next_x, next_y));
				castle[next_x][next_y][4] = area_num;
			}
		}

	}
	//이 영역의 크기를 넣어줌 
	area.push_back(count);
}

int main()
{
	
	//0-3: 벽 막혀있는지 -> 서 북 동 남
	//4: 여기가 몇번 구역인지 
	scanf("%d %d", &N, &M);
	memset(castle, 0, sizeof(castle));
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int tmp;
			scanf("%d", &tmp);

			for(int k = 0; k < 4; k++) //서 북 동 남
			{
				if(tmp%2 == 1) //벽이 있음 
					castle[i][j][k] = 1;
				tmp /= 2;
			}
		}
	}


	int area_num = 1;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(castle[i][j][4] == 0)
			{
				bfs(i, j, area_num);
				area_num += 1;
			}
		}
	}

	//1 방의 갯수
	cout << area_num - 1  << "\n";
	//2 최대 영역값
	int max_area = *max_element(area.begin()+1, area.end());
	cout << max_area << "\n";


	//3 합칠 수 있는 방의 최대 크기
	bool merge[2501][2501] = {0,};
	//성을 순회하면서 옆에있는지 확인
	int ans = 0;
	for(int i = 0 ; i < M;i++)
	{
		for(int j = 0; j < N; j++)
		{
			for(int d = 1; d <= 2; d++) //위랑 오른쪽만 검사 4방향다 붙어있는지 볼필요X
			{
				int nx = i+dx[d];
				int ny = j+dy[d];
				int area1 = castle[i][j][4];
				int area2 = castle[nx][ny][4];
				if(0<=nx && nx<M && 0<=ny && ny<N 
				&& merge[area1][area2] == false && area1 != area2){
					merge[area1][area2] = true;
					merge[area2][area1] = true; // 방문
					if(ans < (area[area1] + area[area2]))
						ans = (area[area1] + area[area2]);
				}
			}
		}
	}

	cout << ans;

	return 0;
}