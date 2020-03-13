#include <iostream>
#include <deque>
#include <cstring>
using namespace std;


int main()
{
	int N; //보드 크기
	scanf("%d", &N);

	int K; //사과갯수
	scanf("%d", &K);

	bool gamepan[N][N]; //사과가 있는지 없는지 
	memset(gamepan, 0, sizeof(gamepan));

	for(int k = 0; k < K; k++)
	{
		int ax, ay;
		scanf("%d %d", &ax, &ay);
		//cout << "apple: " << ax << ", " << ay << endl;
		gamepan[ax-1][ay-1] = true; //사과 놓자 
	}
	

	int L;
	scanf("%d", &L);



	int move[N*N];
	memset(move, 0, sizeof(move));
	for(int m = 0; m < L; m++)
	{
		int t;
		char rotate;
		cin >> t >> rotate;
		if(rotate == 'L')
			move[t] = -1;
		else
			move[t] = 1;
	}


	int dx[4] = {0, 1, 0, -1}; // 우, 아래, 왼, 위
	int dy[4] = {1, 0, -1, 0}; 

	deque<pair<int, int>> snake;
	snake.push_front(make_pair(0, 0));
	//snake direction
	int sd = 0; //맨 처음에 오른쪽을 향한다. 
	
	//1. 몸 길이를 늘려 머리를 다음칸에 위치시킨다.
	//2. 이동한 칸에 사과있다면, 사과 먹고 꼬리 움직이지 X
	//3.          사과없으면, 몸길이 줄여 꼬리가 위치한 칸 비워줌 -> 몸길이 변하지 X

	
	int time = 1;
	while(true)
	{

		// cout << "Snake : ";
		// for(int s = 0; s < snake.size(); s++)
		// 	cout << "(" << snake[s].first << ", " << snake[s].second << ") ";
		// cout << endl;

		pair<int, int> now = snake.front();

		int nx = now.first + dx[sd];
		int ny = now.second+ dy[sd];

		if(nx < 0 || nx >= N || ny < 0 || ny >= N) //벽이면 
			break;

		bool visit_me = false;
		for(int s = 0; s < snake.size(); s++)
		{
			if(nx == snake[s].first && ny == snake[s].second)//자기 몸이면
			{
				visit_me = true;
				break;
			}
		}
		if(visit_me == true) //자기몸에 부딫함
			break;
			
  	
  		//자기몸에 안부딫히고 벽에 안부딫히면 움직이자.
		snake.push_front(make_pair(nx, ny));

		if(gamepan[nx][ny] == true)//사과가 있으면
		{	
			gamepan[nx][ny] = false; //먹어서 없어짐

		}else //사과가 없으면 
		{
			snake.pop_back(); //몸길이를 못늘림
		}

		//X초 끝나고 방향바꾸기
		if(move[time] == 1) //오른쪽 
			sd = (sd + 1) % 4;
		else if(move[time] == -1)//왼쪽
			sd = (sd + 3) % 4;

		time += 1;

	}

	cout << time;

	
	return 0;
}