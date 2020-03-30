#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	int R, C;
	scanf("%d %d", &R, &C);

	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};

	char lake[1500][1500];


	int s1x, s1y, s2x, s2y;
	s1x = -1; s1y = -1; s2x = -1; s2y = -1;

	queue<pair<int, int>> water;
	bool water_check[1500][1500] = {0,};
	for(int i = 0; i < R; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < C; j++){
			lake[i][j] = tmp[j];
			if(lake[i][j] == 'L'){
				if(s1x == -1){
					s1x = i;
					s1y = j;
					lake[i][j] = '.';
					water.push(make_pair(i, j)); //백조도 물로 취급
					water_check[i][j] = true;
				}else{
					s2x = i;
					s2y = j;
					lake[i][j] = '.';
					water.push(make_pair(i, j)); //백조도 물로 취급
					water_check[i][j] = true;
				}
			}
			else if(lake[i][j] == '.')//물인 경우
			{
				water.push(make_pair(i, j));
				water_check[i][j] = true;
			}	
		}
	}
	//cout << "SWAN = ("<<s1x << ", " << s1y << ") (" << s2x << ", " << s2y <<")"<< endl;
		
	queue<pair<int, int>> next_water;


	bool swan_check[1500][1500] = {0,};
	queue<pair<int, int>> swan;
	swan.push(make_pair(s1x, s1y));
	swan_check[s1x][s1y] = true;
	queue<pair<int, int>> next_swan;
	int time = 0;
	while(true)
	{
		//한개씩 녹는다
		//근처얼음 찾기
		while(!water.empty())
		{
			int x, y;
			tie(x, y) = water.front(); 
			water.pop();
			lake[x][y] = '.'; //녹을 차례
			for(int d = 0; d < 4; d++)
			{
				int nx = x + dx[d];
				int ny = y + dy[d];
				if(0<=nx && nx<R && 0<=ny && ny<C && water_check[nx][ny] == false)//방문안해ㅐ야 방문가능
				{
					if(lake[nx][ny] == '.')
					{
						water.push(make_pair(nx, ny));
						water_check[nx][ny] = true;
					}else //물 근처 얼음이니까 다음번에 녹는다 
					{
						next_water.push(make_pair(nx, ny));
						water_check[nx][ny] = true;
					}
				}
			}

		}


		//백조 갈 수 있는지 확인 
		while(!swan.empty())
		{
			int x, y;
			tie(x, y) = swan.front();
			swan.pop();
			for(int d = 0; d < 4; d++)
			{
				int nx = x + dx[d];
				int ny = y + dy[d];
				if(0<=nx && nx<R && 0<=ny && ny<C && swan_check[nx][ny] == false)
				{
					if(lake[nx][ny]=='.'){
						swan.push(make_pair(nx, ny));
						swan_check[nx][ny] = true;
					}else //얼음이면 
					{
						next_swan.push(make_pair(nx, ny));
						swan_check[nx][ny] = true;
					}
					
				}
			}
		}

		
		if(swan_check[s2x][s2y] == true) //두번째 백조에 도착했으면
			break;
		
		time += 1;

		water = next_water;
		swan = next_swan;
		next_water = queue<pair<int, int>>();
		next_swan = queue<pair<int, int>>();

	}
	
	//처음에는 0초임 -> 아무것도 안녹았으니까
	cout << time;




	return 0;
}