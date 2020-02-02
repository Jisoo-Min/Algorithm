#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char forest[60][60];

int main()
{

	int r, c;
	scanf("%d %d", &r, &c);

	int now_x, now_y; //고슴도치 위치 -> 시작점
	int end_x, end_y; //비버굴 위치 -> 도착점

	queue<pair<int, int>> flood;
	int flood_time[60][60];
	memset(flood_time, -1, sizeof(flood_time));

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> forest[i][j];
			if(forest[i][j] == 'D'){ // 비버굴
				end_x = i;
				end_y = j;
			}else if(forest[i][j] == 'S'){//고슴도치
				now_x = i;
				now_y = j;
			}else if(forest[i][j] == '*'){ // 물 새는 곳
				flood.push(make_pair(i, j));
				flood_time[i][j] = 0;
		
			}
		}
	}



	//비버굴은 안잠김
	


	int dir_x[4] = {0, 0, 1, -1};
	int dir_y[4] = {1, -1, 0, 0};
	while(!flood.empty())
	{
		pair<int, int> head = flood.front();
		flood.pop();

		
		for(int i = 0; i<4; i++)
		{
			int next_x = head.first + dir_x[i];
			int next_y = head.second+ dir_y[i];

			if(0<=next_x && next_x<r && 0<=next_y && next_y <c //범위 안에 있고 
			&& flood_time[next_x][next_y] == -1//방문한 적 없으면
			&& forest[next_x][next_y]!='X'  // 돌 아니면
			&& forest[next_x][next_y]!='D') // 소굴에도 불가능
			{
				flood_time[next_x][next_y] = flood_time[head.first][head.second] + 1;
				flood.push(make_pair(next_x, next_y));

			}
		}
	}

	flood_time[end_x][end_y] = 3000;


	int move_time[60][60];
	memset(move_time, -1, sizeof(move_time));
	queue<pair<int, int>> move; 
	move.push(make_pair(now_x, now_y));
	move_time[now_x][now_y] = 0;

	while(!move.empty())
	{
		pair<int, int> head = move.front();
		move.pop();

		for(int i = 0; i < 4; i++)
		{
			int next_x = head.first + dir_x[i];
			int next_y = head.second+ dir_y[i];

			if(0<=next_x && next_x<r && 0<=next_y && next_y <c 
			&& forest[next_x][next_y]!='X'//돌이 아니여야하고
			&& move_time[next_x][next_y] == -1//방문한적 없고
		    && (flood_time[next_x][next_y]== -1 || move_time[head.first][head.second] + 1 < flood_time[next_x][next_y])){ // 침수될리가 없거나(침수되는게없는거임), 시간 넉넉

		    	move_time[next_x][next_y] = move_time[head.first][head.second] +1;
		    	move.push(make_pair(next_x, next_y));

			}
		}
		    
	}
	if(move_time[end_x][end_y] == -1)
	{
		cout << "KAKTUS";
	}else{
		cout <<move_time[end_x][end_y];
	}
	

	return 0;
}
