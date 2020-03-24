#include <iostream>
#include <cstring>
using namespace std;

int N, M;
char board[21][21];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int answer = 11;
void go(int x1, int y1, int x2, int y2, int time)
{
	if(time > 10)
		return; //횟수 넘으면 중지


	for(int d = 0; d < 4; d++)
	{

		int nx1 = x1 + dx[d];
		int ny1 = y1 + dy[d];
		int nx2 = x2 + dx[d];
		int ny2 = y2 + dy[d];
	
		bool is_1_fall = false;
		bool is_2_fall = false;

		if(nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= M)
			is_1_fall = true;
		if(nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= M)
			is_2_fall = true;


		if(is_1_fall == true && is_2_fall == true) //둘다 바닥으로 떨어지면 
			continue;

		if(is_1_fall == true || is_2_fall == true) //정답 찾으면 //다른방향 볼필요 X
		{
			if(answer > time)
				answer = time;
			return;
		}

		if(board[nx1][ny1] == '#'){
			nx1 = x1; 
			ny1 = y1;
		}
		if(board[nx2][ny2] == '#'){
			nx2 = x2;
			ny2 = y2;
		}

		go(nx1, ny1, nx2, ny2, time+1);



	} 


}


int main()
{
	
	scanf("%d %d", &N, &M);

	int c1_x, c1_y, c2_x, c2_y;
	c1_x = c1_y = c2_x = c2_y = -1;

	for(int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for(int j = 0; j < M; j++)
		{
			board[i][j] = tmp[j];
			if(board[i][j] == 'o')
			{
				if(c1_x == -1)
				{
					c1_x = i;
					c1_y = j;
				}
				else
				{
					c2_x = i;
					c2_y = j;
				}
			}
		}
	}
	go(c1_x, c1_y, c2_x, c2_y, 1);


	if(answer == 11)
		cout << "-1";
	else
		cout << answer;



	return 0;
}