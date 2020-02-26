#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
char prison[102][102];
bool visit[102][102];
int h, w;
void go(int arr[][102], int s_x, int s_y)
{
	deque<pair<int, int>> q;
	q.push_back(make_pair(s_x, s_y));
	visit[s_x][s_y] = true;
	arr[s_x][s_y] = 0;

	int dir_x[4] = {0, 0, 1, -1};
	int dir_y[4] = {1, -1, 0, 0};
	while(!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop_front();

		for(int d = 0; d < 4; d++)
		{
			int nx = now.first + dir_x[d];
			int ny = now.second+ dir_y[d];

			if(0<=nx && nx<=h+1 && 0<=ny && ny<=w+1
			&& visit[nx][ny] == false) //범위안에 있고, 방문한적X
			{
				if(prison[nx][ny] == '#')
				{
					q.push_back(make_pair(nx, ny));
					arr[nx][ny] = arr[now.first][now.second] + 1;
					visit[nx][ny] = true;//방문
				}else if(prison[nx][ny] == '.' || prison[nx][ny] == 0 || prison[nx][ny] == '$')
				{
					q.push_front(make_pair(nx, ny));
					arr[nx][ny] = arr[now.first][now.second];
					visit[nx][ny] = true;//방문
				}
			}
		}


	}
	

}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		
		scanf("%d %d", &h, &w);

		pair<int, int> p1;
		pair<int, int> p2;
	
		bool find_p1 = false;
		memset(prison, 0, sizeof(prison));
		for(int i = 1 ; i <= h; i++){
			string tmp;
			cin >> tmp;
			for(int j = 1; j <= w; j++){
				prison[i][j] = tmp[j-1];
				if(prison[i][j] == '$'){
					if(find_p1 == false){
						p1.first = i;
						p1.second = j;
						find_p1 = true;
					}else{
						p2.first = i;
						p2.second = j;
					}
				}
			}
		}


		int from_outside[102][102];
		int from_p1[102][102];
		int from_p2[102][102];
		
		memset(visit, 0, sizeof(visit));
		go(from_outside, 0, 0);
		memset(visit, 0, sizeof(visit));
		go(from_p1, p1.first, p1.second);
		memset(visit, 0, sizeof(visit));
		go(from_p2, p2.first, p2.second);

		int answer = w*h;
		for(int i = 0; i <= h+1; i++)
		{
			for(int j = 0; j <= w+1; j++)
			{
				if(prison[i][j] == '*')
					continue;
				int tmp = from_outside[i][j] + from_p1[i][j] + from_p2[i][j];
				if(prison[i][j] == '#')
					tmp -= 2;
				if(tmp < answer)
					answer = tmp;
			}
		}
		printf("%d\n", answer);


	}
	
	return 0;
}